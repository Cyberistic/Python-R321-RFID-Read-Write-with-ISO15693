#ifndef _HFREADER_HFREADER_
#define _HFREADER_HFREADER_
#include "Serial.h"

#pragma pack(push)//保存对齐状态
#pragma pack(4)//设定为4字节对齐

typedef struct hfReaderOpResult {
	UINT srcAddr;
	UINT targetAddr;
	UINT flag;
	UINT errType;
	UINT t;
}HFREADER_OPRESULT;

typedef struct hfReaderImInfo {
	int department;
	int devieId;

	int antNum;
	int antWorkTime;
	int opMode;
	int opTimeout;
	int blockAddr;
	int blockNum;
	UCHAR block[1024];
}HFREADER_IM;

typedef struct hfReaderFrame {
	UINT txLen;
	UCHAR txFrame[HFREADER_LBUFFER_MAX];
	UINT rxLen;
	UCHAR rxFrame[HFREADER_LBUFFER_MAX];
}HFREADER_FRAME;
/*
typedef struct hfReaderLongFrame{
	UINT txLen;
	UCHAR txFrame[HFREADER_LBUFFER_MAX];
	UINT rxLen;
	UCHAR rxFrame[HFREADER_LBUFFER_MAX];
}HFREADER_LFRAME;
*/
#define HFREADER_VERSION_SIZE		50
typedef struct hfReaderVersion {
	HFREADER_OPRESULT result;
	char type[HFREADER_VERSION_SIZE];
	char sv[HFREADER_VERSION_SIZE];
	char hv[HFREADER_VERSION_SIZE];
}HFREADER_VERSION;

typedef struct hfReaderConfig {
	HFREADER_OPRESULT result;
	UINT workMode;
	UINT readerAddr;
	UINT cmdMode;
	UINT afiCtrl;
	UINT uidSendMode;
	UINT tagStatus;
	UINT baudrate;
	UINT beepStatus;
	UINT afi;
}HFREADER_CONFIG;

typedef struct hfReaderIo {
	HFREADER_OPRESULT result;
	UINT out1State;
	UINT out1Frequent;
	UINT out1Cycle;
	UINT out2State;
	UINT out2Frequent;
	UINT out2Cycle;
	UINT relayState;
	UINT relayFrequent;
	UINT relayCycle;
	UINT in1;
	UINT in2;
	UINT in3;
	UINT in4;
}HFREADER_IO;

#define HFREADER_FRAME_MAX_NUM		64
typedef struct hfReaderActiveFrame {
	UINT num;
	UCHAR uid[HFREADER_FRAME_MAX_NUM][HFREADER_BUFFER_MAX];
	UCHAR frame[HFREADER_FRAME_MAX_NUM][HFREADER_BUFFER_MAX];
}HFREADER_ACTIVEFRAME;

typedef struct hfReaderDtuFrame {
	UCHAR cmd;
    UINT txLen;
    UCHAR txFrame[HFREADER_LBUFFER_MAX];	
	UINT rxLen;
    UCHAR rxFrame[HFREADER_LBUFFER_MAX];	
	UINT timeout;
}HFREADER_DTUFRAME;

#pragma pack(pop)//恢复对齐状态

#define HFREADER_FRAME_CMD_SET_CFG				0xF4
#define HFREADER_FRAME_CMD_GET_CFG				0xF5
#define HFREADER_FRAME_CMD_SET_VERSION			0xF6
#define HFREADER_FRAME_CMD_GET_VERSION			0xF7
#define HFREADER_FRAME_CMD_RF_CTRL				0xF0
#define HFREADER_FRAME_CMD_TRIGGLE_CTRL			0xF1
#define HFREADER_FRAME_CMD_SEL_ANT   			0xF2
#define HFREADER_FRAME_CMD_SET_IO				0xE9
#define HFREADER_FRAME_CMD_GET_IO				0xE6
#define HFREADER_FRAME_CMD_CFG_IO				0xEA

#define HFREADER_FRAME_CMD_SET_IM				0x08

#define HFREADER_FRAME_CMD_SET_PWR				0xFA

#define HFREADER_CFG_WM_EAS						1
#define HFREADER_CFG_WM_INVENTORY				2
#define HFREADER_CFG_WM_MASK                    0x0F
#define HFREADER_CFG_TYPE_ISO15693				0x00
#define HFREADER_CFG_TYPE_ISO14443A				0x10
#define HFREADER_CFG_TYPE_ISO14443B				0x20
#define HFREADER_CFG_TYPE_MASK					0xF0

#define HFREADER_CFG_BAUDRATE9600				5
#define HFREADER_CFG_BAUDRATE38400				7
#define HFREADER_CFG_BAUDRATE115200				11

#define HFREADER_CFG_TAG_QUIET					0
#define HFREADER_CFG_TAG_NOQUIET                1

