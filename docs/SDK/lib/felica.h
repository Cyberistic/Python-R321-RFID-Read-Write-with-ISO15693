#ifndef _HFREADER_FELICA_
#define _HFREADER_FELICA_

#include "Serial.h"
#include "hfReader.h"

#define HFREADER_FELICA_UID_MAX_NUM			10
#define HFREAADER_FELICA_UID_LEN					16
#define HFREAADER_FELICA_BLOCK_LEN					16 

typedef struct felicaUidParam{
	HFREADER_OPRESULT result;
	UCHAR uid[HFREADER_FELICA_UID_MAX_NUM * HFREAADER_FELICA_UID_LEN];
	UINT remainNum;
	UINT num;
}FELICA_UIDPARAM;

typedef struct felicaDtuParam{
    HFREADER_OPRESULT result;
    UINT txLen;
    UCHAR txFrame[HFREADER_BUFFER_MAX];
    UINT rxLen;
    UCHAR rxFrame[HFREADER_BUFFER_MAX];
	UINT timeout;
}FELICA_DTU;

//felica
#define HFREAADER_FELICA_CMD_ACTIVE_SUID         0x17
#define HFREAADER_FELICA_CMD_GET_UID             0x18
#define HFREAADER_FELICA_CMD_DTU                 0x9F

#define HFREADER_FELICA_TIMEOUT				500

int WINAPI felicaGetUID(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR mode, FELICA_UIDPARAM *pUid, UCHAR *pTxFrame, UCHAR *pRxFrame);
int WINAPI felicaDtu(HANDLE h, USHORT srcAddr, USHORT targetAddr, FELICA_DTU *pDtu, UCHAR *pTxFrame, UCHAR *pRxFrame);


#endif
