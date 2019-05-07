// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Core/Public/HAL/Runnable.h"
#include "Networking.h"
#include "NetWorkMessageData.h"
#include "SocketTask.generated.h"
//https://forums.unrealengine.com/development-discussion/c-gameplay-programming/9535-how-to-connect-to-socket
/**
 *
 */



DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNetworkMessage, UNetWorkMessageData*, e_Data);

class MYPROJECTCODEREPORT_API SocketTask : public FRunnable
{
	enum eConnectionStatus
	{
		eCS_NONE = 0,
		eCS_TRY_TO_CONNECT,
		eCS_CONNECTED,
		eCS_CONNECTION_FAILED,
		eCS_MAX
	};
	eConnectionStatus	m_eConnectionStatus = eCS_NONE;
	const	float		m_cfReConnectTime = 1.f;
	float				m_fReconnectTime = m_cfReConnectTime;
	void				TryConnect();
	//================



	FRunnableThread* RunnableThread;
	FSocket* Socket;
	TSharedPtr<FInternetAddr> InternetAddress;
	FString Address;
	int32 Port;
	//
	FCriticalSection m_mutex;
	TArray<UNetWorkMessageData*>m_UNetWorkMessageDataArray;

public:

	SocketTask(const FString& InAddress, int32 InPort);
	~SocketTask();


public: // FRunnable Interface

	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Stop() override;

	void	DebugRender();
	void	Update(float e_fElpaseTime);
	void	SendData(int e_iPacketSize,char*e_pData);
	bool	FetchNetworkMessage(TArray<UNetWorkMessageData*>&e_UNetWorkMessageDataArray);
private:

	/** Processes the socket message */
	//void ProcessSocketMessage(char*e_pData);
};

USTRUCT(BlueprintType)
struct MYPROJECTCODEREPORT_API FLoginResultData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerMusicSkill)
	int iResult;
	FLoginResultData(){}
	~FLoginResultData(){}
};
UCLASS()
class MYPROJECTCODEREPORT_API UNetworkConvertClass :public UObject
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, Category = "My Network Data Convert")
	static FLoginResultData CastLoginResult(UNetWorkMessageData*e_pUNetWorkMessageData)
	{
		FLoginResultData l_pFLoginResultData;// = 0;//(FLoginResultData*)e_pUNetWorkMessageData.pData;
		//FLoginResultData l_sLoginResultData;
		//l_sLoginResultData.iResult = 0;
		return l_pFLoginResultData;
	}
};
