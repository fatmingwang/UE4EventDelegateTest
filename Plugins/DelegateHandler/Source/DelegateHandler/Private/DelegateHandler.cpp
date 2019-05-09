// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "DelegateHandler.h"
#include "CommonFunction.h"
#define LOCTEXT_NAMESPACE "FEventHandlerModule"

// Sets default values for this component's properties
//void FDelegateHandlerModule::TestFunction()
//{
//
//}
FDelegateHandlerModule*g_pDelegateHandlerModule = nullptr;
FDelegateHandlerModule::FDelegateHandlerModule()
{
	g_pDelegateHandlerModule = this;
	//g_pMyMessageHanlder = this;
	//m_FTestDelegate.AddDynamic(this, &FDelegateHandlerModule::TestFunction)
	//l_FTestDelegate.
	//l_FTestDelegate.
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	//PrimaryComponentTick.bCanEverTick = true;

	// ...
	//m_FNetworkMessage.BindUObject()
//	m_FEventMessage;
	//m_FEventMessage.
}

FDelegateHandlerModule::~FDelegateHandlerModule()
{

}

void FDelegateHandlerModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FDelegateHandlerModule::ShutdownModule()
{
	DELETE_TMAP(m_IDAndFNetworkMessageMap);
	DELETE_TMAP(m_IDAndFEventMessageMap);
	DELETE_TARRAY(m_WaitProcessEventArray);
	DELETE_TARRAY(m_WaitProcessNetworkArray);	
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}


// Called when the game starts
//void FDelegateHandlerModule::BeginPlay()
//{
//	Super::BeginPlay();
//
//	// ...
//	
//}


// Called every frame
//void FDelegateHandlerModule::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//	// ...
//}

void FDelegateHandlerModule::EventShoot(uint32 e_iID, char * e_pData)
{
	UEventDelegateData*l_pUEventDelegateData = NewObject<UEventDelegateData>();
	l_pUEventDelegateData->SetData(e_iID, e_pData);
	m_WaitProcessEventArray.Add(l_pUEventDelegateData);
}

void FDelegateHandlerModule::EventShoot(uint32 e_iID, char * e_pData, int e_iDataSize)
{
	UEventDelegateData*l_pUEventDelegateData = NewObject<UEventDelegateData>();
	l_pUEventDelegateData->SetData(e_iID, e_pData, e_iDataSize);
	m_WaitProcessEventArray.Add(l_pUEventDelegateData);
}
//void FDelegateHandlerModule::NetworkMessageShoot(FSocket*pSocket, uint32	e_i32NetworkMessageID, char*e_pData, int e_iDataSize)
void	FDelegateHandlerModule::NetworkMessageShoot(UNetWorkMessageDelegateData*e_pUNetWorkMessageDelegateData)
{
	//UNetWorkMessageDelegateData*l_pUNetWorkMessageDelegateData = NewObject<UNetWorkMessageDelegateData>();
	//l_pUNetWorkMessageDelegateData->SetData(pSocket, e_pData, e_iDataSize);
	m_WaitProcessNetworkArray.Add(e_pUNetWorkMessageDelegateData);
}

