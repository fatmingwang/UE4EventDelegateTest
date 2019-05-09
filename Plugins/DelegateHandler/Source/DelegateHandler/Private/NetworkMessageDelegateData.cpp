// Fill out your copyright notice in the Description page of Project Settings.


#include "NetworkMessageDelegateData.h"
#include "Sockets.h"
UNetWorkMessageDelegateData::UNetWorkMessageDelegateData()
{
	m_pSocket = nullptr;
	m_pData = nullptr;
	m_i32EventID = -1;
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
	if (m_pData)
		delete[] m_pData;
}

void UNetWorkMessageDelegateData::SetData(FSocket * e_pSocket, int32	e_i32EventID, char * e_pData, int e_iDataSize)
{
	m_i32EventID = e_i32EventID;
	m_pSocket = e_pSocket;
	if (m_pData)
	{
		delete[] m_pData;
		m_pData = nullptr;
	}
	if (e_iDataSize)
	{
		m_pData = new char[e_iDataSize];
		memcpy(m_pData, e_pData, e_iDataSize);
	}
}