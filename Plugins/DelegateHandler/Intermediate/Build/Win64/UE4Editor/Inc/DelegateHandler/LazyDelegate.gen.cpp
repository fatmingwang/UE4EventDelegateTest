// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DelegateHandler/Public/LazyDelegate.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLazyDelegate() {}
// Cross Module References
	DELEGATEHANDLER_API UClass* Z_Construct_UClass_UMyLazyBPDelegate_NoRegister();
	DELEGATEHANDLER_API UClass* Z_Construct_UClass_UMyLazyBPDelegate();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_DelegateHandler();
	DELEGATEHANDLER_API UFunction* Z_Construct_UFunction_UMyLazyBPDelegate_BindEvent();
	DELEGATEHANDLER_API UFunction* Z_Construct_UFunction_UMyLazyBPDelegate_BindEventWithData();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	DELEGATEHANDLER_API UClass* Z_Construct_UClass_UMyLazyBPEventFire_NoRegister();
	DELEGATEHANDLER_API UClass* Z_Construct_UClass_UMyLazyBPEventFire();
	DELEGATEHANDLER_API UFunction* Z_Construct_UFunction_UMyLazyBPEventFire_FireEvent();
	DELEGATEHANDLER_API UFunction* Z_Construct_UFunction_UMyLazyBPEventFire_FireEventWithTArray();
