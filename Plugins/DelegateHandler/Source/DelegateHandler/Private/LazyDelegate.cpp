// Fill out your copyright notice in the Description page of Project Settings.

#include "LazyDelegate.h"
#include "DelegateHandler.h"
#include "NetworkMessageDelegateData.h"

DEFINE_LOG_CATEGORY(FDelegateHandlerModuleLogName);

FMyLazyDelegate::FMyLazyDelegate(uint32 e_iID, UObject*e_pObject, FName e_Name, int e_iBindingType)
{
	m_pObject = nullptr;
	m_iBindingType = -1;
	m_i32ID = -1;
	if (GetDelegateHandler())
	{
		m_pObject = e_pObject;
		m_iBindingType = e_iBindingType;
		m_i32ID = e_iID;
		m_FScriptDelegate.BindUFunction(e_pObject, e_Name);
		if(m_i32ID == 1)
			g_pDelegateHandlerModule->RegisterNetworkMessage(this);
		else
		if (m_i32ID == 0)
			g_pDelegateHandlerModule->RegisterEvent(this);
		else
		{

		}
	}
}
FMyLazyDelegate::~FMyLazyDelegate()
{
	if (GetDelegateHandler())
	{
		if(m_i32ID == 1)
			g_pDelegateHandlerModule->RemoveNetworkMessage(this);
		else
		if (m_i32ID == 0)
			g_pDelegateHandlerModule->RemoveEvent(this);
		else
		{

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

void UMyLazyBPDelegate::BindEvent()
{
	if (m_pMyLazyDelegate)
		delete m_pMyLazyDelegate;
	m_pMyLazyDelegate = new FMyLazyDelegate(m_i32ID, m_pObject, m_FunctionName, m_iBindingType);
}

void UMyLazyBPDelegate::BindEventWithData(UObject*e_pObject,int32 e_i32ID, int32 e_iBindingType, FName e_FunctionName)
{
	m_pObject = e_pObject;
	m_i32ID = e_i32ID;
	m_iBindingType = e_iBindingType;
	m_FunctionName = e_FunctionName;
	if (m_pMyLazyDelegate)
		delete m_pMyLazyDelegate;
	m_pMyLazyDelegate = new FMyLazyDelegate(m_i32ID, m_pObject, m_FunctionName, m_iBindingType);
}

UMyLazyBPDelegate* UMyLazyBPDelegate::BindingEventWithData(UObject*e_pObject, int32 e_i32ID, int32 e_iBindingType, FName e_FunctionName)
{
	UMyLazyBPDelegate*l_pUMyLazyBPDelegate = NewObject<UMyLazyBPDelegate>();
	l_pUMyLazyBPDelegate->BindEventWithData(e_pObject, e_i32ID, e_iBindingType, e_FunctionName);
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