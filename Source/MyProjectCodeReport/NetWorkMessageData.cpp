// Fill out your copyright notice in the Description page of Project Settings.


#include "NetWorkMessageData.h"
#include "Sockets.h"
UNetWorkMessageDelegateData::UNetWorkMessageDelegateData()
{
	pSocket = nullptr;
	pData = nullptr;
}
//UNetWorkMessageDelegateData::UNetWorkMessageDelegateData(FSocket*e_pSocket, char*e_pData, int e_iDataSize)
//{
//	pData = nullptr;
//	pSocket = e_pSocket;
//	if (e_iDataSize)
//	{
//		pData = new char[e_iDataSize];
//		memcpy(pData, e_pData, e_iDataSize);
//	}
//}

UNetWorkMessageDelegateData::~UNetWorkMessageDelegateData()
{
	if (pData)
		delete[] pData;
}

void UNetWorkMessageDelegateData::SetData(FSocket * e_pSocket, char * e_pData, int e_iDataSize)
{
	pSocket = e_pSocket;
	if (pData)
	{
		delete[] pData;
		pData = nullptr;
	}
	if (e_iDataSize)
	{
		pData = new char[e_iDataSize];
		memcpy(pData, e_pData, e_iDataSize);
	}
}