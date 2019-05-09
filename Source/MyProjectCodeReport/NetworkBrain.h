// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../../ExternalScource_NetworkProtocal/NetworkMessage.h"
#include "DelegateHandler.h"
#include "NetworkBrain.generated.h"


//https://wiki.unrealengine.com/Enums_For_Both_C%2B%2B_and_BP
UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EVictoryEnum : uint8
{
	VE_Dance 	UMETA(DisplayName = "Dance"),
	VE_Rain 	UMETA(DisplayName = "Rain"),
	VE_Song	UMETA(DisplayName = "Song")
};

/**
 * 
 */
class MYPROJECTCODEREPORT_API NetworkBrain
{
	class SocketTask*m_pSocketTask;
public:
	NetworkBrain();
	~NetworkBrain();
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
