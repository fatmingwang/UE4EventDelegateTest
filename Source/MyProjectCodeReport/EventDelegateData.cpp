// Fill out your copyright notice in the Description page of Project Settings.


#include "EventDelegateData.h"


UEventDelegateData::UEventDelegateData()
{
	i32EventID = -1;
	pReferencePointer = nullptr;
}

void	UEventDelegateData::SetData(uint32 e_i32Value, char*e_pReferenceData)
{
	i32EventID = e_i32Value;
	pReferencePointer = e_pReferenceData;
}
void	UEventDelegateData::SetData(uint32 e_i32Value, char*e_pData, int e_iDataSize)
{
	i32EventID = e_i32Value;
	pReferencePointer = nullptr;
	if (e_iDataSize)
	{
		memcpy(Data, e_pData, e_iDataSize);
	}
}

UEventDelegateData::~UEventDelegateData()
{
}