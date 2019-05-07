// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMessageHanlder.h"
#include "MyGameInstance.h"
#include "NetWorkMessageData.h"
FMyMessageHanlder*g_pMyMessageHanlder = nullptr;
FMyLazyDelegate::FMyLazyDelegate(uint32 e_iID, UObject*e_pObject, FName e_Name, int e_iBindingType)
{
	m_pObject = nullptr;
	m_iBindingType = -1;
	m_i32ID = -1;
	if (g_pMyMessageHanlder)
	{
		m_pObject = e_pObject;
		m_iBindingType = e_iBindingType;
		m_i32ID = e_iID;
		m_FScriptDelegate.BindUFunction(e_pObject, e_Name);
		if(m_i32ID == 1)
			g_pMyMessageHanlder->RegisterNetworkMessage(this);
		else
		if (m_i32ID == 0)
			g_pMyMessageHanlder->RegisterEvent(this);
		else
		{

		}
	}
}
FMyLazyDelegate::~FMyLazyDelegate()
{
	if (g_pMyMessageHanlder)
	{
		if(m_i32ID == 1)
			g_pMyMessageHanlder->RemoveNetworkMessage(this);
		else
		if (m_i32ID == 0)
			g_pMyMessageHanlder->RemoveEvent(this);
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

// Sets default values for this component's properties
//void FMyMessageHanlder::TestFunction()
//{
//
//}
FMyMessageHanlder::FMyMessageHanlder()
{
	g_pMyMessageHanlder = this;
	//m_FTestDelegate.AddDynamic(this, &FMyMessageHanlder::TestFunction)
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

FMyMessageHanlder::~FMyMessageHanlder()
{

}


// Called when the game starts
//void FMyMessageHanlder::BeginPlay()
//{
//	Super::BeginPlay();
//
//	// ...
//	
//}


// Called every frame
//void FMyMessageHanlder::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//	// ...
//}

void FMyMessageHanlder::EventShoot(uint32 e_iID, char * e_pData)
{
	FEventDataStruct l_FEventDataStruct(e_iID, e_pData);
	m_WaitProcessEventArray.Add(l_FEventDataStruct);
}

void FMyMessageHanlder::EventShoot(uint32 e_iID, char * e_pData, int e_iDataSize)
{
	FEventDataStruct l_FEventDataStruct(e_iID, e_pData, e_iDataSize);
	m_WaitProcessEventArray.Add(l_FEventDataStruct);
}

void FMyMessageHanlder::NetworkMessageShoot(FSocket*pSocket, uint32	e_i32NetworkMessageID, char*e_pData, int e_iDataSize)
{
	UNetWorkMessageData*l_pUNetWorkMessageData = NewObject<UNetWorkMessageData>();
	l_pUNetWorkMessageData->SetData(pSocket, e_pData);
	m_WaitProcessNetworkArray.Add(l_pUNetWorkMessageData);
}

void FMyMessageHanlder::FireEventAndtNetworkMessage()
{
	m_WaitProcessNetworkArray;
}
void FMyMessageHanlder::RegisterEventForBP(uint32 e_iID, UObject * e_pObject, FName e_Name)
{
	TArray<FMyLazyDelegate*>& l_MyLazyDelegateArrayRef = m_UObjectAndFMyLazyDelegateMapForBPBindEvent[e_pObject];
	FMyLazyDelegate*l_pFMyLazyDelegate = new FMyLazyDelegate(e_iID,e_pObject,e_Name, eBindingType::eBT_EVENT);
	l_MyLazyDelegateArrayRef.Add(l_pFMyLazyDelegate);
	//i
}
void FMyMessageHanlder::RegisterNetworkMessageForBP(uint32 e_iID, UObject * e_pObject, FName e_Name)
{
	TArray<FMyLazyDelegate*>& l_MyLazyDelegateArrayRef = m_UObjectAndFMyLazyDelegateMapForBPBindEvent[e_pObject];
	FMyLazyDelegate*l_pFMyLazyDelegate = new FMyLazyDelegate(e_iID, e_pObject, e_Name, eBindingType::eBT_NETWORK);
	l_MyLazyDelegateArrayRef.Add(l_pFMyLazyDelegate);
}
void FMyMessageHanlder::RemoveBindingBP(UObject * e_pObject)
{
	TArray<FMyLazyDelegate*>& l_MyLazyDelegateArrayRef = m_UObjectAndFMyLazyDelegateMapForBPBindEvent[e_pObject];
	for (int i = 0; i < l_MyLazyDelegateArrayRef.Num(); ++i)
	{
		FMyLazyDelegate*l_pFMyLazyDelegate = l_MyLazyDelegateArrayRef[i];
		if (l_pFMyLazyDelegate)
			delete l_pFMyLazyDelegate;
	}
	l_MyLazyDelegateArrayRef.Empty();
	m_UObjectAndFMyLazyDelegateMapForBPBindEvent.Remove(e_pObject);
	
}
//https://forums.unrealengine.com/development-discussion/c-gameplay-programming/33614-onactorhit-delegate-how-do-they-work
//
//FScriptDelegate Delegate;
//Delegate.BindUFunction(this, "OnActorBump");
//GetOwner()->OnActorHit.AddUnique(Delegate);
//
void FMyMessageHanlder::RegisterEvent(FMyLazyDelegate*e_pFMyLazyDelegate)
{
	auto l_FEventMessage = m_IDAndFEventMessageMap[e_pFMyLazyDelegate->m_i32ID];
	l_FEventMessage->Add(e_pFMyLazyDelegate->m_FScriptDelegate);
}
void FMyMessageHanlder::RegisterNetworkMessage(FMyLazyDelegate*e_pFMyLazyDelegate)
{
	auto l_FNetworkMessage = m_IDAndFNetworkMessageMap[e_pFMyLazyDelegate->m_i32ID];
	l_FNetworkMessage->Add(e_pFMyLazyDelegate->m_FScriptDelegate);
}

void FMyMessageHanlder::RemoveEvent(FMyLazyDelegate*e_pFMyLazyDelegate)
{
	auto l_FEventMessage = m_IDAndFEventMessageMap[e_pFMyLazyDelegate->m_i32ID];
	l_FEventMessage->Remove(e_pFMyLazyDelegate->m_FScriptDelegate);
}

void FMyMessageHanlder::RemoveNetworkMessage(FMyLazyDelegate*e_pFMyLazyDelegate)
{
	auto l_FNetworkMessage = m_IDAndFNetworkMessageMap[e_pFMyLazyDelegate->m_i32ID];
	l_FNetworkMessage->Remove(e_pFMyLazyDelegate->m_FScriptDelegate);
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

void UMyLazyBPDelegate::BindEventWithData(int32 e_i32ID, int32 e_iBindingType, FName e_FunctionName)
{
	m_i32ID = e_i32ID;
	m_iBindingType = e_iBindingType;
	m_FunctionName = e_FunctionName;
	if (m_pMyLazyDelegate)
		delete m_pMyLazyDelegate;
	m_pMyLazyDelegate = new FMyLazyDelegate(m_i32ID, m_pObject, m_FunctionName, m_iBindingType);
}