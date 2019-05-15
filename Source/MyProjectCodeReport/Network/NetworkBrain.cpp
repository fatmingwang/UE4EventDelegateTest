// Fill out your copyright notice in the Description page of Project Settings.


#include "NetworkBrain.h"
#include "SocketTask.h"
#include "DelegateHandler.h"
#include "../Event/EventEnum.h"
UNetworkBrain::UNetworkBrain()
{
	m_pSocketTask = nullptr;
	m_pCREE_BP_TO_CPP_LOGIN_BUTTON_CLICK_LazyDelegate = nullptr;
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
	if (m_pCREE_BP_TO_CPP_LOGIN_BUTTON_CLICK_LazyDelegate)
		delete m_pCREE_BP_TO_CPP_LOGIN_BUTTON_CLICK_LazyDelegate;
	if (m_pSocketTask)
	{
		delete m_pSocketTask;
	}
}

void	UNetworkBrain::Init()
{
	if (!m_pCREE_BP_TO_CPP_LOGIN_BUTTON_CLICK_LazyDelegate)
	{
		int l_iValue = (int)eCodeReportEventEnum::eCREE_BP_TO_CPP_LOGIN_BUTTON_CLICK;
		//FMyLazyDelegate(uint32 e_iID, UObject*e_pObject, FName e_Name, int e_iBindingType);
		//m_pCREE_BP_TO_CPP_LOGIN_BUTTON_CLICK_LazyDelegate = new FMyLazyDelegate((int)eCodeReportEventEnum::eCREE_LOGIN_BUTTON_CLICK, this, "BPCallCPlusPlus", eBindingType::eBT_CPLUSPLUS_EVENT);
		m_pCREE_BP_TO_CPP_LOGIN_BUTTON_CLICK_LazyDelegate = new FMyLazyDelegate((int)eCodeReportEventEnum::eCREE_BP_TO_CPP_LOGIN_BUTTON_CLICK, this, "LoginWidgetLoginButtonClickEvent", eBindingType::eBT_CPLUSPLUS_EVENT);
	}
}

void	UNetworkBrain::LoginWidgetLoginButtonClickEvent(UEventDelegateData*e_Data)
{
	//FDelegateHandlerModule*	l_pDelegateHandlerModule = GetDelegateHandler();
	//if (l_pDelegateHandlerModule)
	//{
	//	char l_Test[260];
	//	sprintf(l_Test, "%s %d","ggyy",999);
	//	l_pDelegateHandlerModule->BPDelegateShoot(9, l_Test,sizeof(l_Test));
	//}
	ConnectToServer("10.168.1.143", TCP_IP_PORT);
}

void	UNetworkBrain::Update(float e_fElpaseTime)
{
	if (m_pSocketTask)
	{
		m_pSocketTask->Update(e_fElpaseTime);
		m_pSocketTask->DebugRender();
		TArray<UNetWorkMessageDelegateData*>l_UNetWorkMessageDelegateDataArray;
		m_pSocketTask->FetchNetworkMessage(l_UNetWorkMessageDelegateDataArray);
		if (GetDelegateHandler())
		{
			for (auto l_pData : l_UNetWorkMessageDelegateDataArray)
			{
				g_pDelegateHandlerModule->NetworkMessageShoot(l_pData);
			}
		}
	}
}

void	UNetworkBrain::ConnectToServer(FString e_strIP, int32 e_iPort)
{
	if (m_pSocketTask == nullptr)
	{
		m_pSocketTask = new SocketTask(e_strIP, e_iPort);
	}
}