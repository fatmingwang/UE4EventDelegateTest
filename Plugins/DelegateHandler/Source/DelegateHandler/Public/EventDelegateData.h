// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EventDelegateData.generated.h"

#define	EVENT_DATA_SIZE	4096


//from FM79979 MessageSender
struct sWaitEmitEvent
{
	int32			i32ID;
	void*			pData;
	char			cData[EVENT_DATA_SIZE];
	sWaitEmitEvent() { pData = nullptr; memset(cData, sizeof(char), EVENT_DATA_SIZE); }
	~sWaitEmitEvent() {}
};
//intefac efor UE4(BP)
UCLASS(BlueprintType)
class DELEGATEHANDLER_API UEventDelegateData : public UObject
{
	GENERATED_BODY()
public:
	UEventDelegateData();
	virtual ~UEventDelegateData();
	//
	uint32	i32EventID;
	char	Data[EVENT_DATA_SIZE];
	void*	pReferencePointer;//ensure input data life circle is exists,it could be UObject ensure what you want.
	//
	void	SetData(sWaitEmitEvent*e_pWaitEmitEvent);
	UFUNCTION(BlueprintCallable, Category = "FM")
	UObject*GetUObjectPointer();
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEventMessage, UEventDelegateData*, e_Data);