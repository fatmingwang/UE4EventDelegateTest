// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
//#include "../../ExternalScource_NetworkProtocal/NetworkMessage.h"
#include "NetworkMessageDelegateData.generated.h"


//from FM79979 Core\Network\GameNetWork.h
struct	DELEGATEHANDLER_API sNetworkSendPacket
{
	int		iSize;
	char*	pData;
	sNetworkSendPacket() { pData = nullptr; iSize = 0; }
	~sNetworkSendPacket() {}
};
//from FM79979 Core\Network\GameNetWork.h
struct DELEGATEHANDLER_API sNetworkReceivedPacket
{
	int				iSize;
	char*			pData;
	class FSocket*	pReceivedSocket;
	sNetworkReceivedPacket();
	~sNetworkReceivedPacket();
	//return rest data wait for receiving,-1 or less or equal than 0 connection has problem(lost connection).
	int	ReceiveData(FSocket*e_pTCPsocket);
};

//store the data from network.
UCLASS(BlueprintType)
class DELEGATEHANDLER_API UNetWorkMessageDelegateData : public UObject
{
	GENERATED_BODY()
public:
	//reference from sNetworkReceivedPacket
	class FSocket*	m_pSocket;
	char*			m_pData;
	int32			m_i32EventID;
public:
	UNetWorkMessageDelegateData();
	//fuck U object is hard to do this for new operator overrideing
	//UNetWorkMessageDelegateData(FSocket*e_pSocket, char*e_pData, int e_iDataSize);
	virtual ~UNetWorkMessageDelegateData();
	void	SetData(sNetworkReceivedPacket*e_pNetworkReceivedPacket);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNetworkMessage, UNetWorkMessageDelegateData*, e_Data);