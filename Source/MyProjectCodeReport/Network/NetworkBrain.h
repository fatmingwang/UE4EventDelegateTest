// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../../ExternalScource_NetworkProtocal/NetworkMessage.h"
#include "DelegateHandler.h"
#include "NetworkBrain.generated.h"


/**
 * 
 */
UCLASS()
class MYPROJECTCODEREPORT_API UNetworkBrain:public UObject
{
	GENERATED_BODY()
	class SocketTask*m_pSocketTask;
	FMyLazyDelegate	 *m_pFMyLazyDelegate;
	//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEventMessage, UEventDelegateData*, e_Data);
	UFUNCTION()
	void			BPCallCPlusPlus(UEventDelegateData*e_Data);
public:
	UNetworkBrain();
	~UNetworkBrain();
	void	Init();
	void	Update(float e_fElpaseTime);
	void	ConnectToServer(FString e_strIP,int32 e_iPort);
};

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
