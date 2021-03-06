#pragma once

#define		NETWORK_MESSAGE_VERSION		1.0//float
#define		MAX_MACHINE_COUNT			200
#define		TCP_IP_PORT					430
const int	g_ciNetworkVersion = 1;
#define		USER_ID_LENGTH				20
#define		USER_PWD_LENGTH				20
#define		USER_DESCRIPTION_LENGTH		20

#define		MESSAGE_ID_ASSIGN(TYPE,ID)TYPE():sBaseNetworkMessage(ID){memset(this,0,sizeof(TYPE));iSize = sizeof(TYPE);}
#define		RESULT_MESSAGE_ID_ASSIGN(TYPE,ID)TYPE():sBaseNetworkResultMessage(ID){memset(this,0,sizeof(TYPE));iSize = sizeof(TYPE);}

#define		RESULT_STRUCT_ASSIGN(TYPE,ID)								\
				struct TYPE:public sBaseNetworkResultMessage			\
				{														\
					TYPE():sBaseNetworkResultMessage(ID) {memset(this,0,sizeof(TYPE));iSize = sizeof(TYPE);}				\
				};


enum eNetworkMessage
{
	eNM_C2S_LOGIN_REQUEST = 0,
	eNM_S2C_LOGIN_RESULT,
	eNM_C2S_ADD_USER_REQUEST,
	eNM_S2C_ADD_USER_RESULT,
	eNM_C2S_DELETE_USER_REQUEST,
	eNM_S2C_DELETE_USER_RESULT,
	eNM_C2S_UPDATE_USER_REQUEST,
	eNM_C2S_UPDATE_USER_RESULT,
	eNM_C2S_UPDATE_USER_OWN_MACHINE_REQUEST,
	eNM_C2S_UPDATE_USER_OWN_MACHINE_RESULT,
	eNM_C2S_DO_CODE_REPORT_REQUEST,//10
	eNM_S2C_DO_CODE_REPORT_RESULT,
	eNM_C2S_QUERY_MACHINE_HISTORY_REQUEST,
	eNM_S2C_QUERY_MACHINE_HISTORY_RESULT,
	eNM_MAX
};

enum eNetworkResultCode
{
	eNRC_OK = 0,
	eNRC_AUTHORITY_NOT_PERMIT,
	eNRC_USER_PWD_NOT_MATCH_ERROR,
	eNRC_MACHINE_EXISTS,
	eNRC_MACHINE_NOT_EXISTS,
	eNRC_REPORT_CODE_VERSION_NOT_MATCH,
	eNRC_REPORT_CODE_SOCKET_AND_ID_NOT_MATCH,
	eNRC_CURD_USER_EXISTS,
	eNRC_CURD_USER_NOT_EXISTS,
	eNRC_CURD_DB_FIND_ONE_ERROR,
	eNRC_CURD_DB_INSERT_ERROR,
	eNRC_CURD_DB_DELETE_ERROR,
	eNRC_CURD_DB_EXCEPTION,
	eNRC_CURD_DB_UPDATE_ERROR,
	eNRC_CURD_MAX
};

//tcpip 1 packet default maximum size is 65k

struct sBaseNetworkMessage
{
	int		iSize;
	int		iMessage;
	char	strID[USER_ID_LENGTH];
	sBaseNetworkMessage(int e_iID) :iMessage(e_iID) { memset(strID, 0, sizeof(strID)); }
};

