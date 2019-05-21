#pragma once

#include "CoreMinimal.h"
//from FishDBStructer.h
#include <map>
#include <vector>
#include <string>

struct sReportInfo
{
	int		iReportCount;
	int		iProductTypeNumber;
	int		iMachineID;
	int64	i64ExchangeIn;
	int64	i64ExchangeOut;
	int64	i64BulletShootCount;
	int64	i64BetMoney;				// This Total
	int64	i64WinMoney;				// This Total
	int64	i64BulletTotalShootCount;   // This Total
	int64  	i64OVERCount;
	int64	i64OVERScore;
	int64	i64GameWater;
};

struct sReportInfoWithReportCodes :public sReportInfo
{
	std::string	strVersion;
	char		strReportCode[50];
	sReportInfoWithReportCodes()
	{
		memset(this, 0, sizeof(sReportInfoWithReportCodes));
	}
};

typedef std::map<int, std::vector<sReportInfoWithReportCodes> >	TWLeadStreamMachineIDAndReportInfoVectorMap;