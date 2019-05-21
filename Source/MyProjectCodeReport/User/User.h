// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"
#include <string>
#include <vector>
#include "MachineData.h"
#include "../../../ExternalScource_NetworkProtocal/NetworkMessage.h"

/**
 * 
 */
enum eUserAuthority
{
	eUA_WAIT_FOR_AUTHORIZE = 0,
	eUA_COMMON_USER,
	eUA_ADMIN,
	eUA_MAX
};
//class MYPROJECTCODEREPORT_API User
struct sUser
{
	bool						m_bLogined = false;
	char						m_strID[USER_ID_LENGTH];
	char						m_strPWD[USER_ID_LENGTH];
	eUserAuthority				m_eUserAuthority;
	std::vector<int>			m_OwnMachineVector;

	TWLeadStreamMachineIDAndReportInfoVectorMap	m_TWLeadStreamMachineIDAndReportInfoVectorMap;
};
