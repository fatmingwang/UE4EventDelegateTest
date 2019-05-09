// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "NetworkBrain.h"
//#include "DelegateHanlder.h"

UMyGameInstance::UMyGameInstance()
{
	//m_pNetworkBrain = nullptr;
	m_pNetworkBrain = new NetworkBrain;
	//m_pUMessageHanlder = nullptr;
}

UMyGameInstance::~UMyGameInstance()
{
	if (m_pNetworkBrain)
	{
		delete m_pNetworkBrain;
		m_pNetworkBrain = nullptr;
	}
	//if (m_pUMessageHanlder)
		//delete m_pUMessageHanlder;
}

bool UMyGameInstance::Tick(float DeltaSeconds)
{
	if (m_pNetworkBrain)
	{
		m_pNetworkBrain->Update(DeltaSeconds);
	}
	if (GetDelegateHandler())
	{
		g_pDelegateHandlerModule->FireEventAndtNetworkMessage();
	}

	return true;
}

void UMyGameInstance::Init()
{
	// Register delegate for ticker callback
	m_TickDelegateHandle = FTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UMyGameInstance::Tick));
	/*if (m_pUMessageHanlder)
	{
		delete m_pUMessageHanlder;
		m_pUMessageHanlder = nullptr;
	}
	if(!m_pUMessageHanlder)
		m_pUMessageHanlder = new FDelegateHanlder();*/
	Super::Init();
}

void UMyGameInstance::Shutdown()
{
	// Unregister ticker delegate
	FTicker::GetCoreTicker().RemoveTicker(m_TickDelegateHandle);

	Super::Shutdown();
}

void UMyGameInstance::ConnectToServer(FString e_strIP, int e_iPort)
{
	if (this->m_pNetworkBrain)
	{
		m_pNetworkBrain->ConnectToServer(e_strIP,e_iPort);
	}
}