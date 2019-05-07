#pragma once

inline void GEngineAddOnScreenDebugMessage(uint64 Key, float TimeToDisplay, FColor DisplayColor, const FString& DebugMessage, bool bNewerOnTop = true, const FVector2D& TextScale = FVector2D::UnitVector)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(Key,TimeToDisplay,DisplayColor,DebugMessage,bNewerOnTop,TextScale);
#endif
}