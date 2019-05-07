// Fill out your copyright notice in the Description page of Project Settings.


#include "MySaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "../../ExternalScource_NetworkProtocal/NetworkMessage.h"
UMySaveGame::UMySaveGame()
{
	m_bRememberData = false;
}

void UMySaveGame::SaveData(FString e_strSlotNAme, int e_UserIndex, bool e_bRememberMe)
{
	if (!e_bRememberMe)
	{
		m_bRememberData = false;
		m_strUserID = "";
		m_strUserPWD = "";
	}
	UGameplayStatics::SaveGameToSlot(this, e_strSlotNAme, e_UserIndex);
}

UMySaveGame* UMySaveGame::LoadData(FString e_strSlotNAme, int e_UserIndex)
{
	UMySaveGame* l_pLoadGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));
	if (l_pLoadGameInstance)
	{
		l_pLoadGameInstance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(e_strSlotNAme, e_UserIndex));
		if (l_pLoadGameInstance)
		{
			m_bRememberData = l_pLoadGameInstance->m_bRememberData;
			m_strUserID = l_pLoadGameInstance->m_strUserID;
			m_strUserPWD = l_pLoadGameInstance->m_strUserPWD;
		}
	}
	return this;
}