// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
//#include "../../ExternalScource_NetworkProtocal/NetworkMessage.h"
#include "NetWorkMessageData.generated.h"

//store the data from network.
UCLASS(BlueprintType)
class MYPROJECTCODEREPORT_API UNetWorkMessageDelegateData : public UObject
{
	GENERATED_BODY()
	class FSocket*pSocket;
	char*pData;
public:
	UNetWorkMessageDelegateData();
	//fuck U object is hard to do this for new operator overrideing
	//UNetWorkMessageDelegateData(FSocket*e_pSocket, char*e_pData, int e_iDataSize);
	virtual ~UNetWorkMessageDelegateData();
	void	SetData(class FSocket*e_pSocket, char*e_pData, int e_iDataSize);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNetworkMessage, UNetWorkMessageDelegateData*, e_Data);

USTRUCT(BlueprintType)
struct MYPROJECTCODEREPORT_API FLoginResultData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerMusicSkill)
	int iResult;
	FLoginResultData() {}
	~FLoginResultData() {}
};

UCLASS()
class MYPROJECTCODEREPORT_API UNetworkConvertClass :public UObject
{
	GENERATED_BODY()
	//eNM_C2S_LOGIN_REQUEST
	//
	UFUNCTION(BlueprintCallable, Category = "My Network Data Convert")
	static FLoginResultData CastLoginResult(UNetWorkMessageDelegateData*e_pUNetWorkMessageDelegateData)
	{
		FLoginResultData l_pFLoginResultData;// = 0;//(FLoginResultData*)e_pUNetWorkMessageDelegateData.pData;
		//FLoginResultData l_sLoginResultData;
		//l_sLoginResultData.iResult = 0;
		return l_pFLoginResultData;
	}
};