void FDelegateHandlerModule::FireEventAndtNetworkMessage()
{
	int l_iNum = m_WaitProcessNetworkArray.Num();
	for(int i=0;i< l_iNum;++i)
	{
		UNetWorkMessageDelegateData*l_pNetWorkMessageDelegateData = m_WaitProcessNetworkArray[i];
		if (l_pNetWorkMessageDelegateData)
		{
			if (m_IDAndFNetworkMessageMap.Contains(l_pNetWorkMessageDelegateData->m_i32EventID))
			{
				auto l_pNetworkDelegate = m_IDAndFNetworkMessageMap[l_pNetWorkMessageDelegateData->m_i32EventID];
			}
			delete l_pNetWorkMessageDelegateData;
		}
	}
	m_WaitProcessNetworkArray.Empty();
	l_iNum = m_WaitProcessEventArray.Num();
	for (int i = 0; i < l_iNum; ++i)
	{
		UEventDelegateData*l_pUEventDelegateData = m_WaitProcessEventArray[i];
		if (l_pUEventDelegateData)
		{
			if (m_IDAndFEventMessageMap.Contains(l_pUEventDelegateData->i32EventID))
			{
				auto l_pEventDelegate = m_IDAndFEventMessageMap[l_pUEventDelegateData->i32EventID];
				//l_pEventDelegate->Call();
			}
			delete l_pUEventDelegateData;
		}
	}	
	m_WaitProcessEventArray.Empty();
}
//void FDelegateHandlerModule::RegisterEventForBP(uint32 e_iID, UObject * e_pObject, FName e_Name)
//{
//	TArray<FMyLazyDelegate*>& l_MyLazyDelegateArrayRef = m_UObjectAndFMyLazyDelegateMapForBPBindEvent[e_pObject];
//	FMyLazyDelegate*l_pFMyLazyDelegate = new FMyLazyDelegate(e_iID,e_pObject,e_Name, eBindingType::eBT_EVENT);
//	l_MyLazyDelegateArrayRef.Add(l_pFMyLazyDelegate);
//	//i
//}
//void FDelegateHandlerModule::RegisterNetworkMessageForBP(uint32 e_iID, UObject * e_pObject, FName e_Name)
//{
//	TArray<FMyLazyDelegate*>& l_MyLazyDelegateArrayRef = m_UObjectAndFMyLazyDelegateMapForBPBindEvent[e_pObject];
//	FMyLazyDelegate*l_pFMyLazyDelegate = new FMyLazyDelegate(e_iID, e_pObject, e_Name, eBindingType::eBT_NETWORK);
//	l_MyLazyDelegateArrayRef.Add(l_pFMyLazyDelegate);
//}
//void FDelegateHandlerModule::RemoveBindingBP(UObject * e_pObject)
//{
//	TArray<FMyLazyDelegate*>& l_MyLazyDelegateArrayRef = m_UObjectAndFMyLazyDelegateMapForBPBindEvent[e_pObject];
//	for (int i = 0; i < l_MyLazyDelegateArrayRef.Num(); ++i)
//	{
//		FMyLazyDelegate*l_pFMyLazyDelegate = l_MyLazyDelegateArrayRef[i];
//		if (l_pFMyLazyDelegate)
//			delete l_pFMyLazyDelegate;
//	}
//	l_MyLazyDelegateArrayRef.Empty();
//	m_UObjectAndFMyLazyDelegateMapForBPBindEvent.Remove(e_pObject);	
//}
//https://forums.unrealengine.com/development-discussion/c-gameplay-programming/33614-onactorhit-delegate-how-do-they-work
//
//FScriptDelegate Delegate;
//Delegate.BindUFunction(this, "OnActorBump");
//GetOwner()->OnActorHit.AddUnique(Delegate);
//
void FDelegateHandlerModule::RegisterEvent(FMyLazyDelegate*e_pFMyLazyDelegate)
{
	if (!m_IDAndFEventMessageMap.Contains(e_pFMyLazyDelegate->m_i32ID))
	{
		FEventMessage*l_pEventMessage = new FEventMessage();
		m_IDAndFEventMessageMap.Add(e_pFMyLazyDelegate->m_i32ID,l_pEventMessage);
	}
	auto l_FEventMessage = m_IDAndFEventMessageMap[e_pFMyLazyDelegate->m_i32ID];
	l_FEventMessage->Add(e_pFMyLazyDelegate->m_FScriptDelegate);
}
void FDelegateHandlerModule::RegisterNetworkMessage(FMyLazyDelegate*e_pFMyLazyDelegate)
{
	if (!m_IDAndFNetworkMessageMap.Contains(e_pFMyLazyDelegate->m_i32ID))
	{
		FNetworkMessage*l_pNetworkMessage = new FNetworkMessage();
		m_IDAndFNetworkMessageMap.Add(e_pFMyLazyDelegate->m_i32ID,l_pNetworkMessage);
	}
	auto l_FNetworkMessage = m_IDAndFNetworkMessageMap[e_pFMyLazyDelegate->m_i32ID];
	l_FNetworkMessage->Add(e_pFMyLazyDelegate->m_FScriptDelegate);
}

void FDelegateHandlerModule::RemoveEvent(FMyLazyDelegate*e_pFMyLazyDelegate)
{
	if (!m_IDAndFNetworkMessageMap.Contains(e_pFMyLazyDelegate->m_i32ID))
	{
		FNetworkMessage*l_pNetworkMessage = new FNetworkMessage();
		m_IDAndFNetworkMessageMap.Add(e_pFMyLazyDelegate->m_i32ID,l_pNetworkMessage);
	}
	auto l_FEventMessage = m_IDAndFEventMessageMap[e_pFMyLazyDelegate->m_i32ID];
	l_FEventMessage->Remove(e_pFMyLazyDelegate->m_FScriptDelegate);
}

void FDelegateHandlerModule::RemoveNetworkMessage(FMyLazyDelegate*e_pFMyLazyDelegate)
{
	auto l_FNetworkMessage = m_IDAndFNetworkMessageMap[e_pFMyLazyDelegate->m_i32ID];
	if (!l_FNetworkMessage)
		return;
	l_FNetworkMessage->Remove(e_pFMyLazyDelegate->m_FScriptDelegate);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FDelegateHandlerModule, DelegateHandler)