#define HFREADER_CFG_UID_ACTIVE					0
#define HFREADER_CFG_UID_POSITIVE				1

#define HFREADER_CFG_AFI_DISABLE				0
#define HFREADER_CFG_AFI_ENABLE					1

#define HFREADER_CFG_INVENTORY_AUTO				0
#define HFREADER_CFG_INVENTORY_TRIGGER			1

#define HFREADER_CFG_QUERY_ENABLE				0
#define HFREADER_CFG_QUERY_DISABLE				1

#define HFREADER_CFG_BUZZER_ENABLE				1
#define HFREADER_CFG_BUZZER_DISABLE				0

#define HFREADER_RF_CLOSE						0
#define HFREADER_RF_OPEN                        1
#define HFREADER_RF_RESET						2

#define HFREADER_ANT_NUM						6
#define HFREADER_IO_NUM							8

#define HFREADER_READ_UID_NORMAL                0x00
#define HFREADER_READ_UID_REPEAT                0x01

#define HFREADER_TIMEOUT						500

HANDLE WINAPI hfReaderOpenPort(char *pPortName, char *pBaudrate);
int WINAPI hfReaderClosePort(HANDLE h);
HANDLE WINAPI hfReaderOpenUsb(DWORD vid, DWORD pid);
int WINAPI hfReaderScanUsbList(DWORD vid, DWORD pid, HANDLE *pHandleList);
int WINAPI hfReaderCloseUsb(HANDLE h);

HANDLE WINAPI hfReaderOpenSocket(char *pIP, DWORD iPort);
int WINAPI hfReaderCloseSocket(HANDLE h);

int WINAPI hfReaderSetIm(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR idleTime, USHORT to, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI hfReaderSetConfig(HANDLE h, USHORT srcAddr, USHORT targetAddr, HFREADER_CONFIG *pConfig, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI hfReaderGetConfig(HANDLE h, USHORT srcAddr, USHORT targetAddr, HFREADER_CONFIG *pConfig, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI hfReaderDefaultConfig(HANDLE h, USHORT srcAddr, USHORT targetAddr, HFREADER_CONFIG *pConfig, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI hfReaderCtrlRf(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR rfCtrl, HFREADER_OPRESULT *pResult, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI hfReaderTrigger(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR triggerCtrl, HFREADER_OPRESULT *pResult, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI hfReaderSetIo(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR *pOutState, HFREADER_OPRESULT *presult, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI hfReaderGetIo(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR *pInState, HFREADER_OPRESULT *pResult, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI hfReaderCfgIo(HANDLE h, USHORT srcAddr, USHORT targetAddr, HFREADER_IO *pIo, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI hfReaderReceive(HANDLE h, HFREADER_ACTIVEFRAME *pReceiveFrame);
int WINAPI hfReaderGetVersion(HANDLE h, USHORT srcAddr, USHORT targetAddr, HFREADER_VERSION *pVersion, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI hfReaderSetVersion(HANDLE h, USHORT srcAddr, USHORT targetAddr, HFREADER_VERSION *pVersion, UCHAR *pTxFrame, UCHAR *pRxFrame);

int WINAPI hfReaderSelectAnt(HANDLE h, USHORT srcAddr, USHORT targetAddr, int antNum, UCHAR *pAnt, HFREADER_OPRESULT *pResult, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI hfReaderSetPower(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR ant, UCHAR power, HFREADER_OPRESULT *pResult, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI hfReaderDtu(HANDLE h, USHORT srcAddr, USHORT targetAddr, HFREADER_DTUFRAME *pDtu, UCHAR *pTxFrame, UCHAR *pRxFrame, USHORT *rxLen, UCHAR *ppprxFrame);

int WINAPI hfReaderAnalyseFrame(UCHAR byte, HFREADER_RCVFRAME *pRcvFrame);
int WINAPI hfReaderFormatFrame(USHORT srcAddr, USHORT targetAddr, UCHAR cmd, UCHAR rspFrame, UCHAR longFrame, UCHAR *pParam, UINT len, UCHAR *pFrame);
int WINAPI hfReaderReceiveFrame(HANDLE h, UCHAR *pBuffer, int timeout);
int WINAPI hfReaderTransFrame(HANDLE h, UCHAR *pFrame, UINT len);
int WINAPI hfReaderReceiveBytes(HANDLE h, UCHAR *pBuffer, int timeout);

int WINAPI hfReaderSetImParams(HANDLE h, USHORT srcAddr, USHORT targetAddr, HFREADER_IM *pIm, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI hfReaderGetImParams(HANDLE h, USHORT srcAddr, USHORT targetAddr, HFREADER_IM *pIm, UCHAR *pTxFrame, UCHAR *pRxFrame);
#endif