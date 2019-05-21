// Fill out your copyright notice in the Description page of Project Settings.


#include "NetworkMessageDelegateData.h"
#include "Sockets.h"

sNetworkReceivedPacket::sNetworkReceivedPacket()
{
	pReceivedSocket = nullptr; pData = nullptr; iSize = 0;
}
sNetworkReceivedPacket::~sNetworkReceivedPacket()
{
	SAFE_DELETE_ARRAY(pData);
}

int	sNetworkReceivedPacket::ReceiveData(FSocket*e_pTCPsocket)
{
	int32 l_iPacketSize = sizeof(int);
	int32 l_iPacketSizeReaded = 0;
	int32 l_iPacketSizeStore = 0;
	if (e_pTCPsocket->Recv((uint8*)&l_iPacketSizeStore, sizeof(int), l_iPacketSizeReaded))
	{//for event ID,4 byte
		if (l_iPacketSizeReaded != sizeof(int))
			return -1;
		iSize = l_iPacketSizeStore;
		SAFE_DELETE_ARRAY(pData);
		this->pData = new char[l_iPacketSizeStore];
		if (e_pTCPsocket->Recv((uint8*)pData, l_iPacketSizeStore, l_iPacketSizeReaded))
		{//enusre data size is same
			if (l_iPacketSizeReaded != l_iPacketSizeStore)
			{
				SAFE_DELETE_ARRAY(pData);
				return -1;
			}
			return l_iPacketSizeReaded;
		}
		else
		{
			return -1;
		}
	}
	return -1;
}

UNetWorkMessageDelegateData::UNetWorkMessageDelegateData()
{
	m_i32EventID = -1;
	m_pSocket = nullptr;
	m_pData = nullptr;
}

UNetWorkMessageDelegateData::~UNetWorkMessageDelegateData()
{
}

void UNetWorkMessageDelegateData::SetData(sNetworkReceivedPacket*e_pNetworkReceivedPacket)
{
	m_pData = e_pNetworkReceivedPacket->pData;
	m_i32EventID = *(int*)e_pNetworkReceivedPacket->pData;
	m_pSocket = e_pNetworkReceivedPacket->pReceivedSocket;
}