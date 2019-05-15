#pragma once

#include "CoreMinimal.h"
#include "EventEnum.generated.h"


//https://wiki.unrealengine.com/Enums_For_Both_C%2B%2B_and_BP
UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class eCodeReportEventEnum : uint8
{
	eCREE_BP_TO_CPP_LOGIN_BUTTON_CLICK	UMETA(DisplayName = "WidgetLoginButtonClick"),//
	eCREE_CPP_TO_BP_LOGIN_RESULT		UMETA(DisplayName = "login result"),//int result
	eCREE_NETWORK_STATUS_CHANGE			UMETA(DisplayName = "network status change"),//basicly only for c++(int result)
	eCREE_MAX							UMETA(DisplayName = "MAX_INLEGAL")
};