// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DelegateHandler/Public/EventDelegateData.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEventDelegateData() {}
// Cross Module References
	DELEGATEHANDLER_API UFunction* Z_Construct_UDelegateFunction_DelegateHandler_EventMessage__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_DelegateHandler();
	DELEGATEHANDLER_API UClass* Z_Construct_UClass_UEventDelegateData_NoRegister();
	DELEGATEHANDLER_API UClass* Z_Construct_UClass_UEventDelegateData();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_DelegateHandler_EventMessage__DelegateSignature_Statics
	{
		struct _Script_DelegateHandler_eventEventMessage_Parms
		{
			UEventDelegateData* e_Data;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_e_Data;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_DelegateHandler_EventMessage__DelegateSignature_Statics::NewProp_e_Data = { "e_Data", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_DelegateHandler_eventEventMessage_Parms, e_Data), Z_Construct_UClass_UEventDelegateData_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_DelegateHandler_EventMessage__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_DelegateHandler_EventMessage__DelegateSignature_Statics::NewProp_e_Data,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_DelegateHandler_EventMessage__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/EventDelegateData.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_DelegateHandler_EventMessage__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_DelegateHandler, nullptr, "EventMessage__DelegateSignature", sizeof(_Script_DelegateHandler_eventEventMessage_Parms), Z_Construct_UDelegateFunction_DelegateHandler_EventMessage__DelegateSignature_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UDelegateFunction_DelegateHandler_EventMessage__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_DelegateHandler_EventMessage__DelegateSignature_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UDelegateFunction_DelegateHandler_EventMessage__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_DelegateHandler_EventMessage__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_DelegateHandler_EventMessage__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	void UEventDelegateData::StaticRegisterNativesUEventDelegateData()
	{
	}
	UClass* Z_Construct_UClass_UEventDelegateData_NoRegister()
	{
		return UEventDelegateData::StaticClass();
	}
	struct Z_Construct_UClass_UEventDelegateData_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UEventDelegateData_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_DelegateHandler,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEventDelegateData_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "EventDelegateData.h" },
		{ "ModuleRelativePath", "Public/EventDelegateData.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UEventDelegateData_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEventDelegateData>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UEventDelegateData_Statics::ClassParams = {
		&UEventDelegateData::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UEventDelegateData_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UEventDelegateData_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UEventDelegateData()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UEventDelegateData_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UEventDelegateData, 1519437268);
	template<> DELEGATEHANDLER_API UClass* StaticClass<UEventDelegateData>()
	{
		return UEventDelegateData::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UEventDelegateData(Z_Construct_UClass_UEventDelegateData, &UEventDelegateData::StaticClass, TEXT("/Script/DelegateHandler"), TEXT("UEventDelegateData"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UEventDelegateData);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
