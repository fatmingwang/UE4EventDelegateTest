// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EventDelegateData.generated.h"

#define	EVENT_DATA_SIZE	4096

UCLASS()
class DELEGATEHANDLER_API UEventDelegateData : public UObject
{
	GENERATED_BODY()
public:
	uint32	i32EventID;
	char	Data[EVENT_DATA_SIZE];
	void*	pReferencePointer;//ensure input data life circle is exists
	UEventDelegateData();
	//UEventDelegateData(uint32 e_i32Value, char*e_pReferenceData);
	//UEventDelegateData(uint32 e_i32Value, char*e_pData, int e_iDataSize);
	void	SetData(uint32 e_i32Value, char*e_pReferenceData);
	void	SetData(uint32 e_i32Value, char*e_pData, int e_iDataSize);
	~UEventDelegateData();
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEventMessage, UEventDelegateData*, e_Data);