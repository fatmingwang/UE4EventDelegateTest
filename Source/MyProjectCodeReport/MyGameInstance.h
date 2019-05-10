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
	UPROPERTY()
	class UNetworkBrain*		m_pNetworkBrain;
public:
	UMyGameInstance();
	virtual ~UMyGameInstance();
	virtual void Init() override;

	virtual void Shutdown() override;

	bool Tick(float DeltaSeconds);

	UFUNCTION(BlueprintCallable, Category = "FM")
	void ConnectToServer(FString e_strIP, int e_iPort);
	UFUNCTION(BlueprintCallable, Category = "FM")
	void MyInit();
};
