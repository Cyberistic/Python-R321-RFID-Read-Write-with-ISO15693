#ifndef _HFREADER_ISO15693_
#define _HFREADER_ISO15693_

#include "Serial.h"
#include "hfReader.h"

#pragma pack(push)//保存对齐状态
#pragma pack(4)//设定为4字节对齐

#define HFREADER_ISO15693_MAX_BLOCK_NUM		32
#define HFREADER_ISO15693_MAX_UID_NUM		25

#define HFREADER_ISO15693_SIZE_BLOCK		4
#define HFREADER_ISO15693_SIZE_UID   		8

typedef struct iso15693BlockParam {
	HFREADER_OPRESULT result;
	UCHAR block[HFREADER_ISO15693_MAX_BLOCK_NUM][HFREADER_ISO15693_SIZE_BLOCK];
	UINT addr;
	UINT num;
}ISO15693_BLOCKPARAM;

typedef struct iso15693UidParam {
	HFREADER_OPRESULT result;
	UCHAR uid[HFREADER_ISO15693_MAX_UID_NUM][HFREADER_ISO15693_SIZE_UID];
	UINT remainNum;
	UINT num;
}ISO15693_UIDPARAM;

typedef struct iso15693TagInfoParam {
	HFREADER_OPRESULT result;
	UINT infoFlag;
	UINT dsfid;
	UINT afi;
	UINT blockNum;
	UINT blockSize;
	UINT ic;
}ISO15693_TAGPARAM;

typedef struct iso15693DtuParam {
	HFREADER_OPRESULT result;
	UINT txLen;
	UCHAR txFrame[HFREADER_BUFFER_MAX];
	UINT rxLen;
	UCHAR rxFrame[HFREADER_BUFFER_MAX];
	UINT timeout;
}ISO15693_DTU;

#define ISO15693_GATE_UID_NUM	256
typedef struct iso15693GateUidParam {
	UCHAR uid[ISO15693_GATE_UID_NUM * HFREADER_ISO15693_SIZE_UID];
	UINT rssi[ISO15693_GATE_UID_NUM];
	UINT ant;
	UINT num;
}ISO15693_GATEUIDPARAM;

#define HFREADER_ISO15693_CMD_ACTIVE_SUID		0x10
#define HFREADER_ISO15693_CMD_READ_UID			0x11
#define HFREADER_ISO15693_CMD_ACTIVE_EAS		0x13

#define HFREADER_ISO15693_CMD_READ_MBLOCK		0x22
#define HFREADER_ISO15693_CMD_WRITE_MBLOCK		0x23
#define HFREADER_ISO15693_CMD_LOCK_BLOCK		0x2C

#define HFREADER_ISO15693_CMD_WRITE_AFI			0x24
#define HFREADER_ISO15693_CMD_LOCK_AFI			0x25
#define HFREADER_ISO15693_CMD_WRITE_DSFID		0x26
#define HFREADER_ISO15693_CMD_LOCK_DSFID		0x27
#define HFREADER_ISO15693_CMD_READ_TAGINF		0x28
#define HFREADER_ISO15693_CMD_SET_EAS			0x29
#define HFREADER_ISO15693_CMD_RESET_EAS			0x2A
#define HFREADER_ISO15693_CMD_LOCK_EAS			0x2B
#define HFREADER_ISO15693_CMD_DIR_RBLOCK		0x2D
#define HFREADER_ISO15693_CMD_DTU   			0x2F

#define HFREADER_ISO15693_CMD_M24_RBLOCK		0xD7
#define HFREADER_ISO15693_CMD_M24_WBLOCK		0xD8

#define HFREADER_ISO15693_CMD_DIROPTAG			0x30
#define HFREADER_ISO15693_CMD_DIRWTAG			0x31
#define HFREADER_ISO15693_CMD_DIRWAFI			0x32
#define HFREADER_ISO15693_CMD_DIRRAFI			0x33
#define HFREADER_ISO15693_CMD_DIRW_NOUID        0x34

#define HFREADER_ISO15693_CMD_DIRRONE			0x50
#define HFREADER_ISO15693_CMD_DIRWONE_NOUID		0x54

#define HFREADER_ISO15693_CMD_MINILIB			0x41

#define HFREADER_ISO15693_CMD_SETSCANANTS		0xF8
#define HFREADER_ISO15693_CMD_ENABLE_GATE		0x0C
#define HFREADER_ISO15693_CMD_GATE_ALARM		0x40

