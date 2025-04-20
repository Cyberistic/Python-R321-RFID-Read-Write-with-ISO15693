#ifndef _HFREADER_SERIAL_
#define _HFREADER_SERIAL_

#include "windows.h"
#include <stdio.h>
#include <time.h>

typedef unsigned short USHORT;
typedef unsigned char UCHAR;
typedef unsigned int UINT;

#define DEVICE_SERIAL_NUM		256
extern HANDLE g_aUartHandle[DEVICE_SERIAL_NUM];
extern HANDLE g_aUsbHandle[DEVICE_SERIAL_NUM];
extern HANDLE g_aSocketHandle[DEVICE_SERIAL_NUM];

extern UINT g_nSerialTime;

#define HFREADER_FRAME_HEAD1				0x7E
#define HFREADER_FRAME_HEAD2				0x55

#define HFREADER_FRAME_POS_HEAD1			0
#define HFREADER_FRAME_POS_HEAD2			1
#define HFREADER_FRAME_POS_LEN				2
#define HFREADER_FRAME_POS_SRCAddr			3
#define HFREADER_FRAME_POS_DESTADDR			5
#define HFREADER_FRAME_POS_CMD				7
#define HFREADER_FRAME_POS_RFU				8
#define HFREADER_FRAME_POS_PAR				9

#define HFREADER_RFRAME_POS_HEAD1			0
#define HFREADER_RFRAME_POS_HEAD2			1
#define HFREADER_RFRAME_POS_LEN				2
#define HFREADER_RFRAME_POS_SRCADDR			3
#define HFREADER_RFRAME_POS_DESTADDR		5
#define HFREADER_RFRAME_POS_FLAG			7
#define HFREADER_RFRAME_POS_CMD				8
#define HFREADER_RFRAME_POS_RFU				9
#define HFREADER_RFRAME_POS_PAR				10

#define HFREADER_FRAME_RESPONSE_FLAG		0x1F

#define HFREADER_FRAME_MIN_LEN				11
#define HFREADER_RFRAME_MIN_LEN				14

#define HFREADER_BUFFER_MAX					4096
#define HFREADER_FRAME_DATA_MAX_LEN			(HFREADER_BUFFER_MAX - 3)
#define HFREADER_FRAME_DATA_MIN_LEN			4
#define HFREADER_RFU						0x00

#define HFREADER_LBUFFER_MAX				HFREADER_BUFFER_MAX

#define HFREADER_UART_FLAG_RCV				0x80
#define HFREADER_UART_STAT_IDLE				0x00
#define HFREADER_UART_STAT_HEAD1			0x81
#define HFREADER_UART_STAT_HEAD2			0x82
#define HFREADER_UART_STAT_DATA				0x84
#define HFREADER_UART_STAT_TO				0x05
#define HFREADER_UART_STAT_END				0x06

////////////////////////////////////////////////////
#define BL_RFRAME_POS_HEAD1          0
#define BL_RFRAME_POS_HEAD2          1
#define BL_RFRAME_POS_LEN            2
#define BL_RFRAME_POS_SRCADDR        3
#define BL_RFRAME_POS_DESTADDR       5
#define BL_RFRAME_POS_CMD            8
#define BL_RFRAME_POS_RFU            9
#define BL_RFRAME_POS_PAR            10

#define BL_FRAME_POS_HEAD1          0
#define BL_FRAME_POS_HEAD2          1
#define BL_FRAME_POS_LEN            2
#define BL_FRAME_POS_SRCADDR        3
#define BL_FRAME_POS_DESTADDR       5
#define BL_FRAME_POS_CMD            7
#define BL_FRAME_POS_RFU            8
#define BL_FRAME_POS_PAR            9

#define BL_FRAME_MIN_LEN            11
#define BL_RFRAME_MIN_LEN           12

#define BL_FRAME_CMD_BOOT           1
#define BL_FRAME_CMD_DL             2
#define BL_FRAME_CMD_JMP            3
#define BL_FRAME_CMD_RESET          4
#define BL_FRAME_CMD_ERASE          5

#define BL_FRAME_RESPONSE_FLAG      0x1F

#define BL_FRAME_OP_OK              0
#define BL_FRAME_OP_FAIL            1

#define DEVICE_TICK_TIME			5
#define DEVICE_TICK_TIME2			50

