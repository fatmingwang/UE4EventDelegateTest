// Fill out your copyright notice in the Description page of Project Settings.


#include "NetworkBrain.h"
#include "SocketTask.h"
#include "DelegateHandler.h"
#include "../Event/EventEnum.h"
#include "NetworkMessageEnum.h"
#include "../../../ExternalScource_NetworkProtocal/NetworkMessage.h"
#include "../User/User.h"
#include <string>
UNetworkBrain::UNetworkBrain()
{
	m_pUser = new sUser();
	m_pSocketTask = nullptr;
	m_pCREE_BP_TO_CPP_LOGIN_BUTTON_CLICK_LazyDelegate = nullptr;
	m_pNetworkStatusChangedDelegate = nullptr;
	m_pLoginResult_eNM_S2C_LOGIN_RESULT_NETWORK_MESSAGE = nullptr;
	//AMyGameGameMode* gameMode = (AMyGameGameMode*)GetWorld()->GetAuthGameMode();
	//if (gameMode)
	//{
	//	UMyGameGameInstance* gameInstance = Cast<UMyGameGameInstance>(gameMode->GetGameInstance());
	//	if (gameInstance)
	//	{
	//		do stuff
	//	}
	//}
}

UNetworkBrain::~UNetworkBrain()
{
	SAFE_DELETE(m_pUser);
	SAFE_DELETE(m_pNetworkStatusChangedDelegate);
	SAFE_DELETE(m_pCREE_BP_TO_CPP_LOGIN_BUTTON_CLICK_LazyDelegate);
	SAFE_DELETE(m_pSocketTask);
	SAFE_DELETE(m_pLoginResult_eNM_S2C_LOGIN_RESULT_NETWORK_MESSAGE);
}

void	UNetworkBrain::Init()
{
	if (!m_pCREE_BP_TO_CPP_LOGIN_BUTTON_CLICK_LazyDelegate)
	{
		uint32 l_ui32Value = (uint32)eCodeReportEventEnum::eCREE_BP_TO_CPP_LOGIN_BUTTON_CLICK;
		m_pCREE_BP_TO_CPP_LOGIN_BUTTON_CLICK_LazyDelegate = new FMyLazyDelegate(l_ui32Value, this, "LoginWidgetLoginButtonClickEvent", eBindingType::eBT_CPLUSPLUS_EVENT);
		l_ui32Value = (uint32)eCodeReportEventEnum::eCREE_NETWORK_STATUS_CHANGE;
		m_pNetworkStatusChangedDelegate = new FMyLazyDelegate(l_ui32Value, this, "NetworkStatusChangeEvent", eBindingType::eBT_CPLUSPLUS_EVENT);
		l_ui32Value = (uint32)eNM_S2C_LOGIN_RESULT;
		m_pLoginResult_eNM_S2C_LOGIN_RESULT_NETWORK_MESSAGE = new FMyLazyDelegate(l_ui32Value, this, "LoginResultNetworkMessage", eBindingType::eBT_NETWORK_MESSAGE);
	}
}

void	UNetworkBrain::LoginWidgetLoginButtonClickEvent(UEventDelegateData*e_Data)
{
	FDelegateHandlerModule*	l_pDelegateHandlerModule = GetDelegateHandler();
	if (l_pDelegateHandlerModule)
	{
		std::string l_strCommand = e_Data->Data;
		std::vector<std::string>l_strArguments = GetCommandString(l_strCommand);
		if (l_strArguments.size() == 2)
		{
			if (m_pUser)
			{
				sprintf(m_pUser->m_strID, "%s", l_strArguments[0].c_str());
				sprintf(m_pUser->m_strPWD, "%s", l_strArguments[1].c_str());
				ConnectToServer("10.168.1.143", TCP_IP_PORT);
				//ConnectToServer("118.163.195.201", TCP_IP_PORT);
				return;
			}
		}
	}
	FString l_str = FString::Printf(TEXT("%d"), (int)eR_PWD_ERROR);
	UMyLazyBPDelegateShoot::DelegateShootWithCommand((int32)eCodeReportEventEnum::eCREE_CPP_TO_BP_LOGIN_RESULT, l_str, eBindingType::eBT_BP_EVENT);
}

