// Fill out your copyright notice in the Description page of Project Settings.

#include "LazyDelegate.h"
#include "DelegateHandler.h"
#include "NetworkMessageDelegateData.h"

DEFINE_LOG_CATEGORY(FDelegateHandlerModuleLogName);

FMyLazyDelegate::FMyLazyDelegate(uint32 e_iID, UObject*e_pObject, FName e_FunctionName, eBindingType e_eBindingType)
{
	m_pObject = nullptr;
	m_eBindingType = eBindingType::eBT_MAX;
	m_i32ID = -1;
	if (GetDelegateHandler() && e_pObject)
	{
		m_pObject = e_pObject;
		m_eBindingType = e_eBindingType;
		m_i32ID = e_iID;
		m_FunctionName = e_FunctionName;
//#if UE_BUILD_DEBUG
#if !UE_BUILD_SHIPPING
		//GEngine->AddOnScreenDebugMessage();
		auto l_Function = e_pObject->FindFunction(e_FunctionName);
		if (!l_Function)
		{
			FString l_strLog = FString::Printf
			(
				TEXT("FMyLazyDelegate::FMyLazyDelegate %s can't not find function:%s"),
				*e_pObject->GetClass()->GetName()
				, *(e_FunctionName.ToString())
			);
			UE_LOG(FDelegateHandlerModuleLogName,Log, TEXT("%s"), *l_strLog);
		}
#endif
		m_FScriptDelegate.BindUFunction(e_pObject, e_FunctionName);
		if(m_eBindingType == eBindingType::eBT_NETWORK_MESSAGE)
			g_pDelegateHandlerModule->RegisterNetworkMessage(this);
		else
		if (m_eBindingType == eBindingType::eBT_CPLUSPLUS_EVENT)
		{
			g_pDelegateHandlerModule->RegisterEvent(this);
		}
		else
		if (m_eBindingType == eBindingType::eBT_BP_EVENT)
		{
			g_pDelegateHandlerModule->RegisterBPEvent(this);
		}
		else
		{
			UE_LOG(FDelegateHandlerModuleLogName, Log, TEXT("FMyLazyDelegate eBindingType is inlegal"));
		}
	}
}
FMyLazyDelegate::~FMyLazyDelegate()
{
	if (GetDelegateHandler())
	{
		if(m_eBindingType == eBindingType::eBT_NETWORK_MESSAGE)
			g_pDelegateHandlerModule->RemoveNetworkMessage(this);
		else
		if (m_eBindingType == eBindingType::eBT_CPLUSPLUS_EVENT)
		{
			g_pDelegateHandlerModule->RemoveEvent(this);
		}
		else
		if (m_eBindingType == eBindingType::eBT_BP_EVENT)
		{
			g_pDelegateHandlerModule->RemoveBPEvent(this);
		}
	}
	//auto l_GameInstance = GEngine->GetWorld()->GetGameInstance();
	//if (l_GameInstance)
	//{
	//	//gameInstance = Cast<UClientGameInstance>(GEngine->GetWorld()->GetGameInstance());
	//}
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


UMyLazyBPDelegate::UMyLazyBPDelegate()
{
	m_pMyLazyDelegate = nullptr;
}

UMyLazyBPDelegate::~UMyLazyBPDelegate()
{
	if (m_pMyLazyDelegate)
		delete m_pMyLazyDelegate;
}

void UMyLazyBPDelegate::BindEventWithData(UObject*e_pObject,int32 e_i32ID, eBindingType e_eBindingType, FName e_FunctionName)
{
	if (m_pMyLazyDelegate)
		delete m_pMyLazyDelegate;
	m_pMyLazyDelegate = new FMyLazyDelegate(e_i32ID, e_pObject, e_FunctionName, e_eBindingType);
}

UMyLazyBPDelegate* UMyLazyBPDelegate::BindingEventWithData(UObject*e_pObject, int32 e_i32ID, eBindingType e_eBindingType, FName e_FunctionName)
{
	UMyLazyBPDelegate*l_pUMyLazyBPDelegate = NewObject<UMyLazyBPDelegate>();
	l_pUMyLazyBPDelegate->BindEventWithData(e_pObject, e_i32ID, e_eBindingType, e_FunctionName);
	return l_pUMyLazyBPDelegate;
}


void UMyLazyBPEventFire::FireEvent(int32 e_i32ID)
{
	if(GetDelegateHandler())
	{
		g_pDelegateHandlerModule->EventShoot(e_i32ID, nullptr);
	}
}

void UMyLazyBPEventFire::FireEventWithTArray(int32 e_i32ID, TArray<int32>&e_Data)
{
	if (GetDelegateHandler())
	{
		int l_iNum = e_Data.Num();
		int32* l_pData = nullptr;
		if (l_iNum)
		{
			l_pData = new int32[l_iNum];
			for (int i=0;i< l_iNum;++i)
			{
				l_pData[i] = e_Data[i];
			}
		}
		g_pDelegateHandlerModule->EventShoot(e_i32ID, (char*)l_pData,sizeof(int32)*l_iNum);
		if(l_pData)
			delete[] l_pData;
	}
}

bool UMyLazyBPEventFire::FireEventWithInt(int32 e_i32ID, int32 e_iValue)
{
	UMyLazyBPEventFire*l_pUMyLazyBPEventFire = NewObject<UMyLazyBPEventFire>();
	if (GetDelegateHandler())
	{
		g_pDelegateHandlerModule->EventShoot(e_i32ID, nullptr);
		return true;
	}
	return false;
}