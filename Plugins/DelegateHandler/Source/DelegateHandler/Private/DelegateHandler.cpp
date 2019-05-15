// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "DelegateHandler.h"
#include "CommonFunction.h"
#include "..\Public\DelegateHandler.h"
#define LOCTEXT_NAMESPACE "FEventHandlerModule"

// Sets default values for this component's properties
//void FDelegateHandlerModule::TestFunction()
//{
//
//}
FDelegateHandlerModule*g_pDelegateHandlerModule = nullptr;
FDelegateHandlerModule*	GetDelegateHandler()
{
	if (!g_pDelegateHandlerModule)
	{
		UE_LOG(FDelegateHandlerModuleLogName, Error, TEXT("FDelegateHandlerModuleName is not enable or FDelegateHandlerModuleName::StartupModule is not called!"));
	}
	return g_pDelegateHandlerModule;
}
FDelegateHandlerModule::FDelegateHandlerModule()
{
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
	DELETE_VECTOR(m_WaitForEmitEventVector);
	DELETE_MAP(m_IDBPEventBindingDataVectorMap);
}

void FDelegateHandlerModule::StartupModule()
{
	g_pDelegateHandlerModule = this;
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FDelegateHandlerModule::ShutdownModule()
{
	g_pDelegateHandlerModule = nullptr;
	DELETE_TMAP(m_IDAndFNetworkMessageMap);
	DELETE_TMAP(m_IDAndFEventMessageMap);
	DELETE_VECTOR(m_WaitForEmitEventVector);
	//DELETE_TARRAY(m_WaitProcessNetworkArray);	
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

void FDelegateHandlerModule::DelegateShoot(int32 e_iID, char * e_pData)
{
	sWaitEmitEvent*l_pWaitEmitEvent = new sWaitEmitEvent();
	l_pWaitEmitEvent->pData = e_pData;
	l_pWaitEmitEvent->i32ID = e_iID;
	l_pWaitEmitEvent->bBPEvent = false;
	m_EventMutex.Lock();
	m_WaitForEmitEventVector.push_back(l_pWaitEmitEvent);
	m_EventMutex.Unlock();
}

void FDelegateHandlerModule::DelegateShoot(int32 e_iID, char * e_pData, int e_iDataSize)
{
	sWaitEmitEvent*l_pWaitEmitEvent = new sWaitEmitEvent();
	l_pWaitEmitEvent->i32ID = e_iID;
	l_pWaitEmitEvent->bBPEvent = false;
	memcpy(l_pWaitEmitEvent->cData, e_pData, e_iDataSize);
	m_EventMutex.Lock();
	m_WaitForEmitEventVector.push_back(l_pWaitEmitEvent);
	m_EventMutex.Unlock();
}

void	FDelegateHandlerModule::BPDelegateShoot(int32 e_iID, char*e_pData, int e_iDataSize)
{

	sWaitEmitEvent*l_pWaitEmitEvent = new sWaitEmitEvent();
	l_pWaitEmitEvent->i32ID = e_iID;
	l_pWaitEmitEvent->bBPEvent = true;
	if (e_iDataSize)
	{
		if(e_pData)
			memcpy(l_pWaitEmitEvent->cData, e_pData, e_iDataSize);
		else
			UE_LOG(FDelegateHandlerModuleLogName, Error, TEXT("BPDelegateShoot input e_pData is nullptr!?"));
	}	
	m_EventMutex.Lock();
	m_WaitForEmitEventVector.push_back(l_pWaitEmitEvent);
	m_EventMutex.Unlock();
}

//void FDelegateHandlerModule::NetworkMessageShoot(FSocket*pSocket, uint32	e_i32NetworkMessageID, char*e_pData, int e_iDataSize)
void	FDelegateHandlerModule::NetworkMessageShoot(UNetWorkMessageDelegateData*e_pUNetWorkMessageDelegateData)
{
	//UNetWorkMessageDelegateData*l_pUNetWorkMessageDelegateData = NewObject<UNetWorkMessageDelegateData>();
	//l_pUNetWorkMessageDelegateData->SetData(pSocket, e_pData, e_iDataSize);
	//m_WaitProcessNetworkArray.Add(e_pUNetWorkMessageDelegateData);
}

void FDelegateHandlerModule::FireEventAndtNetworkMessage()
{
	int l_iNum = 0;
	//int l_iNum = m_WaitProcessNetworkArray.Num();
	//for(int i=0;i< l_iNum;++i)
	//{
	//	UNetWorkMessageDelegateData*l_pNetWorkMessageDelegateData = m_WaitProcessNetworkArray[i];
	//	if (l_pNetWorkMessageDelegateData)
	//	{
	//		if (m_IDAndFNetworkMessageMap.Contains(l_pNetWorkMessageDelegateData->m_i32EventID))
	//		{
	//			auto l_pNetworkDelegate = m_IDAndFNetworkMessageMap[l_pNetWorkMessageDelegateData->m_i32EventID];
	//		}
	//		delete l_pNetWorkMessageDelegateData;
	//	}
	//}
	//m_WaitProcessNetworkArray.Empty();
	std::vector<sWaitEmitEvent*> l_WaitForEmitEventVector;
	{
		m_EventMutex.Lock();
		l_WaitForEmitEventVector = m_WaitForEmitEventVector;
		m_WaitForEmitEventVector.clear();
		m_EventMutex.Unlock();
		l_iNum = (int)l_WaitForEmitEventVector.size();
	}
	for (int i = 0; i < l_iNum; ++i)
	{
		sWaitEmitEvent*l_pWaitEmitEvent = l_WaitForEmitEventVector[i];
		if (l_pWaitEmitEvent)
		{
			if (l_pWaitEmitEvent->bBPEvent)
			{
				auto l_Iterator = m_IDBPEventBindingDataVectorMap.find(l_pWaitEmitEvent->i32ID);
				if (l_Iterator != m_IDBPEventBindingDataVectorMap.end())
				{
					auto l_pBPEventBindingDataVector = l_Iterator->second;
					for (auto l_pData : *l_pBPEventBindingDataVector)
					{
						FString l_strCommand(l_pWaitEmitEvent->cData);
						FString l_strFunctionNameAndCommand = FString::Printf
						(
							//TEXT("%s"),
							TEXT("%s %s"),
							*l_pData->FunctionName.ToString(),
							*l_strCommand
						);
						const TCHAR*l_strResult = *l_strFunctionNameAndCommand;
						l_pData->pObject->CallFunctionByNameWithArguments(l_strResult, m_OutputDeviceNull, nullptr, true);;
					}
				}
			}
			else
			if (m_IDAndFEventMessageMap.Contains(l_pWaitEmitEvent->i32ID))
			{
				auto l_pEventDelegate = m_IDAndFEventMessageMap[l_pWaitEmitEvent->i32ID];
				UEventDelegateData*l_pUEventDelegateData = NewObject<UEventDelegateData>();
				l_pUEventDelegateData->SetData(l_pWaitEmitEvent);
				l_pEventDelegate->Broadcast(l_pUEventDelegateData);
				//UObject delete it?
				delete l_pUEventDelegateData;
			}
			delete l_pWaitEmitEvent;
		}
	}
}
//https://forums.unrealengine.com/development-discussion/c-gameplay-programming/33614-onactorhit-delegate-how-do-they-work
//
//FScriptDelegate Delegate;
//Delegate.BindUFunction(this, "OnActorBump");
//GetOwner()->OnActorHit.AddUnique(Delegate);
//
bool FDelegateHandlerModule::RegisterDelegate(FMyLazyDelegate*e_pFMyLazyDelegate)
{
	if (!m_IDAndFEventMessageMap.Contains(e_pFMyLazyDelegate->m_i32ID))
	{
		FEventMessage*l_pEventMessage = new FEventMessage();
		m_IDAndFEventMessageMap.Add(e_pFMyLazyDelegate->m_i32ID,l_pEventMessage);
	}
	auto l_FEventMessage = m_IDAndFEventMessageMap[e_pFMyLazyDelegate->m_i32ID];
	l_FEventMessage->Add(e_pFMyLazyDelegate->m_FScriptDelegate);
	if (l_FEventMessage->IsBound())
	{
		int a = 0;
	}
	return true;
}
bool FDelegateHandlerModule::RegisterNetworkMessage(FMyLazyDelegate*e_pFMyLazyDelegate)
{
	if (!m_IDAndFNetworkMessageMap.Contains(e_pFMyLazyDelegate->m_i32ID))
	{
		FNetworkMessage*l_pNetworkMessage = new FNetworkMessage();
		m_IDAndFNetworkMessageMap.Add(e_pFMyLazyDelegate->m_i32ID,l_pNetworkMessage);
	}
	auto l_FNetworkMessage = m_IDAndFNetworkMessageMap[e_pFMyLazyDelegate->m_i32ID];
	l_FNetworkMessage->Add(e_pFMyLazyDelegate->m_FScriptDelegate);
	if (l_FNetworkMessage->IsBound())
	{
		int a = 0;
	}
	return true;
}

bool FDelegateHandlerModule::RemoveDelegate(FMyLazyDelegate*e_pFMyLazyDelegate)
{
	if (!m_IDAndFNetworkMessageMap.Contains(e_pFMyLazyDelegate->m_i32ID))
	{
		return false;
		//FNetworkMessage*l_pNetworkMessage = new FNetworkMessage();
		//m_IDAndFNetworkMessageMap.Add(e_pFMyLazyDelegate->m_i32ID,l_pNetworkMessage);
	}
	auto l_FEventMessage = m_IDAndFEventMessageMap[e_pFMyLazyDelegate->m_i32ID];
	l_FEventMessage->Remove(e_pFMyLazyDelegate->m_FScriptDelegate);
	return true;
}

bool FDelegateHandlerModule::RemoveNetworkMessage(FMyLazyDelegate*e_pFMyLazyDelegate)
{
	auto l_FNetworkMessage = m_IDAndFNetworkMessageMap[e_pFMyLazyDelegate->m_i32ID];
	if (!l_FNetworkMessage)
		return false;
	l_FNetworkMessage->Remove(e_pFMyLazyDelegate->m_FScriptDelegate);
	return true;
}

bool FDelegateHandlerModule::RegisterBPDelegate(FMyLazyDelegate * e_pFMyLazyDelegate)
{
	std::vector<sBPEventBindingData*>*l_pVector = nullptr;
	if (m_IDBPEventBindingDataVectorMap.find(e_pFMyLazyDelegate->m_i32ID) == m_IDBPEventBindingDataVectorMap.end())
	{
		l_pVector = new std::vector<sBPEventBindingData*>;
		m_IDBPEventBindingDataVectorMap[e_pFMyLazyDelegate->m_i32ID] = l_pVector;
	}
	else
	{
		l_pVector = m_IDBPEventBindingDataVectorMap[e_pFMyLazyDelegate->m_i32ID];
	}
	sBPEventBindingData*l_pBPEventBindingData = new sBPEventBindingData();
	l_pBPEventBindingData->FunctionName = e_pFMyLazyDelegate->m_FunctionName;
	l_pBPEventBindingData->pObject = e_pFMyLazyDelegate->m_pObject;
	l_pVector->push_back(l_pBPEventBindingData);;
	return true;
}

bool FDelegateHandlerModule::RemoveBPDelegate(FMyLazyDelegate * e_pFMyLazyDelegate)
{
	std::vector<sBPEventBindingData*>*l_pVector = nullptr;
	if (m_IDBPEventBindingDataVectorMap.find(e_pFMyLazyDelegate->m_i32ID) == m_IDBPEventBindingDataVectorMap.end())
	{
		return false;
	}
	else
	{
		l_pVector = m_IDBPEventBindingDataVectorMap[e_pFMyLazyDelegate->m_i32ID];
	}
	for (int i = 0; i < (int)l_pVector->size(); ++i)
	{
		sBPEventBindingData* l_pData = (*l_pVector)[i];
		if (l_pData->pObject == e_pFMyLazyDelegate->m_pObject
			&& l_pData->FunctionName == e_pFMyLazyDelegate->m_FunctionName)
		{
			delete l_pData;
			l_pVector->erase(l_pVector->begin() + i);
			--i;
		}
	}
	return true;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FDelegateHandlerModule, DelegateHandler)