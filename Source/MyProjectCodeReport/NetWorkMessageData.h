// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NetWorkMessageData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class MYPROJECTCODEREPORT_API UNetWorkMessageData : public UObject
{
	GENERATED_BODY()
	class FSocket*pSocket;
	char*pData;
public:
	UNetWorkMessageData();
	UNetWorkMessageData(FSocket*e_pSocket, char*e_pData, int e_iDataSize);
	virtual ~UNetWorkMessageData();
	void	SetData(class FSocket*e_pSocket, char*e_pData);



};
