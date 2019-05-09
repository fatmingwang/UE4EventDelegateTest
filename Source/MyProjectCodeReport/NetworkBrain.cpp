// Fill out your copyright notice in the Description page of Project Settings.


#include "NetworkBrain.h"
#include "SocketTask.h"
#include "DelegateHandler.h"
NetworkBrain::NetworkBrain()
{
	m_pSocketTask = nullptr;
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

NetworkBrain::~NetworkBrain()
{
	if (m_pSocketTask)
	{
		delete m_pSocketTask;
	}
}

void	NetworkBrain::Update(float e_fElpaseTime)
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
void	NetworkBrain::ConnectToServer(FString e_strIP, int32 e_iPort)
{
	if (m_pSocketTask == nullptr)
	{
		m_pSocketTask = new SocketTask(e_strIP, e_iPort);
	}
}