#define HFREADER_ISO15693_CMD_IMOP  			0x3F
#define HFREADER_ISO15693_IM_BLOCK_NUM			8
#define HFREADER_ISO15693_IM_UID_NUM			256
#define HFREADER_ISO15693_IM_MODE_RUID			0x01
#define HFREADER_ISO15693_IM_MODE_RBLOCK		0x03
#define HFREADER_ISO15693_IM_SCAN_ANTS  		0xFF
#define HFREADER_ISO15693_IM_ANT_NUM			0xFF
typedef struct iso15693ImParam {
	HFREADER_OPRESULT result;
	UINT antNum;
	UCHAR antIndex[HFREADER_ISO15693_IM_ANT_NUM];
	UINT mode;
	UINT tagNum;
	UCHAR uid[HFREADER_ISO15693_IM_UID_NUM][HFREADER_ISO15693_SIZE_UID];
	UINT blockNum;
	UCHAR blockAddr[HFREADER_ISO15693_IM_BLOCK_NUM];
	UCHAR opBlockResult[HFREADER_ISO15693_IM_UID_NUM];
	UCHAR block[HFREADER_ISO15693_IM_UID_NUM][HFREADER_ISO15693_IM_BLOCK_NUM][HFREADER_ISO15693_SIZE_BLOCK];
	UINT timeout;
	UINT tagQuite;
}ISO15693_IMOP;

#define HFREADER_ISO15693_TIMEOUT               500

#pragma pack(pop)//恢复对齐状态

int WINAPI iso15693GetUid(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR mode, ISO15693_UIDPARAM *pUid, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso15693ReadBlock(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR *pUid, ISO15693_BLOCKPARAM *pReadBlock, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso15693M24ReadBlock(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR *pUid, ISO15693_BLOCKPARAM *pReadBlock, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso15693WriteBlock(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR *pUid, ISO15693_BLOCKPARAM *pWriteBlock, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso15693M24WriteBlock(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR *pUid, ISO15693_BLOCKPARAM *pWriteBlock, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso15693LockBlock(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR *pUid, UCHAR blockAddr, HFREADER_OPRESULT *pResult, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso15693WriteAfi(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR *pUid, UCHAR afi, HFREADER_OPRESULT *pResult, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso15693LockAfi(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR *pUid, HFREADER_OPRESULT *pResult, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso15693WriteDsfid(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR *pUid, UCHAR defid, HFREADER_OPRESULT *pResult, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso15693LockDsfid(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR *pUid, HFREADER_OPRESULT *pResult, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso15693ReadTagInfo(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR *pUid, ISO15693_TAGPARAM *pTagInfo, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso15693SetEas(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR *pUid, UCHAR cmd, HFREADER_OPRESULT *pResult, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso15693Dtu(HANDLE h, USHORT srcAddr, USHORT targetAddr, ISO15693_DTU *pDtu, UCHAR *pTxFrame, UCHAR *pRxFrame);

int WINAPI iso15693ReadDishTags(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR *pBlockAddr, UCHAR blockNum, UCHAR *pUid, UCHAR *pBlock, UCHAR waitTime, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso15693OpTagsRUidAndBlock(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR *pBlockAddr, UCHAR blockNum, UCHAR *pUid, UCHAR *pBlock, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso15693ImOp(HANDLE h, USHORT srcAddr, USHORT targetAddr, ISO15693_IMOP *pImOpParams, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso15693OpTagsWriteBlock(HANDLE h, USHORT srcAddr, USHORT targetAddr, USHORT tagRspTimeMin, USHORT tagRspTimeMax, UCHAR tagNum, UCHAR *pUid, UCHAR blockNum, UCHAR *pBlockAddr, UCHAR *pBlock, UCHAR *pResult, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso15693OpTagsWriteAfi(HANDLE h, USHORT srcAddr, USHORT targetAddr, USHORT tagRspTimeMin, USHORT tagRspTimeMax, UCHAR tagNum, UCHAR *pUid, UCHAR afi, UCHAR *pResult, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso15693OpTagsReadAfi(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR tagNum, UCHAR *pUid, UCHAR *pAfiValue, UCHAR *pResult, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso15693ScanLayerAnts(HANDLE h, USHORT srcAddr, USHORT targetAddr, int layerNum, ISO15693_IMOP *pImOpParams, UCHAR *pTxFrame, UCHAR *pRxFrame);

int WINAPI iso15693OpTagsRUidAndWBlock(HANDLE h, USHORT srcAddr, USHORT targetAddr, USHORT tagRspTimeMin, USHORT tagRspTimeMax, UCHAR *pTagNum, UCHAR *pUid, UCHAR blockNum, UCHAR *pBlockAddr, UCHAR *pBlock, UCHAR *pResult, UCHAR *pTxFrame, UCHAR *pRxFrame);

int WINAPI iso15693OpTagRUidAndBlock(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR *pBlockAddr, UCHAR blockNum, UCHAR *pUid, UCHAR *pBlock, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso15693OpTagRUidAndWBlock(HANDLE h, USHORT srcAddr, USHORT targetAddr, USHORT tagRspTimeMin, USHORT tagRspTimeMax, UCHAR *pTagNum, UCHAR *pUid, UCHAR blockNum, UCHAR *pBlockAddr, UCHAR *pBlock, UCHAR *pResult, UCHAR *pTxFrame, UCHAR *pRxFrame);


int WINAPI iso15693EnableGateMode(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR state, HFREADER_OPRESULT *pResult, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso15693SetScanAnts(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR ant, HFREADER_OPRESULT *pResult, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso15693GetGateAlarmUid(HANDLE h, USHORT srcAddr, USHORT targetAddr, ISO15693_GATEUIDPARAM *pGateTagInfo, UCHAR *pTxFrame, UCHAR *pRxFrame);
#endif