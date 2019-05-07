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
	class FMyMessageHanlder*	m_pUMessageHanlder;
public:
	void Init() override;

	void Shutdown() override;

	bool Tick(float DeltaSeconds);
	//UFUNCTION(BlueprintCallable, Category = "Fatming")
	//void							RegisterEvent(uint32 e_iID, UObject*e_pObject, FName e_Name);
	//void							RegisterNetworkMessage(uint32 e_iID, UObject*e_pObject, FName e_Name);
	//void							RemoveEvent(int32 e_iEventID, FScriptDelegate& e_FScriptDelegate);
	//void							RemoveNetworkMessage(int32 e_iEventID, FScriptDelegate& e_FScriptDelegate);
};
