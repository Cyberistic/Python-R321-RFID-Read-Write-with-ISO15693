#ifndef _HFREADER_NFC_
#define _HFREADER_NFC_
#include "Serial.h"
#include "iso14443A.h"
#include "iso15693.h"
#include "iso14443B.h"
#include "felica.h"

#define HFREADER_NFC_CMD_ACTIVE_SCANTAG	0x1B 
#define HFREADER_NFC_CMD_SCANTAG		0x1C 

#define HFREADER_NFC_UID_MAX_LEN		16
#define HFREADER_NFC_INFO_MAX_LEN		16

int WINAPI nfcGetTagType(HANDLE h, USHORT srcAddr, USHORT targetAddr, UCHAR *pType, UCHAR *pUidLen, UCHAR *pUid, UCHAR *pTagInfo, UCHAR *pTxFrame, UCHAR *pRxFrame);

#endif