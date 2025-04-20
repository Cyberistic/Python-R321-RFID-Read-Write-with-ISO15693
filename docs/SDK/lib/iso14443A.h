#ifndef _HFREADER_ISO14443A_
#define _HFREADER_ISO14443A_

#include "Serial.h"
#include "hfReader.h"

#define HFREADER_ISO14443A_LEN_MAX_UID           10
#define HFREADER_ISO14443A_LEN_SIGNAL_UID        4
#define HFREADER_ISO14443A_LEN_DOUBLE_UID        7
#define HFREADER_ISO14443A_LEN_TRIPLE_UID        10
#define HFREADER_ISO14443A_LEN_M1_KEY            6
#define HFREADER_ISO14443A_LEN_M1BLOCK           16
#define HFREADER_ISO14443A_LEN_M1VALUE           4
#define HFREADER_ISO14443A_LEN_M1SECTOR          4
#define HFREADER_ISO14443A_LEN_M0KEY             4
#define HFREADER_ISO14443A_LEN_M0PCK             2
#define HFREADER_ISO14443A_LEN_M0BLOCK           4
#define HFREADER_ISO14443A_LEN_M0CNT             4
#define HFREADER_ISO14443A_LEN_M0SIG		     32

#define HFREADER_ISO14443A_M0U2KEY_LEN				16
#define HFREADER_ISO14443A_TOPAZ_BLOCK_LEN           8
#define HFREADER_ISO14443A_TOPAZ_UID_LEN             7


#define HFREADER_ISO14443A_UID_MAX_NUM				15
#define HFREADER_ISO14443A_MOBLOCKNUM_MAX			52
#define HFREADER_ISO14443A_M1BLOCKNUM_MAX			13
#define HFREADER_ISO14443A_TOPAZBLOCKNUM_MAX		26  //8BYTE/BLOCK

#define HFREADER_ISO14443A_KEY_A				0x60   //AUTHENT A command
#define HFREADER_ISO14443A_KEY_B				0x61   //AUTHENT B command

#define HFREADER_ISO14443A_VALUE_INCREMENT		0xC1   //INCREMENT command
#define HFREADER_ISO14443A_VALUE_DECREMENT		0xC0   //DECREMENT command
#define HFREADER_ISO14443A_VALUE_RESTORE		0xC2   //RESTORE command

#define HFREADER_ISO14443A_CMD_ACTIVE_SUID      0x15 
#define HFREADER_ISO14443A_CMD_READ_UID         0x16 

#define HFREADER_ISO14443A_CMD_AUTHRB			0x70 
#define HFREADER_ISO14443A_CMD_AUTHWB           0x71 
#define HFREADER_ISO14443A_CMD_AUTHRV           0x72 
#define HFREADER_ISO14443A_CMD_AUTHWV           0x73 
#define HFREADER_ISO14443A_CMD_AUTHV            0x74 
#define HFREADER_ISO14443A_CMD_RM0BLOCK         0x75
#define HFREADER_ISO14443A_CMD_WM0BLOCK         0x76
#define HFREADER_ISO14443A_CMD_RATS             0x77
#define HFREADER_ISO14443A_CMD_PCTRLESAM        0x78        //ESAM¿ØÖÆ
#define HFREADER_ISO14443A_CMD_APDU             0x7A
#define HFREADER_ISO14443A_CMD_HALT             0x7B
#define HFREADER_ISO14443A_CMD_DESEL            0x7C
#define HFREADER_ISO14443A_CMD_DTU              0x7F

#define HFREADER_ISO14443A_CMD_IMSTAT     		0x8E
#define HFREADER_ISO14443A_CMD_IMOP     		0x8F


#define HFREADER_ISO14443A_CMD_AUTHM0U2					0X80
#define HFREADER_ISO14443A_CMD_RTOPAZBLK				0x81
#define HFREADER_ISO14443A_CMD_WTOPAZBLK				0x82

//?¡ê?a¡À¨º??NFCType2
#define HFREADER_EMUL_T2_GET_UID                0xB0
#define HFREADER_EMUL_T2_SET_UID                0xB1
#define HFREADER_EMUL_T2_RBLOCK                 0xB2
#define HFREADER_EMUL_T2_WBLOCK                 0xB3

#define HFREADER_ISO14443A_TIMEOUT				500
typedef struct iso14443aUid{
    UINT type;
    UINT len;   
	UINT sak;
    UCHAR uid[HFREADER_ISO14443A_LEN_MAX_UID]; 
}ISO14443A_UID;
#define HFREADER_ISO14443A_SIZE_UID				14			

typedef struct iso14443aUidParam{
	HFREADER_OPRESULT result;
	ISO14443A_UID uid[HFREADER_ISO14443A_UID_MAX_NUM];
	UINT remainNum;
	UINT num;
}ISO14443A_UIDPARAM;

typedef struct iso14443ABlockParam{
	HFREADER_OPRESULT result;
	ISO14443A_UID uid;
	UINT keyType;
	UCHAR key[HFREADER_ISO14443A_LEN_M1_KEY];
	UCHAR block[HFREADER_ISO14443A_M1BLOCKNUM_MAX * HFREADER_ISO14443A_LEN_M1BLOCK];
	UINT addr;
	UINT num;
}ISO14443A_BLOCKPARAM;



typedef struct iso14443AImOpParam{
	HFREADER_OPRESULT result;
	ISO14443A_UID uid;
	UINT antNum;
	UINT antWorkTime;
	UINT opMode;
	UINT opTimeout;
	UINT blockAddr;
	UINT blockNum;
	UCHAR block[1024];
}ISO14443A_IMPARAM;


