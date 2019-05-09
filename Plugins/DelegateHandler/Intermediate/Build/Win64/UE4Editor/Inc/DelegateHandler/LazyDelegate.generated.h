// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef DELEGATEHANDLER_LazyDelegate_generated_h
#error "LazyDelegate.generated.h already included, missing '#pragma once' in LazyDelegate.h"
#endif
#define DELEGATEHANDLER_LazyDelegate_generated_h

#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_37_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execBindEventWithData) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_e_i32ID); \
		P_GET_PROPERTY(UIntProperty,Z_Param_e_iBindingType); \
		P_GET_PROPERTY(UNameProperty,Z_Param_e_FunctionName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->BindEventWithData(Z_Param_e_i32ID,Z_Param_e_iBindingType,Z_Param_e_FunctionName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBindEvent) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->BindEvent(); \
		P_NATIVE_END; \
	}


#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execBindEventWithData) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_e_i32ID); \
		P_GET_PROPERTY(UIntProperty,Z_Param_e_iBindingType); \
		P_GET_PROPERTY(UNameProperty,Z_Param_e_FunctionName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->BindEventWithData(Z_Param_e_i32ID,Z_Param_e_iBindingType,Z_Param_e_FunctionName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBindEvent) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->BindEvent(); \
		P_NATIVE_END; \
	}


#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_37_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMyLazyBPDelegate(); \
	friend struct Z_Construct_UClass_UMyLazyBPDelegate_Statics; \
public: \
	DECLARE_CLASS(UMyLazyBPDelegate, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DelegateHandler"), NO_API) \
	DECLARE_SERIALIZER(UMyLazyBPDelegate)


#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_37_INCLASS \
private: \
	static void StaticRegisterNativesUMyLazyBPDelegate(); \
	friend struct Z_Construct_UClass_UMyLazyBPDelegate_Statics; \
public: \
	DECLARE_CLASS(UMyLazyBPDelegate, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DelegateHandler"), NO_API) \
	DECLARE_SERIALIZER(UMyLazyBPDelegate)


#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_37_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMyLazyBPDelegate(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMyLazyBPDelegate) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyLazyBPDelegate); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyLazyBPDelegate); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMyLazyBPDelegate(UMyLazyBPDelegate&&); \
	NO_API UMyLazyBPDelegate(const UMyLazyBPDelegate&); \
public:


#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_37_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMyLazyBPDelegate(UMyLazyBPDelegate&&); \
	NO_API UMyLazyBPDelegate(const UMyLazyBPDelegate&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyLazyBPDelegate); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyLazyBPDelegate); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UMyLazyBPDelegate)


#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_37_PRIVATE_PROPERTY_OFFSET
#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_33_PROLOG
#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_37_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_37_PRIVATE_PROPERTY_OFFSET \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_37_RPC_WRAPPERS \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_37_INCLASS \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_37_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_37_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_37_PRIVATE_PROPERTY_OFFSET \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_37_INCLASS_NO_PURE_DECLS \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_37_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DELEGATEHANDLER_API UClass* StaticClass<class UMyLazyBPDelegate>();

#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_62_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execFireEventWithTArray) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_e_i32ID); \
		P_GET_TARRAY_REF(int32,Z_Param_Out_e_Data); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->FireEventWithTArray(Z_Param_e_i32ID,Z_Param_Out_e_Data); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFireEvent) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_e_i32ID); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->FireEvent(Z_Param_e_i32ID); \
		P_NATIVE_END; \
	}


#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_62_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execFireEventWithTArray) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_e_i32ID); \
		P_GET_TARRAY_REF(int32,Z_Param_Out_e_Data); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->FireEventWithTArray(Z_Param_e_i32ID,Z_Param_Out_e_Data); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFireEvent) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_e_i32ID); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->FireEvent(Z_Param_e_i32ID); \
		P_NATIVE_END; \
	}


#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_62_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMyLazyBPEventFire(); \
	friend struct Z_Construct_UClass_UMyLazyBPEventFire_Statics; \
public: \
	DECLARE_CLASS(UMyLazyBPEventFire, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DelegateHandler"), NO_API) \
	DECLARE_SERIALIZER(UMyLazyBPEventFire)


#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_62_INCLASS \
private: \
	static void StaticRegisterNativesUMyLazyBPEventFire(); \
	friend struct Z_Construct_UClass_UMyLazyBPEventFire_Statics; \
public: \
	DECLARE_CLASS(UMyLazyBPEventFire, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DelegateHandler"), NO_API) \
	DECLARE_SERIALIZER(UMyLazyBPEventFire)


#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_62_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMyLazyBPEventFire(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMyLazyBPEventFire) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyLazyBPEventFire); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyLazyBPEventFire); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMyLazyBPEventFire(UMyLazyBPEventFire&&); \
	NO_API UMyLazyBPEventFire(const UMyLazyBPEventFire&); \
public:


#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_62_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMyLazyBPEventFire(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMyLazyBPEventFire(UMyLazyBPEventFire&&); \
	NO_API UMyLazyBPEventFire(const UMyLazyBPEventFire&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyLazyBPEventFire); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyLazyBPEventFire); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMyLazyBPEventFire)


#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_62_PRIVATE_PROPERTY_OFFSET
#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_59_PROLOG
#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_62_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_62_PRIVATE_PROPERTY_OFFSET \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_62_RPC_WRAPPERS \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_62_INCLASS \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_62_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_62_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_62_PRIVATE_PROPERTY_OFFSET \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_62_RPC_WRAPPERS_NO_PURE_DECLS \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_62_INCLASS_NO_PURE_DECLS \
	MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h_62_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DELEGATEHANDLER_API UClass* StaticClass<class UMyLazyBPEventFire>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MyProjectCodeReport_Plugins_DelegateHandler_Source_DelegateHandler_Public_LazyDelegate_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