void	UNetworkBrain::NetworkStatusChangeEvent(UEventDelegateData*e_Data)
{
	int*l_piConnectionResult = (int*)e_Data->Data;
	if (*l_piConnectionResult == (int)SocketTask::eConnectionStatus::eCS_CONNECTED)
	{
		if (m_pSocketTask)
		{
			sLoginMessage_eNM_C2S_LOGIN_REQUEST	l_sLoginMessage_eNM_C2S_LOGIN_REQUEST;
			l_sLoginMessage_eNM_C2S_LOGIN_REQUEST.fVersion = NETWORK_MESSAGE_VERSION;
			memcpy(l_sLoginMessage_eNM_C2S_LOGIN_REQUEST.strID, m_pUser->m_strID, sizeof(m_pUser->m_strID));
			memcpy(l_sLoginMessage_eNM_C2S_LOGIN_REQUEST.strPwd, m_pUser->m_strPWD, sizeof(m_pUser->m_strPWD));
			m_pSocketTask->SendData(l_sLoginMessage_eNM_C2S_LOGIN_REQUEST.iSize,(char*)&l_sLoginMessage_eNM_C2S_LOGIN_REQUEST);
		}
	}
	else
	if (*l_piConnectionResult == (int)SocketTask::eConnectionStatus::eCS_CONNECTION_FAILED)
	{
		m_pUser->m_bLogined = false;
	}
}

void UNetworkBrain::LoginResultNetworkMessage(UNetWorkMessageDelegateData*e_Data)
{
	if (!m_pUser)
		return;
	sLoginResultMessage_eNM_S2C_LOGIN_RESULT*l_pLoginResultMessage_eNM_S2C_LOGIN_RESULT = (sLoginResultMessage_eNM_S2C_LOGIN_RESULT*)e_Data->m_pData;
	if(l_pLoginResultMessage_eNM_S2C_LOGIN_RESULT->iResultCode == eR_LOGIN_OK)
	{ 
		m_pUser->m_OwnMachineVector.clear();
		//m_pUser->m_OwnMachineVector = std::vector<int>();
		int l_iNumMachine = 200;
		for (int i = 0; i < MAX_MACHINE_COUNT; ++i)
		{
			if (l_pLoginResultMessage_eNM_S2C_LOGIN_RESULT->iMachineIDArray[i] != 0)
			{
				m_pUser->m_OwnMachineVector.push_back(l_pLoginResultMessage_eNM_S2C_LOGIN_RESULT->iMachineIDArray[i]);
			}
		}
		m_pUser->m_eUserAuthority = (eUserAuthority)l_pLoginResultMessage_eNM_S2C_LOGIN_RESULT->iUserAuthority;
		m_pUser->m_bLogined = true;

	}
	FString l_str = FString::Printf(TEXT("%d"), l_pLoginResultMessage_eNM_S2C_LOGIN_RESULT->iResultCode);
	UMyLazyBPDelegateShoot::DelegateShootWithCommand((int32)eCodeReportEventEnum::eCREE_CPP_TO_BP_LOGIN_RESULT, l_str, eBindingType::eBT_BP_EVENT);
}

void	UNetworkBrain::Update(float e_fElpaseTime)
{
	if (m_pSocketTask)
	{
		m_pSocketTask->Update(e_fElpaseTime);
		m_pSocketTask->DebugRender();
		std::vector<sNetworkReceivedPacket*>l_NetworkReceivedPacketVector;
		m_pSocketTask->FetchNetworkMessage(l_NetworkReceivedPacketVector);
		if (GetDelegateHandler())
		{
			for (auto l_pData : l_NetworkReceivedPacketVector)
			{
				UNetWorkMessageDelegateData *l_pUNetWorkMessageDelegateData = NewObject<UNetWorkMessageDelegateData>();
				l_pUNetWorkMessageDelegateData->SetData(l_pData);
				g_pDelegateHandlerModule->NetworkMessageShoot(l_pUNetWorkMessageDelegateData);
			}
		}
		DELETE_VECTOR(l_NetworkReceivedPacketVector);
	}
}

void	UNetworkBrain::ConnectToServer(FString e_strIP, int32 e_iPort)
{
	if (m_pSocketTask == nullptr)
	{
		m_pSocketTask = new SocketTask(e_strIP, e_iPort);
	}
	else
	{
		sLoginMessage_eNM_C2S_LOGIN_REQUEST	l_sLoginMessage_eNM_C2S_LOGIN_REQUEST;
		l_sLoginMessage_eNM_C2S_LOGIN_REQUEST.fVersion = NETWORK_MESSAGE_VERSION;
		memcpy(l_sLoginMessage_eNM_C2S_LOGIN_REQUEST.strID, m_pUser->m_strID, sizeof(m_pUser->m_strID));
		memcpy(l_sLoginMessage_eNM_C2S_LOGIN_REQUEST.strPwd, m_pUser->m_strPWD, sizeof(m_pUser->m_strPWD));
		m_pSocketTask->SendData(l_sLoginMessage_eNM_C2S_LOGIN_REQUEST.iSize, (char*)&l_sLoginMessage_eNM_C2S_LOGIN_REQUEST);
	}
}