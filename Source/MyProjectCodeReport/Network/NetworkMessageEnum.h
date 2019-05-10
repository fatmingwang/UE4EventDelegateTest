#pragma once


//https://wiki.unrealengine.com/Enums_For_Both_C%2B%2B_and_BP
UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EVictoryEnum : uint8
{
	VE_Dance 	UMETA(DisplayName = "Dance"),
	VE_Rain 	UMETA(DisplayName = "Rain"),
	VE_Song	UMETA(DisplayName = "Song")
};