struct sBaseNetworkResultMessage:public sBaseNetworkMessage
{
	int		iResultCode;//basicly 0 for false 1 for true
	sBaseNetworkResultMessage(int e_iID) :sBaseNetworkMessage(e_iID) {}
};
//=====================================
struct sLoginMessage_eNM_C2S_LOGIN_REQUEST :public sBaseNetworkMessage
{
	char	strPwd[USER_PWD_LENGTH];
	float	fVersion;
	MESSAGE_ID_ASSIGN(sLoginMessage_eNM_C2S_LOGIN_REQUEST, eNM_C2S_LOGIN_REQUEST);
};
enum eResult//for iResultCode
{
	eR_NO_USER = 0,
	eR_LOGIN_OK,
	eR_PWD_ERROR,
	eR_MAX
};
inline const char*GetResultString(eResult e_eResult)
{
	if (e_eResult == eR_NO_USER)
		return "ID not exist";
	if (e_eResult == eR_LOGIN_OK)
		return "Ok";
	if (e_eResult == eR_PWD_ERROR)
		return "Password is not correct";
	return "sLoginResultMessage_eNM_S2C_LOGIN_RESULT::GetResultString Error";
}
struct sLoginResultMessage_eNM_S2C_LOGIN_RESULT :public sBaseNetworkResultMessage
{
	//iResultCode,0 no such user,1 pw and user name correct,2 pwd is wrong
	int		iUserAuthority;
	int		iMachineIDArray[MAX_MACHINE_COUNT];//0 for empty
	RESULT_MESSAGE_ID_ASSIGN(sLoginResultMessage_eNM_S2C_LOGIN_RESULT, eNM_S2C_LOGIN_RESULT);
};

struct sAddUserMessage_eNM_C2S_ADD_USER_REQUEST :public sBaseNetworkMessage
{
	char	strTargetID[USER_ID_LENGTH];
	char	strPwd[USER_PWD_LENGTH];
	char	strDescription[USER_DESCRIPTION_LENGTH];
	MESSAGE_ID_ASSIGN(sAddUserMessage_eNM_C2S_ADD_USER_REQUEST, eNM_C2S_ADD_USER_REQUEST);
};

RESULT_STRUCT_ASSIGN(sAddUserMessage_eNM_C2S_ADD_USER_RESULT, eNM_C2S_UPDATE_USER_RESULT);

struct sDeleteUserMessage_eNM_C2S_DELETE_USER_REQUEST :public sBaseNetworkMessage
{
	char	strTargetID[USER_ID_LENGTH];
	char	strPwd[USER_PWD_LENGTH];//ASK pwd TO AVOID ACCIDENT.
	MESSAGE_ID_ASSIGN(sDeleteUserMessage_eNM_C2S_DELETE_USER_REQUEST, eNM_C2S_DELETE_USER_REQUEST);
};

RESULT_STRUCT_ASSIGN(sDeleteUserMessage_eNM_S2C_DELETE_USER_RESULT, eNM_S2C_DELETE_USER_RESULT);

struct sUpdateUserDataInfo_eNM_C2S_UPDATE_USER_REQUEST :public sBaseNetworkMessage
{
	char strTargetID[USER_ID_LENGTH];
	char strPWD[USER_PWD_LENGTH];
	char strNewPWD[USER_PWD_LENGTH];
	char strDescription[USER_DESCRIPTION_LENGTH];
	MESSAGE_ID_ASSIGN(sUpdateUserDataInfo_eNM_C2S_UPDATE_USER_REQUEST, eNM_C2S_UPDATE_USER_REQUEST);
};

RESULT_STRUCT_ASSIGN(sUpdateUserDataInfo_eNM_C2S_UPDATE_USER_RESULT, eNM_C2S_UPDATE_USER_RESULT);

struct sUpdateUserOwnMachine_eNM_C2S_UPDATE_USER_OWN_MACHINE_REQUEST :public sBaseNetworkMessage
{
	char	strTargetID[USER_ID_LENGTH];
	bool	bAddNewMachine;//true for add false or delete
	int		iMachineID;
	MESSAGE_ID_ASSIGN(sUpdateUserOwnMachine_eNM_C2S_UPDATE_USER_OWN_MACHINE_REQUEST, eNM_C2S_UPDATE_USER_OWN_MACHINE_REQUEST);
};

