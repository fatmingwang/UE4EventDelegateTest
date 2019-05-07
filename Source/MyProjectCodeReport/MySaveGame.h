// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MySaveGame.generated.h"

/**
 * 
 */

UCLASS()
class MYPROJECTCODEREPORT_API UMySaveGame : public USaveGame
{
	GENERATED_BODY()
public:
	UMySaveGame();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BPTest")
	FString m_strUserID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BPTest")
	FString m_strUserPWD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BPTest")
	bool	m_bRememberData;

	UFUNCTION(BlueprintCallable, Category = "BPTest")
	void			SaveData(FString e_strSlotNAme,int e_UserIndex, bool e_bRememberMe);
	UFUNCTION(BlueprintCallable, Category = "BPTest")
	UMySaveGame*	LoadData(FString e_strSlotNAme, int e_UserIndex);
	
};