// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Sockets.h"
#include "NetworkMessageDelegateData.h"
//#include "Function.h"
#include "EventDelegateData.h"
#include "LazyDelegate.generated.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class eBindingType : uint8
{
	eBT_CPLUSPLUS_EVENT		UMETA(DisplayName = "c++ event"),
	eBT_BP_EVENT			UMETA(DisplayName = "BP event"),
	eBT_NETWORK_MESSAGE		UMETA(DisplayName = "Network Message"),
	eBT_MAX					UMETA(DisplayName = "inlegal event type")
};
//this will auto unbind the event,so please ensure this is your class member.

class DELEGATEHANDLER_API FMyLazyDelegate
{
public:
	//https://answers.unrealengine.com/questions/725851/binding-and-declaring-delegates-in-different-ways.html
	FScriptDelegate m_FScriptDelegate;
	uint32			m_i32ID;
	eBindingType	m_eBindingType;//0 for event 1 for network
	UObject*		m_pObject;
	FName			m_FunctionName;
//public:
	FMyLazyDelegate(uint32 e_iID,UObject*e_pObject, FName e_FunctionName, eBindingType e_eBindingType);
	~FMyLazyDelegate();
};

UCLASS(BlueprintType)
class DELEGATEHANDLER_API UMyLazyBPDelegate:public UObject
{
	FMyLazyDelegate*m_pMyLazyDelegate;
	GENERATED_BODY()

	void BindEventWithData(UObject*e_pObject, int32 e_i32ID, eBindingType e_eBindingType, FName e_FunctionName);
public:
	//
	UMyLazyBPDelegate();
	virtual ~UMyLazyBPDelegate();

	UFUNCTION(BlueprintCallable, Category = "FM")
	static UMyLazyBPDelegate* BindingEventWithData(UObject*e_pObject, int32 e_i32ID, eBindingType e_eBindingType, FName e_FunctionName);
};
//for BP fire event
UCLASS(BlueprintType)
class DELEGATEHANDLER_API UMyLazyBPEventFire :public UObject
{
	GENERATED_BODY()
public:
	//
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FM")
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FM")
	int32			m_i32ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FM")
	TArray<int32>	m_ArrayData;
	UFUNCTION(BlueprintCallable, Category = "FM")
	void FireEvent(int32 e_i32ID);
	UFUNCTION(BlueprintCallable, Category = "FM")
	void FireEventWithTArray(int32 e_i32ID,TArray<int32>&e_Data);

	UFUNCTION(BlueprintCallable, Category = "FM")
	static bool FireEventWithInt(int32 e_i32ID,int32 e_iValue);
};