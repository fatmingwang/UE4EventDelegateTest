// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UEventDelegateData;
#ifdef DELEGATEHANDLER_EventDelegateData_generated_h
#error "EventDelegateData.generated.h already included, missing '#pragma once' in EventDelegateData.h"
#endif
#define DELEGATEHANDLER_EventDelegateData_generated_h

#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_EventDelegateData_h_27_DELEGATE \
struct _Script_DelegateHandler_eventEventMessage_Parms \
{ \
	UEventDelegateData* e_Data; \
}; \
static inline void FEventMessage_DelegateWrapper(const FMulticastScriptDelegate& EventMessage, UEventDelegateData* e_Data) \
{ \
	_Script_DelegateHandler_eventEventMessage_Parms Parms; \
	Parms.e_Data=e_Data; \
	EventMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_EventDelegateData_h_14_RPC_WRAPPERS
#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_EventDelegateData_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_EventDelegateData_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEventDelegateData(); \
	friend struct Z_Construct_UClass_UEventDelegateData_Statics; \
public: \
	DECLARE_CLASS(UEventDelegateData, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DelegateHandler"), NO_API) \
	DECLARE_SERIALIZER(UEventDelegateData)


#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_EventDelegateData_h_14_INCLASS \
private: \
	static void StaticRegisterNativesUEventDelegateData(); \
	friend struct Z_Construct_UClass_UEventDelegateData_Statics; \
public: \
	DECLARE_CLASS(UEventDelegateData, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DelegateHandler"), NO_API) \
	DECLARE_SERIALIZER(UEventDelegateData)


#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_EventDelegateData_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEventDelegateData(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEventDelegateData) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEventDelegateData); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEventDelegateData); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UEventDelegateData(UEventDelegateData&&); \
	NO_API UEventDelegateData(const UEventDelegateData&); \
public:


#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_EventDelegateData_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UEventDelegateData(UEventDelegateData&&); \
	NO_API UEventDelegateData(const UEventDelegateData&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEventDelegateData); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEventDelegateData); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UEventDelegateData)


#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_EventDelegateData_h_14_PRIVATE_PROPERTY_OFFSET
#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_EventDelegateData_h_11_PROLOG
#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_EventDelegateData_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_EventDelegateData_h_14_PRIVATE_PROPERTY_OFFSET \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_EventDelegateData_h_14_RPC_WRAPPERS \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_EventDelegateData_h_14_INCLASS \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_EventDelegateData_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_EventDelegateData_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_EventDelegateData_h_14_PRIVATE_PROPERTY_OFFSET \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_EventDelegateData_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_EventDelegateData_h_14_INCLASS_NO_PURE_DECLS \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_EventDelegateData_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DELEGATEHANDLER_API UClass* StaticClass<class UEventDelegateData>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_EventDelegateData_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
