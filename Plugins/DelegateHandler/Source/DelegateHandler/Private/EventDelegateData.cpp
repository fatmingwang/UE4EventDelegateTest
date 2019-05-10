// Fill out your copyright notice in the Description page of Project Settings.


#include "EventDelegateData.h"

UEventDelegateData::UEventDelegateData()
{
	i32EventID = -1;
	pReferencePointer = nullptr;
}

UEventDelegateData::~UEventDelegateData()
{
}

void	UEventDelegateData::SetData(sWaitEmitEvent*e_pWaitEmitEvent)
{
	i32EventID = e_pWaitEmitEvent->i32ID;
	memcpy(Data, e_pWaitEmitEvent->cData, sizeof(char)*EVENT_DATA_SIZE);
	pReferencePointer = e_pWaitEmitEvent->pData;
}

UObject*UEventDelegateData::GetUObjectPointer()
{
	if (pReferencePointer)
	{
		return (UObject*)pReferencePointer;
	}
	return nullptr;
}