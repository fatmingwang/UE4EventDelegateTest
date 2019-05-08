// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Core/Public/HAL/Runnable.h"
#include "Networking.h"
#include "NetWorkMessageData.h"
//#include "SocketTask.generated.h"
//https://forums.unrealengine.com/development-discussion/c-gameplay-programming/9535-how-to-connect-to-socket
/**
 *
 */

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
	TArray<UNetWorkMessageDelegateData*>m_UNetWorkMessageDelegateDataArray;

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
	bool	FetchNetworkMessage(TArray<UNetWorkMessageDelegateData*>&e_UNetWorkMessageDelegateDataArray);
private:

	/** Processes the socket message */
	//void ProcessSocketMessage(char*e_pData);
};