RESULT_STRUCT_ASSIGN(sUpdateUserDataInfo_eNM_C2S_UPDATE_USER_OWN_MACHINE_RESULT, eNM_C2S_UPDATE_USER_OWN_MACHINE_RESULT);

struct sNetworkworkTwLeadStreamProductData//from fish -FishGameParameterize-FISG_GAME_PARAMETERIZE::sTwLeadStreamProductData
{
	int		iProductTypeNumber = 0;
	int		iMachineID = 0;
};
//bool	GenerateReportCode(char*e_strReportCodeOutData, uint64 e_i64ExchangeIn, uint64 e_i64ExchangeOut, uint64 e_iBulletCount, int e_iReportCount, sTwLeadStreamProductData e_sTwLeadStreamProductData);
struct sCodeReportRequest_eNM_C2S_DO_CODE_REPORT_REQUEST :public sBaseNetworkMessage
{
	uint64	i64ExchangeIn;
	uint64  i64ExchangeOut;
	int		iReportCount;
	uint64  i64BulletCount;
	char	ReportCodeVersion[10];
	char	ParameterCode[50];
	sNetworkworkTwLeadStreamProductData TwLeadStreamProductData;
	MESSAGE_ID_ASSIGN(sCodeReportRequest_eNM_C2S_DO_CODE_REPORT_REQUEST, eNM_C2S_DO_CODE_REPORT_REQUEST);
};

struct sCodeReportResult_eNM_S2C_DO_CODE_REPORT_RESULT :public sBaseNetworkResultMessage
{
	char	strReportCodeResult[50];
	RESULT_MESSAGE_ID_ASSIGN(sCodeReportResult_eNM_S2C_DO_CODE_REPORT_RESULT, eNM_S2C_DO_CODE_REPORT_RESULT);
};

struct sQueryUserMachineHistory_eNM_C2S_QUERY_MACHINE_HISTORY_REQUEST :public sBaseNetworkMessage
{
	int	iMachineID;
	MESSAGE_ID_ASSIGN(sQueryUserMachineHistory_eNM_C2S_QUERY_MACHINE_HISTORY_REQUEST, eNM_C2S_QUERY_MACHINE_HISTORY_REQUEST);
};

#define	MACHINE_REPORT_INFO_REQUEST_HISTORY_COUNT	20
//because its possible record count too large so give result for serval times.
//
static const char*	g_cNetworkReportCodeVersion = "1.3";// FISG_GAME_PARAMETERIZE::g_strFishGameParameterizeVersion;//1.3 April/29/2019.
	//const char*	cReportCodeVersion = "1.3";
struct sNetworkworkReportInfoWithReportCodes
{
	int		iReportCount;
	int		iProductTypeNumber;
	int		iMachineID;
	int64	i64ExchangeIn;
	int64	i64ExchangeOut;
	int64	i64BulletShootCount;
	int64	i64BetMoney;				// This Total
	int64	i64WinMoney;				// This Total
	int64	i64BulletTotalShootCount;   // This Total
	int64  	i64OVERCount;
	int64	i64OVERScore;
	int64	i64GameWater;
	char	strReportCode[50];
	sNetworkworkReportInfoWithReportCodes()
	{
		memset(this, 0, sizeof(sNetworkworkReportInfoWithReportCodes));
	}
};
struct sQueryUserMachineHistory_eNM_S2C_QUERY_MACHINE_HISTORY_RESULT :public sBaseNetworkResultMessage
{
	int										iRecoredCount = 0;//if -1 retult is failed
	bool									bNextDataExists = false;
	int										iRecordStartIndex;
	int										iRecordCount;
	sNetworkworkReportInfoWithReportCodes	ReportInfoArray[MACHINE_REPORT_INFO_REQUEST_HISTORY_COUNT];
	RESULT_MESSAGE_ID_ASSIGN(sQueryUserMachineHistory_eNM_S2C_QUERY_MACHINE_HISTORY_RESULT, eNM_S2C_QUERY_MACHINE_HISTORY_RESULT);
};