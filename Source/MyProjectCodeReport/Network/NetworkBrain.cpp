// Fill out your copyright notice in the Description page of Project Settings.


#include "NetworkBrain.h"
#include "SocketTask.h"
#include "DelegateHandler.h"
#include "../Event/EventEnum.h"
UNetworkBrain::UNetworkBrain()
{
	m_pSocketTask = nullptr;
	m_pFMyLazyDelegate = nullptr;
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
	if (m_pFMyLazyDelegate)
		delete m_pFMyLazyDelegate;
	if (m_pSocketTask)
	{
		delete m_pSocketTask;
	}
}

void	UNetworkBrain::Init()
{
	if (!m_pFMyLazyDelegate)
	{
		int l_iValue = (int)eCodeReportEventEnum::eCREE_LOGIN_BUTTON_CLICK;
		//FMyLazyDelegate(uint32 e_iID, UObject*e_pObject, FName e_Name, int e_iBindingType);
		m_pFMyLazyDelegate = new FMyLazyDelegate((int)eCodeReportEventEnum::eCREE_LOGIN_BUTTON_CLICK, this, "BPCallCPlusPlus", eBindingType::eBT_EVENT);
	}
}

void	UNetworkBrain::BPCallCPlusPlus(UEventDelegateData*e_Data)
{
	int a = 0;
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