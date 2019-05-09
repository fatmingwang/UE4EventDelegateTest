// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Sockets.h"
#include "NetworkMessageDelegateData.h"
//#include "Function.h"
#include "EventDelegateData.h"
#include "LazyDelegate.generated.h"

enum eBindingType
{
	eBT_EVENT = 0,
	eBT_NETWORK,
	eBT_MAX
};
//this will auto unbind the event,so please ensure this is your class member.

class DELEGATEHANDLER_API FMyLazyDelegate
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
class DELEGATEHANDLER_API UMyLazyBPDelegate:public UObject
{
	FMyLazyDelegate*m_pMyLazyDelegate;
	GENERATED_BODY()
public:
	//
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FM")
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FM")
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
};