// Fill out your copyright notice in the Description page of Project Settings.


#include "NetWorkMessageData.h"
#include "Sockets.h"
UNetWorkMessageData::UNetWorkMessageData()
{
	pSocket = nullptr;
	pData = nullptr;
}
UNetWorkMessageData::UNetWorkMessageData(FSocket*e_pSocket, char*e_pData, int e_iDataSize)
{
	pData = nullptr;
	pSocket = e_pSocket;
	if (e_iDataSize)
	{
		pData = new char[e_iDataSize];
		memcpy(pData, e_pData, e_iDataSize);
	}
}
UNetWorkMessageData::~UNetWorkMessageData()
{
	if (pData)
		delete[] pData;
}

void UNetWorkMessageData::SetData(FSocket * e_pSocket, char * e_pData)
{
	pSocket = e_pSocket;
	pData = e_pData;
}