#define BL_GetFrameLength(p)          (((p)[BL_RFRAME_POS_LEN]) + 3)
#define BL_GetFrameCrc(p, len)        (*((USHORT *)(p + len - 2)))

#define CP_FRAME_DATA_MAX_LEN               2048
#define CP_FRAME_BUF_MAX_LEN                (CP_FRAME_DATA_MAX_LEN + 255)
////////////////////////////////////////////////////////////////////////////////
typedef struct uartRcvFrame {
	UCHAR state;
	UINT index;
	UINT len;
	UCHAR buffer[HFREADER_LBUFFER_MAX];
}HFREADER_RCVFRAME;
void receiveAllTypeFrameByte(HFREADER_RCVFRAME *pRcvFrame, UCHAR byte);
int waitReaderResponse(HANDLE h, UCHAR *pBuffer, UCHAR cmd, int timeout);
void receiveByte(HFREADER_RCVFRAME *pRcvFrame, UCHAR byte);
USHORT calCrc(UCHAR *pFrame, int len);
BOOL findReaderFrame(UCHAR *pBuffer, int len, int *pStartPos);

#define getFrameLength(p)				(((p)[HFREADER_FRAME_POS_LEN]) + 3)
USHORT getFrameCrc(UCHAR *p, int len);
USHORT getSrcAddr(UCHAR *p);
USHORT getTargetAddr(UCHAR *p);
int getFrameAndRfu(USHORT srcAddr, USHORT targetAddr, UCHAR cmd, BOOL bRspFrame, UCHAR *pParam, UINT len, UCHAR rfu, UCHAR *pFrame);
int getFrame(USHORT srcAddr, USHORT targetAddr, UCHAR cmd, BOOL bRspFrame, UCHAR *pParam, UINT len, UCHAR *pFrame);
int getLongFrame(USHORT srcAddr, USHORT targetAddr, UCHAR cmd, BOOL bRspFrame, UCHAR *pParam, UINT len, UCHAR *pFrame);
int transceiveFrame(HANDLE h, DWORD txLen, UCHAR *pTxFrame, UCHAR *pRxFrame, int timeout);
int receiveFrame(HANDLE h, UCHAR *pRxFrame);
int transFrame(HANDLE h, DWORD txLen, UCHAR *pTxFrame);

void receiveLongFrameByte(HFREADER_RCVFRAME *pRcvFrame, UCHAR byte);
int waitReaderUartLongResponse(HANDLE h, UCHAR *pBuffer, UCHAR cmd, int timeout);
int transceiveLongFrame(HANDLE h, DWORD txLen, UCHAR *pTxFrame, UCHAR *pRxFrame, int timeout);
BOOL WriteUsbFrame(HANDLE h, DWORD txLen, UCHAR *pTxFrame);

BOOL WriteSocketFrame(HANDLE h, DWORD txLen, UCHAR *pTxFrame);
int ReceiveSocketFrame(HANDLE h, DWORD txLen, UCHAR *pRxFrame);

#define DEVICE_USBRX_MAX_LEN		65

#define DEVICE_SERIAL_TYPE_NULL		0
#define DEVICE_SERIAL_TYPE_UART		1
#define DEVICE_SERIAL_TYPE_USB		2
#define DEVICE_SERIAL_TYPE_SOCKET	3
int getSerialType(HANDLE h);
void addUartHandle(HANDLE h);
void delUartHandle(HANDLE h);
void addUsbHandle(HANDLE h);
void delUsbHandle(HANDLE h);
void addSocketHandle(HANDLE h);
void delSocketHandle(HANDLE h);

extern FILE *g_pFileLog;
extern BOOL g_bWriteLogFile;
void LOG(const char *fmt, ...);
void AppendLOG(const char *fmt, ...);
void LOGARRAY(char *strHeader, UCHAR *pFrame, int len);

/////////////////////////////////////////////////////////////////////
USHORT a_GetCrc(UCHAR *pFrame, USHORT len);
int BootWaitReaderResponse(HANDLE hSerial, UCHAR *pBuffer, int timeout, int tick, UCHAR cmd);
int BootFindDeviceFrame(UCHAR *pBuffer, int rcvLen, UCHAR cmd);
int InformationProcessing(HANDLE h, UCHAR *txBuffer, DWORD txLength, DWORD writeLength, int tick, UCHAR cmd, int iType, UCHAR checkMode, UINT size);
#endif