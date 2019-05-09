// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "SocketTask.h"
// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	m_iForBPTest = 10;
}

AMyActor::~AMyActor()
{
	//FOutputDeviceNull l_ODN;
	//this->CallFunctionByNameWithArguments(TEXT("FunctionName"), l_ODN, nullptr, true);
	//this->CallFunctionByNameWithArguments(TEXT("FunctionName Parameter1"),l_ODN, nullptr, true);
	//FOutputDeviceNull ar;
	//const FString command = FString::Printf(TEXT("FunctionName %s"), *Actor->GetName());
	//OtherActor->CallFunctionByNameWithArguments(*command, ar, NULL, true);	
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	

}

//void AMyActor::ConnectToServer(FString e_strIP, int e_iPort)
//{
//
//	//UMyGameGameInstance *gameInstance = Cast<UMyGameGameInstance>(GetParentActor()->GetGameInstance());
//	//if (gameInstance)
//	//{
//	//	do stuff;
//	//}
//	//else
//	//{
//	//	log error
//	//}
//}