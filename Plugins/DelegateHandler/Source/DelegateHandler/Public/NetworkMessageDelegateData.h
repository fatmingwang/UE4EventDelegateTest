// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
//#include "../../ExternalScource_NetworkProtocal/NetworkMessage.h"
#include "NetworkMessageDelegateData.generated.h"

//store the data from network.
UCLASS(BlueprintType)
class DELEGATEHANDLER_API UNetWorkMessageDelegateData : public UObject
{
	GENERATED_BODY()
public:
	class FSocket*	m_pSocket;
	char*			m_pData;
	int32			m_i32EventID;
public:
	UNetWorkMessageDelegateData();
	//fuck U object is hard to do this for new operator overrideing
	//UNetWorkMessageDelegateData(FSocket*e_pSocket, char*e_pData, int e_iDataSize);
	virtual ~UNetWorkMessageDelegateData();
	void	SetData(class FSocket*e_pSocket, int32	e_i32EventID, char*e_pData, int e_iDataSize);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNetworkMessage, UNetWorkMessageDelegateData*, e_Data);