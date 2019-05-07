// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Sockets.h"
#include "SocketTask.h"
#include "Function.h"

#include "MyMessageHanlder.generated.h"

#define	EVENT_DATA_SIZE	4096

USTRUCT(BlueprintType)
struct MYPROJECTCODEREPORT_API FEventDataStruct
{
	GENERATED_BODY()

	UPROPERTY()
	uint32	i32EventID;
	char	Data[EVENT_DATA_SIZE];
	void*	pReferencePointer;//ensure input data life circle is exists
	FEventDataStruct()
	{
		i32EventID = -1;
		pReferencePointer = nullptr;
	}
	FEventDataStruct(uint32 e_i32Value, char*e_pReferenceData)
	{
		i32EventID = e_i32Value;
		pReferencePointer = e_pReferenceData;
	}
	FEventDataStruct(uint32 e_i32Value,char*e_pData,int e_iDataSize)
	{
		i32EventID = e_i32Value;
		pReferencePointer = nullptr;
		if (e_iDataSize)
		{
			memcpy(Data, e_pData, e_iDataSize);
		}
	}
	~FEventDataStruct()
	{
	}
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEventMessage, FEventDataStruct&,e_Data);
enum eBindingType
{
	eBT_EVENT = 0,
	eBT_NETWORK,
	eBT_MAX
};
//this will auto unbind the event,so please ensure this is your class member.
class MYPROJECTCODEREPORT_API FMyLazyDelegate
{
public:
	FScriptDelegate m_FScriptDelegate;
	uint32			m_i32ID;
	int32			m_iBindingType;//0 for event 1 for network
	UObject*		m_pObject;
//public:
	FMyLazyDelegate(uint32 e_iID,UObject*e_pObject, FName e_Name,int e_iBindingType);
	~FMyLazyDelegate();
};

UCLASS(BlueprintType)
class UMyLazyBPDelegate:public UObject
{
	FMyLazyDelegate*m_pMyLazyDelegate;
	GENERATED_BODY()
public:
	//
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FM")
	UPROPERTY(EditAnywhere)
	int32			m_i32ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FM")
	int32			m_iBindingType;//0 for event 1 for network
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FM")
	UObject*		m_pObject;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FM")
	FName			m_FunctionName;
	//
	UMyLazyBPDelegate();
	virtual ~UMyLazyBPDelegate();
	UFUNCTION(BlueprintCallable, Category = "FM")
	void BindEvent();

	UFUNCTION(BlueprintCallable, Category = "FM")
	void BindEventWithData(int32 e_i32ID, int32 e_iBindingType,FName e_FunctionName);
};

//UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECTCODEREPORT_API FMyMessageHanlder
{
	//GENERATED_BODY()
	//
	friend class FMyLazyDelegate;
	//
	TArray<FEventDataStruct>				m_WaitProcessEventArray;
	TArray<UNetWorkMessageData*>			m_WaitProcessNetworkArray;

	TMap<int32,FNetworkMessage*>			m_IDAndFNetworkMessageMap;
	TMap<int32,FEventMessage*>				m_IDAndFEventMessageMap;
	//
	TMap<UObject*, TArray<FMyLazyDelegate*> >	m_UObjectAndFMyLazyDelegateMapForBPBindEvent;

public:	
	// Sets default values for this component's properties
	FMyMessageHanlder();
	virtual ~FMyMessageHanlder();

protected:
	// Called when the game starts
	//virtual void BeginPlay() override;
	//c++,for use FScriptDelegate
	void							RegisterEvent(FMyLazyDelegate*e_pFMyLazyDelegate);
	void							RegisterNetworkMessage(FMyLazyDelegate*e_pFMyLazyDelegate);
	void							RemoveEvent(FMyLazyDelegate*e_pFMyLazyDelegate);
	void							RemoveNetworkMessage(FMyLazyDelegate*e_pFMyLazyDelegate);
public:	
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void	EventShoot(uint32 e_iID,char*e_pData);
	void	EventShoot(uint32 e_iID, char*e_pData,int e_iDataSize);
	void	NetworkMessageShoot(FSocket*pSocket,uint32	e_i32NetworkMessageID,char*e_pData,int e_iDataSize);
	void	FireEventAndtNetworkMessage();

	//TMap<int32, FNetworkMessage*>	GetIDAndFNetworkMessageMap() { return m_IDAndFNetworkMessageMap; }
	//TMap<int32, FEventMessage*>		GetIDAndFEventMessageMap() { return m_IDAndFEventMessageMap; }
	//please remember call remove!.
	void							RegisterEventForBP(uint32 e_iID, UObject*e_pObject, FName e_Name);
	void							RegisterNetworkMessageForBP(uint32 e_iID, UObject*e_pObject, FName e_Name);
	void							RemoveBindingBP(UObject*e_pObject);
};
//https://answers.unrealengine.com/questions/568762/delegate-binduobject.html
//#define	BIND_EVENT(FMyMessageHanlder,EventID,Object,Function)  
////bool BindEvent(FMyMessageHanlder*e_pFMyMessageHanlder, uint32 e_i32EventID)
//{
//	if (e_pFMyMessageHanlder)
//	{
//		auto l_IDAndFNetworkMessageMap = e_pFMyMessageHanlder->GetIDAndFNetworkMessageMap();
//		FNetworkMessage l_FNetworkMessage = l_IDAndFNetworkMessageMap[e_i32EventID];
//		l_FNetworkMessage.AddDynamic(Object, Function);
//		//, Object, Function
//	}
//	return false;
//}