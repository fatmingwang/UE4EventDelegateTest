// Fill out your copyright notice in the Description page of Project Settings.

#include "SocketTask.h"
#include "CommonDefine.h"
#include "DelegateHandler.h"
#include "../Event/EventEnum.h"
#include "../../../ExternalScource_NetworkProtocal/NetworkMessage.h"
SocketTask::SocketTask(const FString& InAddress, int32 InPort)
{
	m_bThreadWasExit = true;
	m_bLeaveThread = false;
	Address = InAddress;
	Port = InPort;
	TryConnect();
}

SocketTask::~SocketTask()
{
	m_bLeaveThread = true;
	FPlatformProcess::Sleep(0.1f);
	//while (!m_bThreadWasExit)
	//{

	//}
	delete Socket;
	Socket = nullptr;
	delete RunnableThread;
	RunnableThread = nullptr;
	DELETE_VECTOR(m_NetworkReceivedPacketVector);
}

void	SocketTask::TryConnect()
{
	m_fReconnectTime = m_cfReConnectTime;
	NetworkConnectionStatusChange(eCS_TRY_TO_CONNECT);

	Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, Address, false);

	FIPv4Address ip;
	FIPv4Address::Parse(Address, ip);

	InternetAddress = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	InternetAddress->SetIp(ip.Value);
	InternetAddress->SetPort(Port);

	RunnableThread = FRunnableThread::Create(this, TEXT("ControllerDeviceTask"), 0, TPri_BelowNormal);
}

void	SocketTask::NetworkConnectionStatusChange(eConnectionStatus e_eConnectionStatus)
{
	if (m_eConnectionStatus != e_eConnectionStatus)
	{
		FDelegateHandlerModule*l_pDelegateHandlerModule = GetDelegateHandler();
		if (l_pDelegateHandlerModule)
		{
			m_eConnectionStatus = e_eConnectionStatus;
			int l_iStatus = (int)m_eConnectionStatus;
			l_pDelegateHandlerModule->DelegateShoot((int32)eCodeReportEventEnum::eCREE_NETWORK_STATUS_CHANGE,(char*)&l_iStatus,sizeof(int));
		}
	}
}

bool SocketTask::Init()
{
	return true;
}

uint32 SocketTask::Run()
{
	m_bThreadWasExit = false;
	if (Socket != nullptr && !m_bLeaveThread)
	{
		NetworkConnectionStatusChange(eCS_TRY_TO_CONNECT);
		if (Socket->Connect(*InternetAddress) == false)
		{
			goto DISCONNECTED;
			//GEngineAddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("Socket->Connect failed")));
			//m_eConnectionStatus = eCS_CONNECTION_FAILED;
			//return 1;
		}
		NetworkConnectionStatusChange(eCS_CONNECTED);
		GEngineAddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("SocketStatus:%d"), Socket->GetConnectionState()));
		// Continue updating the device while possible...
		while (Socket != nullptr && Socket->GetConnectionState() == ESocketConnectionState::SCS_Connected && !m_bLeaveThread)
		{
			if (1)
			{
				sNetworkReceivedPacket*l_pPacket = new sNetworkReceivedPacket();
				int l_iReceivedSize = l_pPacket->ReceiveData(Socket);
				if (l_iReceivedSize <= 0)
				{//wrong data ignore it
					bool	l_bConnectionFailed = false;
					delete l_pPacket;
					goto DISCONNECTED;
				}
				else
				{
					m_mutex.Lock();
					this->m_NetworkReceivedPacketVector.push_back(l_pPacket);
					m_mutex.Unlock();
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
	if(Socket)
		Socket->Close();
	NetworkConnectionStatusChange(eCS_CONNECTION_FAILED);
	GEngineAddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("SocketClosed")));
	m_bThreadWasExit = true;
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
	//TArray<UNetWorkMessageDelegateData*>l_UNetWorkMessageDelegateDataArray;
	//FetchNetworkMessage(l_UNetWorkMessageDelegateDataArray);
	//FDelegateHandlerModule*l_pDelegateHandlerModule = GetDelegateHandler();
}

void	SocketTask::SendData(int e_iPacketSize, char*e_pData)
{

	//char l_tt[6] = {6,1,2,3,4,5};

	int	l_iSendSize = (int)(sizeof(int) + e_iPacketSize);
	unsigned char*l_pData = new unsigned char[l_iSendSize];
	memcpy(l_pData, &e_iPacketSize, sizeof(int));
	memcpy(&l_pData[sizeof(int)], e_pData, e_iPacketSize);
	sLoginMessage_eNM_C2S_LOGIN_REQUEST*l_psLoginMessage_eNM_C2S_LOGIN_REQUEST = (sLoginMessage_eNM_C2S_LOGIN_REQUEST*)&l_pData[sizeof(int)];
	int32 sent = 0;
	if (Socket->Send((uint8*)l_pData, l_iSendSize, sent))
	//if (Socket->Send((uint8*)&l_tt,l_tt[0], sent))
	{
	}
	else
	{
		GEngineAddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("send data failed")));
	}
	delete[] l_pData;
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

bool	SocketTask::FetchNetworkMessage(std::vector<sNetworkReceivedPacket*>&e_NetworkReceivedPacketVector)
{
	m_mutex.Lock();
	for (auto l_pData: m_NetworkReceivedPacketVector)
	{
		e_NetworkReceivedPacketVector.push_back(l_pData);
	}
	m_NetworkReceivedPacketVector.clear();
	m_mutex.Unlock();
	if (e_NetworkReceivedPacketVector.size() > 0)
		return true;
	return false;
}

//void SocketTask::ProcessSocketMessage(char*e_pData)
//{
//	// Your code here...
//}