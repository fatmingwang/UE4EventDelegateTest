// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECTCODEREPORT_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	//
	FDelegateHandle				m_TickDelegateHandle;
	class NetworkBrain*			m_pNetworkBrain;
public:
	UMyGameInstance();
	virtual ~UMyGameInstance();
	void Init() override;

	void Shutdown() override;

	bool Tick(float DeltaSeconds);

	UFUNCTION(BlueprintCallable, Category = "FM")
	void ConnectToServer(FString e_strIP, int e_iPort);
};
