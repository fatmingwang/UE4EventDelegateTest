// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Networking.h"

#include "MyActor.generated.h"

//https://wiki.unrealengine.com/TCP_Socket_Listener,_Receive_Binary_Data_From_an_IP/Port_Into_UE4,_%28Full_Code_Sample%29
UCLASS()
class MYPROJECTCODEREPORT_API AMyActor : public AActor
{
	GENERATED_BODY()
//
	class SocketTask*m_pSocketTask;
public:	
	// Sets default values for this actor's properties
	AMyActor();
	virtual ~AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Activate Fancy New Project-Specific System Created in C++! */
	UFUNCTION(BlueprintCallable, Category = "BPTest")
		void ConnectToServer(FString e_strIP,int e_iPort);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BPTest")
	int	m_iForBPTest = 5;
};
