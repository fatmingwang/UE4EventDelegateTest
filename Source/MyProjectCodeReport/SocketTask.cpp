// Fill out your copyright notice in the Description page of Project Settings.

#include "SocketTask.h"
#include "CommonDefine.h"
//FM79979 Core\Network\GameNetWork.h
struct	sNetworkSendPacket
{
	int		iSize;
	char*	pData;
	sNetworkSendPacket() { pData = nullptr; iSize = 0; }
	~sNetworkSendPacket()
	{
		if (pData)
			delete[] pData;
	}
};

SocketTask::SocketTask(const FString& InAddress, int32 InPort)
{
	Address = InAddress;
	Port = InPort;
	TryConnect();
}

SocketTask::~SocketTask()
{
	delete Socket;
	Socket = nullptr;

	delete RunnableThread;
	RunnableThread = nullptr;

	for (int i = 0; i < m_UNetWorkMessageDataArray.Num(); ++i)
	{
		UNetWorkMessageData*l_pData = m_UNetWorkMessageDataArray[i];
		if(l_pData)
			delete l_pData;
	}
	m_UNetWorkMessageDataArray.Empty();
}

void	SocketTask::TryConnect()
{
	m_fReconnectTime = m_cfReConnectTime;
	m_eConnectionStatus = eCS_TRY_TO_CONNECT;

	Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, Address, false);

	FIPv4Address ip;
	FIPv4Address::Parse(Address, ip);

	InternetAddress = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	InternetAddress->SetIp(ip.Value);
	InternetAddress->SetPort(Port);

	RunnableThread = FRunnableThread::Create(this, TEXT("ControllerDeviceTask"), 0, TPri_BelowNormal);
}

bool SocketTask::Init()
{
	return true;
}

uint32 SocketTask::Run()
{
	if (Socket != nullptr)
	{
		char l_NetworkDataTemp[65535];
		m_eConnectionStatus = eCS_TRY_TO_CONNECT;
		if (Socket->Connect(*InternetAddress) == false)
		{
			goto DISCONNECTED;
			//GEngineAddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("Socket->Connect failed")));
			//m_eConnectionStatus = eCS_CONNECTION_FAILED;
			//return 1;
		}
		m_eConnectionStatus = eCS_CONNECTED;
		GEngineAddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("SocketStatus:%d"), Socket->GetConnectionState()));
		// Continue updating the device while possible...
		while (Socket != nullptr && Socket->GetConnectionState() == ESocketConnectionState::SCS_Connected)
		{
			//reference sNetworkSendPacket.
			//first fetch first 4 byte for data size
			int32 l_iPacketSize = sizeof(int);
			int32 l_iPacketSizeReaded = 0;
			int32 l_iPacketSizeStore = 0;
			if (Socket->Recv((uint8*)&l_iPacketSizeStore, sizeof(int), l_iPacketSizeReaded))
			{
				int32 l_i32BytesRead = 0;
				//second read packet data.
				if (Socket->Recv((uint8*)l_NetworkDataTemp, l_iPacketSizeStore, l_i32BytesRead))
				{
					if (l_iPacketSizeStore == l_i32BytesRead)
					{
						m_mutex.Lock();
						//UNetWorkMessageData*l_pNetWorkMessageDataStruct = new UNetWorkMessageData(Socket, l_NetworkDataTemp, l_iPacketSizeStore);
						UNetWorkMessageData*l_pNetWorkMessageDataStruct = nullptr;
						m_UNetWorkMessageDataArray.Add(l_pNetWorkMessageDataStruct);
						m_mutex.Unlock();
						//GEngineAddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("data  received:%d"), BytesRead));
					}
				}
				else
				{
					goto DISCONNECTED;
				}
			}
			else
			{
				goto DISCONNECTED;
			}
			FPlatformProcess::Sleep(0.32f);
		}
	}
DISCONNECTED:
	Socket->Close();
	m_eConnectionStatus = eCS_CONNECTION_FAILED;
	GEngineAddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("SocketClosed")));
	return 0;
}

void SocketTask::Stop()
{
	// This will make the socket connection state different then SCS_Connected and
	// It will break the while loop in Run method.
	if (Socket)
		Socket->Close();
}

void	SocketTask::Update(float e_fElpaseTime)
{
	if (m_eConnectionStatus == eCS_CONNECTION_FAILED)
	{
		m_fReconnectTime -= e_fElpaseTime;
		if (m_fReconnectTime <= 0.f)
		{
			TryConnect();
		}
	}
}

void	SocketTask::SendData(int e_iPacketSize, char*e_pData)
{
	//uint8 Request[] = { 250, 3, 3 };
	struct sDataTest
	{
		int iSize = 44;//3 char
		int iMessageID = 0;
		char strUserName[20] = { 'A','B','C','D',0 };
		char strPWD[20] = { 'A','B','C','D',0 };
	};
	sDataTest l_pDataToSend;
	int32 sent = 0;
	//if (Socket->Send((uint8*)&l_pDataToSend, sizeof(l_pDataToSend), sent))
	if (Socket->Send((uint8*)e_pData, e_iPacketSize, sent))
	{
	}
	else
	{
		GEngineAddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("send data failed")));
	}
}

void SocketTask::DebugRender()
{
	FString l_str = "";
	switch (m_eConnectionStatus)
	{
	case eCS_NONE:
		l_str = "None";
		break;
	case eCS_TRY_TO_CONNECT:
		l_str = "try to connect";
		break;
	case eCS_CONNECTED:
		l_str = "connected";
		break;
	case eCS_CONNECTION_FAILED:
		l_str = "connection failed";
		break;
	default:
		l_str = "???";
		break;
	}
	GEngineAddOnScreenDebugMessage(0,0, FColor::Red, l_str);
}

bool	SocketTask::FetchNetworkMessage(TArray<UNetWorkMessageData*>&e_UNetWorkMessageDataArray)
{
	m_mutex.Lock();
	int32 l_i32Num = m_UNetWorkMessageDataArray.Num();
	for (int i = 0; i < l_i32Num; ++i)
	{
		auto l_pData = m_UNetWorkMessageDataArray[i];
		e_UNetWorkMessageDataArray.Add(l_pData);
	}
	e_UNetWorkMessageDataArray;
	m_mutex.Unlock();
	if (e_UNetWorkMessageDataArray.Num() > 0)
		return true;
	return false;
}

//void SocketTask::ProcessSocketMessage(char*e_pData)
//{
//	// Your code here...
//}