// End Cross Module References
	void UMyLazyBPDelegate::StaticRegisterNativesUMyLazyBPDelegate()
	{
		UClass* Class = UMyLazyBPDelegate::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BindEvent", &UMyLazyBPDelegate::execBindEvent },
			{ "BindEventWithData", &UMyLazyBPDelegate::execBindEventWithData },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMyLazyBPDelegate_BindEvent_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyLazyBPDelegate_BindEvent_Statics::Function_MetaDataParams[] = {
		{ "Category", "FM" },
		{ "ModuleRelativePath", "Public/LazyDelegate.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyLazyBPDelegate_BindEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyLazyBPDelegate, nullptr, "BindEvent", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyLazyBPDelegate_BindEvent_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UMyLazyBPDelegate_BindEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyLazyBPDelegate_BindEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMyLazyBPDelegate_BindEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMyLazyBPDelegate_BindEventWithData_Statics
	{
		struct MyLazyBPDelegate_eventBindEventWithData_Parms
		{
			int32 e_i32ID;
			int32 e_iBindingType;
			FName e_FunctionName;
		};
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_e_FunctionName;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_e_iBindingType;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_e_i32ID;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UMyLazyBPDelegate_BindEventWithData_Statics::NewProp_e_FunctionName = { "e_FunctionName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyLazyBPDelegate_eventBindEventWithData_Parms, e_FunctionName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMyLazyBPDelegate_BindEventWithData_Statics::NewProp_e_iBindingType = { "e_iBindingType", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyLazyBPDelegate_eventBindEventWithData_Parms, e_iBindingType), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMyLazyBPDelegate_BindEventWithData_Statics::NewProp_e_i32ID = { "e_i32ID", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyLazyBPDelegate_eventBindEventWithData_Parms, e_i32ID), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyLazyBPDelegate_BindEventWithData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyLazyBPDelegate_BindEventWithData_Statics::NewProp_e_FunctionName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyLazyBPDelegate_BindEventWithData_Statics::NewProp_e_iBindingType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyLazyBPDelegate_BindEventWithData_Statics::NewProp_e_i32ID,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyLazyBPDelegate_BindEventWithData_Statics::Function_MetaDataParams[] = {
		{ "Category", "FM" },
		{ "ModuleRelativePath", "Public/LazyDelegate.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyLazyBPDelegate_BindEventWithData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyLazyBPDelegate, nullptr, "BindEventWithData", sizeof(MyLazyBPDelegate_eventBindEventWithData_Parms), Z_Construct_UFunction_UMyLazyBPDelegate_BindEventWithData_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UMyLazyBPDelegate_BindEventWithData_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyLazyBPDelegate_BindEventWithData_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UMyLazyBPDelegate_BindEventWithData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyLazyBPDelegate_BindEventWithData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMyLazyBPDelegate_BindEventWithData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UMyLazyBPDelegate_NoRegister()
	{
		return UMyLazyBPDelegate::StaticClass();
	}
	struct Z_Construct_UClass_UMyLazyBPDelegate_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_FunctionName_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_m_FunctionName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_pObject_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_m_pObject;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_iBindingType_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_m_iBindingType;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_i32ID_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_m_i32ID;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMyLazyBPDelegate_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_DelegateHandler,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UMyLazyBPDelegate_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMyLazyBPDelegate_BindEvent, "BindEvent" }, // 1035634539
		{ &Z_Construct_UFunction_UMyLazyBPDelegate_BindEventWithData, "BindEventWithData" }, // 2975640686
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyLazyBPDelegate_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "LazyDelegate.h" },
		{ "ModuleRelativePath", "Public/LazyDelegate.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyLazyBPDelegate_Statics::NewProp_m_FunctionName_MetaData[] = {
		{ "Category", "FM" },
		{ "ModuleRelativePath", "Public/LazyDelegate.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UClass_UMyLazyBPDelegate_Statics::NewProp_m_FunctionName = { "m_FunctionName", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMyLazyBPDelegate, m_FunctionName), METADATA_PARAMS(Z_Construct_UClass_UMyLazyBPDelegate_Statics::NewProp_m_FunctionName_MetaData, ARRAY_COUNT(Z_Construct_UClass_UMyLazyBPDelegate_Statics::NewProp_m_FunctionName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyLazyBPDelegate_Statics::NewProp_m_pObject_MetaData[] = {
		{ "Category", "FM" },
		{ "ModuleRelativePath", "Public/LazyDelegate.h" },
		{ "ToolTip", "0 for event 1 for network" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyLazyBPDelegate_Statics::NewProp_m_pObject = { "m_pObject", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMyLazyBPDelegate, m_pObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMyLazyBPDelegate_Statics::NewProp_m_pObject_MetaData, ARRAY_COUNT(Z_Construct_UClass_UMyLazyBPDelegate_Statics::NewProp_m_pObject_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyLazyBPDelegate_Statics::NewProp_m_iBindingType_MetaData[] = {
		{ "Category", "FM" },
		{ "ModuleRelativePath", "Public/LazyDelegate.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMyLazyBPDelegate_Statics::NewProp_m_iBindingType = { "m_iBindingType", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMyLazyBPDelegate, m_iBindingType), METADATA_PARAMS(Z_Construct_UClass_UMyLazyBPDelegate_Statics::NewProp_m_iBindingType_MetaData, ARRAY_COUNT(Z_Construct_UClass_UMyLazyBPDelegate_Statics::NewProp_m_iBindingType_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyLazyBPDelegate_Statics::NewProp_m_i32ID_MetaData[] = {
		{ "Category", "FM" },
		{ "ModuleRelativePath", "Public/LazyDelegate.h" },
		{ "ToolTip", "UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = \"FM\")" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMyLazyBPDelegate_Statics::NewProp_m_i32ID = { "m_i32ID", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMyLazyBPDelegate, m_i32ID), METADATA_PARAMS(Z_Construct_UClass_UMyLazyBPDelegate_Statics::NewProp_m_i32ID_MetaData, ARRAY_COUNT(Z_Construct_UClass_UMyLazyBPDelegate_Statics::NewProp_m_i32ID_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMyLazyBPDelegate_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyLazyBPDelegate_Statics::NewProp_m_FunctionName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyLazyBPDelegate_Statics::NewProp_m_pObject,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyLazyBPDelegate_Statics::NewProp_m_iBindingType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyLazyBPDelegate_Statics::NewProp_m_i32ID,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMyLazyBPDelegate_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyLazyBPDelegate>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMyLazyBPDelegate_Statics::ClassParams = {
		&UMyLazyBPDelegate::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UMyLazyBPDelegate_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_UMyLazyBPDelegate_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMyLazyBPDelegate_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UMyLazyBPDelegate_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMyLazyBPDelegate()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMyLazyBPDelegate_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMyLazyBPDelegate, 2261826972);
	template<> DELEGATEHANDLER_API UClass* StaticClass<UMyLazyBPDelegate>()
	{
		return UMyLazyBPDelegate::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMyLazyBPDelegate(Z_Construct_UClass_UMyLazyBPDelegate, &UMyLazyBPDelegate::StaticClass, TEXT("/Script/DelegateHandler"), TEXT("UMyLazyBPDelegate"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMyLazyBPDelegate);
	void UMyLazyBPEventFire::StaticRegisterNativesUMyLazyBPEventFire()
	{
		UClass* Class = UMyLazyBPEventFire::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "FireEvent", &UMyLazyBPEventFire::execFireEvent },
			{ "FireEventWithTArray", &UMyLazyBPEventFire::execFireEventWithTArray },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMyLazyBPEventFire_FireEvent_Statics
	{
		struct MyLazyBPEventFire_eventFireEvent_Parms
		{
			int32 e_i32ID;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_e_i32ID;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMyLazyBPEventFire_FireEvent_Statics::NewProp_e_i32ID = { "e_i32ID", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyLazyBPEventFire_eventFireEvent_Parms, e_i32ID), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyLazyBPEventFire_FireEvent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyLazyBPEventFire_FireEvent_Statics::NewProp_e_i32ID,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyLazyBPEventFire_FireEvent_Statics::Function_MetaDataParams[] = {
		{ "Category", "FM" },
		{ "ModuleRelativePath", "Public/LazyDelegate.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyLazyBPEventFire_FireEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyLazyBPEventFire, nullptr, "FireEvent", sizeof(MyLazyBPEventFire_eventFireEvent_Parms), Z_Construct_UFunction_UMyLazyBPEventFire_FireEvent_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UMyLazyBPEventFire_FireEvent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyLazyBPEventFire_FireEvent_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UMyLazyBPEventFire_FireEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyLazyBPEventFire_FireEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMyLazyBPEventFire_FireEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMyLazyBPEventFire_FireEventWithTArray_Statics
	{
		struct MyLazyBPEventFire_eventFireEventWithTArray_Parms
		{
			int32 e_i32ID;
			TArray<int32> e_Data;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_e_Data;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_e_Data_Inner;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_e_i32ID;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UMyLazyBPEventFire_FireEventWithTArray_Statics::NewProp_e_Data = { "e_Data", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyLazyBPEventFire_eventFireEventWithTArray_Parms, e_Data), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMyLazyBPEventFire_FireEventWithTArray_Statics::NewProp_e_Data_Inner = { "e_Data", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMyLazyBPEventFire_FireEventWithTArray_Statics::NewProp_e_i32ID = { "e_i32ID", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyLazyBPEventFire_eventFireEventWithTArray_Parms, e_i32ID), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyLazyBPEventFire_FireEventWithTArray_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyLazyBPEventFire_FireEventWithTArray_Statics::NewProp_e_Data,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyLazyBPEventFire_FireEventWithTArray_Statics::NewProp_e_Data_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyLazyBPEventFire_FireEventWithTArray_Statics::NewProp_e_i32ID,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyLazyBPEventFire_FireEventWithTArray_Statics::Function_MetaDataParams[] = {
		{ "Category", "FM" },
		{ "ModuleRelativePath", "Public/LazyDelegate.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyLazyBPEventFire_FireEventWithTArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyLazyBPEventFire, nullptr, "FireEventWithTArray", sizeof(MyLazyBPEventFire_eventFireEventWithTArray_Parms), Z_Construct_UFunction_UMyLazyBPEventFire_FireEventWithTArray_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UMyLazyBPEventFire_FireEventWithTArray_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyLazyBPEventFire_FireEventWithTArray_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UMyLazyBPEventFire_FireEventWithTArray_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyLazyBPEventFire_FireEventWithTArray()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMyLazyBPEventFire_FireEventWithTArray_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UMyLazyBPEventFire_NoRegister()
	{
		return UMyLazyBPEventFire::StaticClass();
	}
	struct Z_Construct_UClass_UMyLazyBPEventFire_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_ArrayData_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_m_ArrayData;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_m_ArrayData_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_i32ID_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_m_i32ID;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMyLazyBPEventFire_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_DelegateHandler,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UMyLazyBPEventFire_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMyLazyBPEventFire_FireEvent, "FireEvent" }, // 1253733532
		{ &Z_Construct_UFunction_UMyLazyBPEventFire_FireEventWithTArray, "FireEventWithTArray" }, // 1712125267
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyLazyBPEventFire_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "LazyDelegate.h" },
		{ "ModuleRelativePath", "Public/LazyDelegate.h" },
		{ "ToolTip", "for BP fire event" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyLazyBPEventFire_Statics::NewProp_m_ArrayData_MetaData[] = {
		{ "Category", "FM" },
		{ "ModuleRelativePath", "Public/LazyDelegate.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UMyLazyBPEventFire_Statics::NewProp_m_ArrayData = { "m_ArrayData", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMyLazyBPEventFire, m_ArrayData), METADATA_PARAMS(Z_Construct_UClass_UMyLazyBPEventFire_Statics::NewProp_m_ArrayData_MetaData, ARRAY_COUNT(Z_Construct_UClass_UMyLazyBPEventFire_Statics::NewProp_m_ArrayData_MetaData)) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMyLazyBPEventFire_Statics::NewProp_m_ArrayData_Inner = { "m_ArrayData", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyLazyBPEventFire_Statics::NewProp_m_i32ID_MetaData[] = {
		{ "Category", "FM" },
		{ "ModuleRelativePath", "Public/LazyDelegate.h" },
		{ "ToolTip", "UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = \"FM\")" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMyLazyBPEventFire_Statics::NewProp_m_i32ID = { "m_i32ID", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMyLazyBPEventFire, m_i32ID), METADATA_PARAMS(Z_Construct_UClass_UMyLazyBPEventFire_Statics::NewProp_m_i32ID_MetaData, ARRAY_COUNT(Z_Construct_UClass_UMyLazyBPEventFire_Statics::NewProp_m_i32ID_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMyLazyBPEventFire_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyLazyBPEventFire_Statics::NewProp_m_ArrayData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyLazyBPEventFire_Statics::NewProp_m_ArrayData_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyLazyBPEventFire_Statics::NewProp_m_i32ID,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMyLazyBPEventFire_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyLazyBPEventFire>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMyLazyBPEventFire_Statics::ClassParams = {
		&UMyLazyBPEventFire::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UMyLazyBPEventFire_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_UMyLazyBPEventFire_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMyLazyBPEventFire_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UMyLazyBPEventFire_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMyLazyBPEventFire()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMyLazyBPEventFire_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMyLazyBPEventFire, 2360180945);
	template<> DELEGATEHANDLER_API UClass* StaticClass<UMyLazyBPEventFire>()
	{
		return UMyLazyBPEventFire::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMyLazyBPEventFire(Z_Construct_UClass_UMyLazyBPEventFire, &UMyLazyBPEventFire::StaticClass, TEXT("/Script/DelegateHandler"), TEXT("UMyLazyBPEventFire"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMyLazyBPEventFire);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
