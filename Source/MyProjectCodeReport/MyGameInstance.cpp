// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "MyMessageHanlder.h"

UMyGameInstance::UMyGameInstance()
{
	m_pUMessageHanlder = nullptr;
}

UMyGameInstance::~UMyGameInstance()
{
	if (m_pUMessageHanlder)
		delete m_pUMessageHanlder;
}

bool UMyGameInstance::Tick(float DeltaSeconds)
{
	return true;
}

//void UMyGameInstance::RegisterEvent(uint32 e_iID, UObject * e_pObject, FName e_Name)
//{
//	//void							RegisterEventForBP(uint32 e_iID, UObject*e_pObject, FName e_Name);
//	//void							RegisterNetworkMessageForBP(uint32 e_iID, UObject*e_pObject, FName e_Name);
//	//void							RemoveBindingBP(UObject*e_pObject);
//	//	if (m_pUMessageHanlder)
//	//		m_pUMessageHanlder->RemoveEvent(e_iEventID, e_FScriptDelegate);
//}
//
//void UMyGameInstance::RegisterNetworkMessage(uint32 e_iID, UObject * e_pObject, FName e_Name)
//{
//}
//
//void UMyGameInstance::RegisterEvent(int32 e_iEventID, FScriptDelegate & e_FScriptDelegate)
//{
//	if (m_pUMessageHanlder)
//		m_pUMessageHanlder->RegisterEvent(e_iEventID, e_FScriptDelegate);
//}
//
//void UMyGameInstance::RegisterNetworkMessage(int32 e_iEventID, FScriptDelegate & e_FScriptDelegate)
//{
//	if (m_pUMessageHanlder)
//		m_pUMessageHanlder->RegisterNetworkMessage(e_iEventID, e_FScriptDelegate);
//}
//
//void UMyGameInstance::RemoveEvent(int32 e_iEventID, FScriptDelegate & e_FScriptDelegate)
//{
//	if (m_pUMessageHanlder)
//		m_pUMessageHanlder->RemoveEvent(e_iEventID, e_FScriptDelegate);
//}
//
//void UMyGameInstance::RemoveNetworkMessage(int32 e_iEventID, FScriptDelegate & e_FScriptDelegate)
//{
//	if (m_pUMessageHanlder)
//		m_pUMessageHanlder->RemoveNetworkMessage(e_iEventID, e_FScriptDelegate);
//}
//
void UMyGameInstance::Init()
{
	// Register delegate for ticker callback
	m_TickDelegateHandle = FTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UMyGameInstance::Tick));
	if (m_pUMessageHanlder)
	{
		delete m_pUMessageHanlder;
		m_pUMessageHanlder = nullptr;
	}
	if(!m_pUMessageHanlder)
		m_pUMessageHanlder = new FMyMessageHanlder();
	Super::Init();
}

void UMyGameInstance::Shutdown()
{
	// Unregister ticker delegate
	FTicker::GetCoreTicker().RemoveTicker(m_TickDelegateHandle);

	Super::Shutdown();
}