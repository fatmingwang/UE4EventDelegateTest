#pragma once

#include "CoreMinimal.h"
#include "EventEnum.generated.h"


//https://wiki.unrealengine.com/Enums_For_Both_C%2B%2B_and_BP
UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class eCodeReportEventEnum : uint8
{
	eCREE_LOGIN_BUTTON_CLICK	UMETA(DisplayName = "WidgetLoginButtonClick"),
	eCREE_LOGIN_MAX				UMETA(DisplayName = "MAX_INLEGAL")
};


UCLASS(BlueprintType)
class MYPROJECTCODEREPORT_API UNetworkLoginResult_Event:public UObject
{
	GENERATED_BODY()
public:
	int	m_iResult;
	UNetworkLoginResult_Event();
	virtual ~UNetworkLoginResult_Event();
};