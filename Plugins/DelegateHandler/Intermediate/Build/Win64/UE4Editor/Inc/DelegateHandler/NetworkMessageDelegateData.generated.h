// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UNetWorkMessageDelegateData;
#ifdef DELEGATEHANDLER_NetworkMessageDelegateData_generated_h
#error "NetworkMessageDelegateData.generated.h already included, missing '#pragma once' in NetworkMessageDelegateData.h"
#endif
#define DELEGATEHANDLER_NetworkMessageDelegateData_generated_h

#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_NetworkMessageDelegateData_h_27_DELEGATE \
struct _Script_DelegateHandler_eventNetworkMessage_Parms \
{ \
	UNetWorkMessageDelegateData* e_Data; \
}; \
static inline void FNetworkMessage_DelegateWrapper(const FMulticastScriptDelegate& NetworkMessage, UNetWorkMessageDelegateData* e_Data) \
{ \
	_Script_DelegateHandler_eventNetworkMessage_Parms Parms; \
	Parms.e_Data=e_Data; \
	NetworkMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_NetworkMessageDelegateData_h_14_RPC_WRAPPERS
#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_NetworkMessageDelegateData_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_NetworkMessageDelegateData_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUNetWorkMessageDelegateData(); \
	friend struct Z_Construct_UClass_UNetWorkMessageDelegateData_Statics; \
public: \
	DECLARE_CLASS(UNetWorkMessageDelegateData, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DelegateHandler"), NO_API) \
	DECLARE_SERIALIZER(UNetWorkMessageDelegateData)


#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_NetworkMessageDelegateData_h_14_INCLASS \
private: \
	static void StaticRegisterNativesUNetWorkMessageDelegateData(); \
	friend struct Z_Construct_UClass_UNetWorkMessageDelegateData_Statics; \
public: \
	DECLARE_CLASS(UNetWorkMessageDelegateData, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DelegateHandler"), NO_API) \
	DECLARE_SERIALIZER(UNetWorkMessageDelegateData)


#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_NetworkMessageDelegateData_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UNetWorkMessageDelegateData(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UNetWorkMessageDelegateData) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UNetWorkMessageDelegateData); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UNetWorkMessageDelegateData); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UNetWorkMessageDelegateData(UNetWorkMessageDelegateData&&); \
	NO_API UNetWorkMessageDelegateData(const UNetWorkMessageDelegateData&); \
public:


#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_NetworkMessageDelegateData_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UNetWorkMessageDelegateData(UNetWorkMessageDelegateData&&); \
	NO_API UNetWorkMessageDelegateData(const UNetWorkMessageDelegateData&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UNetWorkMessageDelegateData); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UNetWorkMessageDelegateData); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UNetWorkMessageDelegateData)


#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_NetworkMessageDelegateData_h_14_PRIVATE_PROPERTY_OFFSET
#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_NetworkMessageDelegateData_h_11_PROLOG
#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_NetworkMessageDelegateData_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_NetworkMessageDelegateData_h_14_PRIVATE_PROPERTY_OFFSET \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_NetworkMessageDelegateData_h_14_RPC_WRAPPERS \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_NetworkMessageDelegateData_h_14_INCLASS \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_NetworkMessageDelegateData_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_NetworkMessageDelegateData_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_NetworkMessageDelegateData_h_14_PRIVATE_PROPERTY_OFFSET \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_NetworkMessageDelegateData_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_NetworkMessageDelegateData_h_14_INCLASS_NO_PURE_DECLS \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_NetworkMessageDelegateData_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DELEGATEHANDLER_API UClass* StaticClass<class UNetWorkMessageDelegateData>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_NetworkMessageDelegateData_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
