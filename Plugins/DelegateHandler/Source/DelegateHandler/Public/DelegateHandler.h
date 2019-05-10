// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "NetworkMessageDelegateData.h"
#include "LazyDelegate.h"
#include "EventDelegateData.h"
#include <vector>
//#include "DelegateHandler.generated.h"
//https://wiki.unrealengine.com/Logs,_Printing_Messages_To_Yourself_During_Runtime
DECLARE_LOG_CATEGORY_EXTERN(FDelegateHandlerModuleLogName, Log, All);

class DELEGATEHANDLER_API FDelegateHandlerModule : public IModuleInterface
{
	friend class FMyLazyDelegate;
	std::vector<sWaitEmitEvent*>			m_WaitForEmitEventVector;
	//
	//
	//TArray<UEventDelegateData*>				m_WaitProcessEventArray;
	//TArray<UNetWorkMessageDelegateData*>	m_WaitProcessNetworkArray;

	TMap<int32, FNetworkMessage*>			m_IDAndFNetworkMessageMap;
	TMap<int32, FEventMessage*>				m_IDAndFEventMessageMap;
protected:
	// Called when the game starts
	//virtual void BeginPlay() override;
	//c++,for use FScriptDelegate
	void	RegisterEvent(FMyLazyDelegate*e_pFMyLazyDelegate);
	void	RegisterNetworkMessage(FMyLazyDelegate*e_pFMyLazyDelegate);
	void	RemoveEvent(FMyLazyDelegate*e_pFMyLazyDelegate);
	void	RemoveNetworkMessage(FMyLazyDelegate*e_pFMyLazyDelegate);
public:
	FDelegateHandlerModule();
	virtual ~FDelegateHandlerModule();
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void	EventShoot(int32 e_iID, char*e_pData);
	void	EventShoot(int32 e_iID, char*e_pData, int e_iDataSize);
	//void	NetworkMessageShoot(FSocket*pSocket, uint32	e_i32NetworkMessageID, char*e_pData, int e_iDataSize);
	void	NetworkMessageShoot(UNetWorkMessageDelegateData*e_pUNetWorkMessageDelegateData);
	void	FireEventAndtNetworkMessage();

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	//
	//
	//
	//https://wiki.unrealengine.com/An_Introduction_to_UE4_Plugins#Non-Game_Module
	/**
		* Singleton-like access to this module's interface.  This is just for convenience!
		* Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
		*
		* @return Returns singleton instance, loading the module on demand if needed
		*/
	static inline FDelegateHandlerModule& Get()
	{
		return FModuleManager::LoadModuleChecked< FDelegateHandlerModule >("DelegateHandler");
	}

	/**
	* Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
	*
	* @return True if the module is loaded and ready to use
	*/
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("DelegateHandler");
	}
};
DELEGATEHANDLER_API FDelegateHandlerModule*	GetDelegateHandler();
extern DELEGATEHANDLER_API FDelegateHandlerModule*g_pDelegateHandlerModule;


//https://answers.unrealengine.com/questions/568762/delegate-binduobject.html
//#define	BIND_EVENT(FDelegateHanlder,EventID,Object,Function)  
////bool BindEvent(FDelegateHanlder*e_pFDelegateHanlder, uint32 e_i32EventID)
//{
//	if (e_pFDelegateHanlder)
//	{
//		auto l_IDAndFNetworkMessageMap = e_pFDelegateHanlder->GetIDAndFNetworkMessageMap();
//		FNetworkMessage l_FNetworkMessage = l_IDAndFNetworkMessageMap[e_i32EventID];
//		l_FNetworkMessage.AddDynamic(Object, Function);
//		//, Object, Function
//	}
//	return false;
//}