typedef struct iso14443AImOpInfo{
	int opMode;
	int blockIndex;
	int uidLen;
	int tempr;
	int paTempr;
	int noise;
	int signal;
	int sofLv;
	int antIndex;
}ISO14443A_IMINFO;

typedef struct iso14443AValueParam{
    HFREADER_OPRESULT result;
	ISO14443A_UID uid;
	UINT keyType;
	UCHAR key[HFREADER_ISO14443A_LEN_M1_KEY];
	UINT opCode;
	UINT blockAddr;
	UINT transAddr;
	int value;
}ISO14443A_VALUEPARAM;

typedef struct iso14443AOperationParam{
    HFREADER_OPRESULT result;
	ISO14443A_UID uid;
	UINT keyType;
	UCHAR key[HFREADER_ISO14443A_LEN_M1_KEY];
	UCHAR txFrame[HFREADER_BUFFER_MAX];
	UINT txLen;
	UCHAR rxFrame[HFREADER_BUFFER_MAX];
	UINT rxLen;
}ISO14443A_OPPARAM;

typedef struct iso14443ADtuParam{
    HFREADER_OPRESULT result;
	ISO14443A_UID uid;
	UINT txBit;
    UINT txLen;
    UCHAR txFrame[HFREADER_BUFFER_MAX];
	UINT rxBit;
    UINT rxLen;
    UCHAR rxFrame[HFREADER_BUFFER_MAX];
	UINT timeout;
}ISO14443A_DTU;

int WINAPI iso14443AGetUID(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR mode, ISO14443A_UIDPARAM *pUid, UCHAR *pTxFrame, UCHAR *pRxFrame);

int WINAPI iso14443AAuthReadM1Block(HANDLE h, USHORT srcAddr, USHORT targetAddr, ISO14443A_BLOCKPARAM *pBlock, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso14443AAuthWriteM1Block(HANDLE h, USHORT srcAddr, USHORT targetAddr, ISO14443A_BLOCKPARAM *pBlock, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso14443AAuthReadM1Value(HANDLE h, USHORT srcAddr, USHORT targetAddr, ISO14443A_VALUEPARAM *pValue, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso14443AAuthWriteM1Value(HANDLE h, USHORT srcAddr, USHORT targetAddr, ISO14443A_VALUEPARAM *pValue, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso14443AAuthOpM1Value(HANDLE h, USHORT srcAddr, USHORT targetAddr, ISO14443A_VALUEPARAM *pValue, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso14443AReadM0Block(HANDLE h, USHORT srcAddr, USHORT targetAddr, ISO14443A_BLOCKPARAM *pBlock, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso14443AWriteM0Block(HANDLE h, USHORT srcAddr, USHORT targetAddr, ISO14443A_BLOCKPARAM *pBlock, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso14443ARats(HANDLE h, USHORT srcAddr, USHORT targetAddr, ISO14443A_OPPARAM *pOpInfo, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso14443ACtrlEsam(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR index, UCHAR state, ISO14443A_OPPARAM *pOpInfo, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso14443AApdu(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR index, ISO14443A_OPPARAM *pOpInfo, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso14443AHalt(HANDLE h, USHORT srcAddr, USHORT targetAddr, ISO14443A_OPPARAM *pOpInfo, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso14443ADsel(HANDLE h, USHORT srcAddr, USHORT targetAddr, ISO14443A_OPPARAM *pOpInfo, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso14443ADtu(HANDLE h, USHORT srcAddr, USHORT targetAddr, ISO14443A_DTU *pDtu, UCHAR *pTxFrame, UCHAR *pRxFrame);

int WINAPI iso14443AReadM0Cnt(HANDLE h, USHORT srcAddr, USHORT targetAddr, ISO14443A_OPPARAM *pOpInfo, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso14443AReadM0Sig(HANDLE h, USHORT srcAddr, USHORT targetAddr, ISO14443A_OPPARAM *pOpInfo, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso14443AAuthM0(HANDLE h, USHORT srcAddr, USHORT targetAddr, ISO14443A_OPPARAM *pOpInfo, UCHAR *pTxFrame, UCHAR *pRxFrame);

int WINAPI iso14443AAuthUltralightC(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR *pKey, HFREADER_OPRESULT *pResult, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso14443AReadTopazBlock(HANDLE h, USHORT srcAddr, USHORT targetAddr, ISO14443A_BLOCKPARAM *pBlock, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI iso14443AWriteTopazBlock(HANDLE h, USHORT srcAddr, USHORT targetAddr, ISO14443A_BLOCKPARAM *pBlock, UCHAR *pTxFrame, UCHAR *pRxFrame);

typedef void(CALLBACK *iso14443aImDeviceInfo)(ISO14443A_IMINFO *pInfo);
int WINAPI iso14443AImOperation(HANDLE h, USHORT srcAddr, USHORT targetAddr, ISO14443A_IMPARAM *pIm, iso14443aImDeviceInfo deviceInfo, UCHAR *pTxFrame, UCHAR *pRxFrame);

int WINAPI emulNfcType2SetUID(HANDLE h, USHORT srcAddr, USHORT targetAddr, ISO14443A_UID *pUid, HFREADER_OPRESULT *pResult, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI emulNfcType2GetUID(HANDLE h, USHORT srcAddr, USHORT targetAddr, ISO14443A_UID *pUid, HFREADER_OPRESULT *pResult, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI emulNfcType2ReadBlock(HANDLE h, USHORT srcAddr, USHORT targetAddr, ISO14443A_BLOCKPARAM *pBlock, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI emulNfcType2WriteBlock(HANDLE h, USHORT srcAddr, USHORT targetAddr, ISO14443A_BLOCKPARAM *pBlock, UCHAR *pTxFrame, UCHAR *pRxFrame);
#endif
