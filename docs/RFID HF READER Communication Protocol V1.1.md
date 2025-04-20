## Technical Documents

Technical Document Name： RFIDStation

Technical Document No：

Version： V1.1 Communication Protocol Description

## Table of Contents

4

8

12

24

45

| Chapter | 1 Communication protocols ......................................................................................      | 4                                                                                                              |
| ------- | --------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------- |
|         | 1.1 Request frame format ............................................................................................ | 4                                                                                                              |
|         | 1.2 Response frame format ..........................................................................................  | 5                                                                                                              |
|         | 1.3 Very long request frame format                                                                                    | ........................................................................ 6                                     |
|         | 1.4 Ultra-long response frame format                                                                                  | .................................................................... 7                                         |
| Chapter | 2 Command Sets                                                                                                        | ............................................................................................................ 8 |
|         | 2.1 System control command set                                                                                        | ................................................................................ 8                             |
|         | 2.2 ISO15693 label manipulation command set                                                                           | ....................................................... 9                                                      |
|         | 2.3 ISO14443A Tag manipulation command set                                                                            | ....................................................... 10                                                     |
|         | 2.4 ISO14443B Label Operation Command Set                                                                             | .......................................................... 11                                                  |
|         | 2.5 Felica tag manipulation command set                                                                               | ............................................................... 11                                             |
| Chapter | 3 System Control Command Frame Format                                                                                 | ............................................................. 12                                               |
|         | 3.1 Reset the system (0x04)                                                                                           | .................................................................................... 12                        |
|         | 3. 2 设 Setting the reader configuration parameters（ 0xF4 ）                                                         | ...................... 13                                                                                      |
|         | 3. 3 Getting the reader configuration parameters（ 0xF5 ）                                                            | ........................... 15                                                                                 |
|         | 3. 4 Radio frequency control（ 0xF0 ）                                                                                | ................................................................... 16                                         |
|         | 3. 5 Trigger control（ 0xF1 ）                                                                                        | ................................................................................... 17                         |
|         | 3. 6 Setting the output interface state（ 0xE9 ）                                                                     | ............................................. 18                                                               |
|         | 3. 7 Get input pin status（ 0xEA ） ........................................................................          | 19                                                                                                             |
|         | 3. 8 Antenna control（ 0xF2 ） ...................................................................................    | 20                                                                                                             |
|         | 3. 9 Get version（ 0xF7 ）                                                                                            | ........................................................................................... 21                 |
|         | 3. 10 Power control（ 0xFA ）                                                                                         | .........................................................................................22                    |
|         | 3. 11 Get CPUID number（ 0xF8 ） .............................................................................        | 23                                                                                                             |
| Chapter | 4 ISO15693 Label Operation Command Frame Format .........................................                             | 24                                                                                                             |
|         | 4.1 Tag into field（ 0x10 ）                                                                                          | ...................................................................................... 24                      |
|         | 4.2 Query in-field tag（ 0x11 ） ..............................................................................       | 25                                                                                                             |
|         | 4.3 EAS alarm output（ 0x13 ）                                                                                        | .................................................................................. 26                          |
|         | 4.4 Read multiple data blocks（ 0x22 ）                                                                               | ................................................................ 27                                            |
|         | 4.5 Writing multiple data blocks（ 0x23 ）                                                                            | .......................................................... 28                                                  |
|         | 4.6 Lock data block（ 0x2C ） ...................................................................................     | 29                                                                                                             |
|         | 4.7 Write AFI （ 0x24 ）                                                                                              | ................................................................................................ 30            |
|         | 4.8 Lock AFI （ 0x25 ）                                                                                               | .................................................................................................. 31          |
|         | 4.9 Write DSFID （ 0x26 ）                                                                                            | ........................................................................................... 32                 |
|         | 4.10 Lock DSFID （ 0x27 ）                                                                                            | ........................................................................................... 33                 |
|         | 4.11 Read tag system information（ 0x28 ）                                                                            | .......................................................... 34                                                  |
|         | 4.12 Pass-through（ 0x2F ）                                                                                           | ........................................................................................ 35                    |
|         | 4.13 Tag data block direct manipulation（ 0x30 ）                                                                     | ............................................ 37                                                                |
|         | 4.14 Intelligent manipulation of tags（ 0x3F ）                                                                       | ................................................ 39                                                            |
|         | 4.15 Label Data Block Direct Write Operation（ 0x31 ）                                                                | .................................. 41                                                                          |
| Chapter | 5 ISO14443A Label Operation Command Frame Format ........................................                             | 45                                                                                                             |
|         | 5.1 Tag Entry Field（ 0x15 ） ....................................................................................    | 45                                                                                                             |
|         | ） ..............................................................................                                     |                                                                                                                |
|         | 5.2 Query in-field tag（ 0x16                                                                                         | 46                                                                                                             |

63

67

69

|          | 5.3                                                                                                                   | Authorization to read M1 data block（ 0x70 ） .......................................... 47                       |
| -------- | --------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------- |
|          | 5.4 Authorisation to write M1 data                                                                                    | block（ 0x71 ） .......................................... 48                                                     |
|          | 5.5 Authorisation to read M1 value（                                                                                  | 0x72 ） ...................................................... 49                                                 |
|          | 5.6 Authorisation to write M1 value（ 0x73 ）                                                                         | .................................................... 50                                                           |
|          | 5.7 Authorisation to manipulate M1 value（ 0x74 ） ..........................................                         | 51                                                                                                                |
|          | 5.8 Read M0 data page （ 0x75 ）                                                                                      | .............................................................................. 52                                 |
|          | 5.9 Write M0 data page（ 0x76 ）                                                                                      | .............................................................................. 53                                 |
|          | 5.10 RATS （ 0x77 ）                                                                                                  | ...............................................................................................................54 |
|          | 5.11 Contact card (PSAM/ESAM) control（ 0x78 ） .............................................                         | 55                                                                                                                |
|          | 5.12 APDU （ 0x7A ）                                                                                                  | ..................................................................................................... 56          |
|          | 5.13 HANG UP （ 0x7B ）                                                                                               | ............................................................................................... 57                |
|          | 5.14 DESELECT （ 0x7C ）                                                                                              | ............................................................................................ 58                   |
|          | 5.15 TRANSMISSION（ 0x7F ）                                                                                           | ........................................................................................ 59                       |
|          | 5.16 Authorise UltralightC （ 0x80 ）                                                                                 | ........................................................................... 60                                    |
|          | 5.17 Read Topaz data block（ 0x81 ）                                                                                  | ....................................................................... 61                                        |
|          | 5.18 Write Topaz Data Block（ 0x82 ）                                                                                 | .................................................................... 62                                           |
| Chapter  | 6 ISO14443B Label Operation Command Frame Format .......................................                              | 63                                                                                                                |
|          | 6.1 Selecting a tag（ 0x1A ） ...................................................................................     | 63                                                                                                                |
|          | 6.2 Reading a Chinese ID tag UID （ 0xA0 ） .........................................................                 | 64                                                                                                                |
|          | 6.3 Pass-through（ 0xAF ） .........................................................................................  | 65                                                                                                                |
|          | 6.4 Hang up（ 0xAE ）                                                                                                 | .................................................................................................. 66             |
| Chapter  | 7 Felica tag manipulation command frame format ...........................................                            | 67                                                                                                                |
|          | 7.1 Get UID（ 0x18 ）                                                                                                 | ...................................................................................................... 67         |
|          | 7.2 Pass-through（ 0x9F ） .......................................................................................... | 68                                                                                                                |
| Appendix | A CRC16 Checksum C Program Code                                                                                       | ...................................................................... 69                                         |

## Chapter 1 Communication protocols

This protocol is the protocol specification for communication between the host and the reader.

- 1.1 Request frame format The request frame is sent by the device in the active position in the communication process, the active device can be a reader or a host, the interval between two request data frames should be not less than 50 milliseconds. Table 1.1 is the request frame format：

Table 1.1 Request frame format

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | N bytes    | 2bytes |

Note 1: The frame header indicates the start of a frame of data and has the value 0x7E55.

Note 2: The length is the number of bytes from the source address to the end of the CRC (including CRC). Note 3: The source address indicates the address of the device sending the data of this frame. Note 4: The destination address indicates the address of the device receiving the data of this frame. Note 5: The command code indicates the different communication behaviour.

Note 6: The reservation is fixed at 0x00.

Note 7: The parameter is the data carried by the command, the length and data varies with the different commands.

Note 8: CRC is a CRC check from the start of the frame length (including the frame length) to the end of the parameter area (including the parameter area), see Appendix A for the algorithm.

- 1.2 Response frame format The response frame is sent by the device in a passive position during the communication process, the passive device can be a reader or host, the response frame should be returned within 200 milliseconds of receiving the request frame (Note: the response frame return time for writing multiple data frames and reading multiple data frames is related to the number of data blocks). Table 1.2 shows the format of the response frame.

Table 1.2 Response frame format

| Frame headers | Length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters | CRC    |
| ------------- | ------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------- | ------ |
| 2bytes        | 1byte  | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | N bytes    | 2bytes |

Note 1: The frame header indicates the start of a frame of data and has the value 0x7E55.

Note 2: The length is the number of bytes from the source address to the end of the CRC (including CRC). Note 3: The source address indicates the address of the device sending the data of this frame.

Note 4: The destination address indicates the address of the device receiving the data of this frame.

- Note 5: The response frame flag indicates that the data of this frame is a response frame and is 0x1F. Note 6: The command code indicates the different communication behaviour.
- Note 7: The reservation is fixed at 0x00.
- Note 8: The parameter is the data carried by the command, the length and data varies with the different commands.
- Note 9: CRC is the CRC checksum from the start of the frame length (including frame length) to the end of the parameter area (including parameter area), see Appendix A for the algorithm.

## Note：

<!-- image -->

<!-- image -->

0x0000 is recommended for the host's device address. 0xFFFF is the broadcast address for communication. The factory device address of the reader is 0x0001.

## Note

：

Data items longer than one byte are transferred in the lower byte first mode.

- 1.3 The request frame is sent by the device in the active position during the communication process, the active device can be a reader or a host, and the interval between two request data frames should be not less than 50 ms. Table 1.3 is the request frame format：
- Note 1: The frame header indicates the start of a frame of data and has the value 0x7E55.
- Note 2: Length: 0x00.
- Note 3: The source address indicates the address of the device sending the data of this frame.
- Note 4: The destination address indicates the address of the device receiving the data of this frame. Note 5: The command code indicates the different communication behaviour.
- Note 6: The reservation is fixed at 0x00.
- Note 7: The parameter length indicates the length of the parameter data, up to 65535 bytes are supported.
- Note 8: The parameter is the data carried by the command, the length and data varies with different commands.
- Note 9: CRC is the CRC checksum from the start of the frame length (including frame length) to the end of the parameter area (including parameter area), see Appendix A for the specific algorithm.

Table 1.3 Request frame format

| Frame header | Frame length | Source address | Target address | Command Code | Reserved | Parameter length | Parameters | CRC    |
| ------------ | ------------ | -------------- | -------------- | ------------ | -------- | ---------------- | ---------- | ------ |
| 2bytes       | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 2bytes           | Nbytes     | 2bytes |

- 1.4 The response frame is sent by the device that is in a passive position during the communication process, the passive device can be a reader or host, the response frame should be returned within 200 milliseconds of receiving the request frame (Note: the response frame return time for writing multiple data frames and reading multiple data frames is related to the number of data blocks). Table 1.4 shows the format of the response frame.
- Note 1: The frame header indicates the start of a frame of data and has the value 0x7E55. Note 2: Length: 0x00.
- Note 3: The source address indicates the address of the device sending the data of this frame.
- Note 4: The destination address indicates the address of the device receiving the data of this frame.
- Note 5: The response frame flag indicates that the data of this frame is a response frame and is 0x1F. Note 6: The command code indicates the different communication behaviour.

Table 1.4 Response frame format

| Frame headers | Length | Source address | Target Address | Response frames Flags | Command Code | Reserved | Parameters Length | Parameters | CRC    |
| ------------- | ------ | -------------- | -------------- | --------------------- | ------------ | -------- | ----------------- | ---------- | ------ |
| 2bytes        | 1byte  | 2bytes         | 2bytes         | 1byte                 | 1byte        | 1byte    | 2bytes            | N bytes    | 2bytes |

Note 7: The reservation is fixed at 0x00.

- Note 8: The parameter length indicates the length of the parameter data, up to 65535 bytes are supported.
- Note 9: The parameter is the data carried by the command, the length and data varies with different commands.

Note 10: CRC is the CRC checksum from the start of the frame length (including frame length) to the end of the parameter area (including parameter area), see Appendix A for the specific algorithm.

## Chapter 2 Command Sets

- 2.1 System Control Commands The system control commands are responsible for managing reader operating parameters and controlling reader RF and IO：

Table 2.1 System control command set

| Command Code | Command Code |
| ------------ | ------------ |
|              | 0x04         |
|              | 0xE9         |
|              | 0xEA         |
|              | 0xF0         |
|              | 0xF1         |
|              | 0xF2         |
|              | 0xF4         |
|              | 0xF5         |
|              | 0xF7         |
|              | 0xF8         |
|              | 0xFA         |

## 2.2 ISO15693 label manipulation command set

The ISO15693 tag manipulation command set is responsible for manipulating the UID, data blocks and other parameters of the tag：

Table 2.2 ISO15693 Label Operation Command Set

| Command Code | Command Code | Description                          |
| ------------ | ------------ | ------------------------------------ |
| ISO15693     | 0x10         | Readers actively report UIDs         |
| ISO15693     | 0x11         | Read the tag UID                     |
| ISO15693     | 0x13         | EAS alarm output                     |
| ISO15693     | 0x22         | Read data blocks                     |
| ISO15693     | 0x23         | Write data block                     |
| ISO15693     | 0x24         | Write AFI                            |
| ISO15693     | 0x25         | Locking AFI                          |
| ISO15693     | 0x26         | Write DSFID                          |
| ISO15693     | 0x27         | Locking DSFID                        |
| ISO15693     | 0x28         | Read label information               |
| ISO15693     | 0x2C         | Locking data blocks                  |
| ISO15693     | 0x2F         | Pass-through tag manipulation frames |
| ISO15693     | 0x30         | Direct manipulation of label data    |

## 2.3 ISO14443A Tag manipulation command set

The ISO14443A tag manipulation command set is responsible for manipulating the UID, M1 data block, M0 data block, PSAM module and other parameters of the tag：

Table 2.3 ISO14443A Label Operation Command Set

| Command Code | Command Code | Description                               |
| ------------ | ------------ | ----------------------------------------- |
| ISO14443A    | 0x15         | Readers actively report UIDs              |
| ISO14443A    | 0x16         | Read ISO14443A tag UID                    |
| ISO14443A    | 0x70         | Authorised read data block (M1)           |
| ISO14443A    | 0x71         | Authorised write data block (M1)          |
| ISO14443A    | 0x72         | Authorised reading value (M1)             |
| ISO14443A    | 0x73         | Authorised write value (M1)               |
| ISO14443A    | 0x74         | Authorised operating value (M1)           |
| ISO14443A    | 0x75         | Read data block (M0)                      |
| ISO14443A    | 0x76         | Write data block (M0)                     |
| ISO14443A    | 0x77         | RATS                                      |
| ISO14443A    | 0x78         | Contact card control (PSAM)               |
| ISO14443A    | 0x7A         | Application Layer Command Delivery (APDU) |
| ISO14443A    | 0x7B         | Hang up the label                         |
| ISO14443A    | 0x7C         | DSEL labels                               |
| ISO14443A    | 0x7F         | Transparent transmission                  |
| ISO14443A    | 0x80         | Authorised UltralightC                    |
| ISO14443A    | 0x81         | Read Topaz label data blocks              |
| ISO14443A    | 0x82         | Write Topaz tag data blocks               |

## 2.4 ISO14443B Label Operation Command Set

The ISO14443B tag manipulation command set is responsible for manipulating tag selection and pass-through operations and the supported command sets are shown in Table 2.4 below：

Table 2.4 ISO14443B Label Operation Command Set Z

| Command Code | Command Code | Description              |
| ------------ | ------------ | ------------------------ |
| ISO14443B    | 0x1A         | Select Tag               |
| ISO14443B    | 0xA0         | Get China ID tag UID     |
| ISO14443B    | 0xAE         | Hang up the label        |
| ISO14443B    | 0xAF         | Transparent transmission |

## 2.5 Felica tag manipulation command set

The Felica tag manipulation command set is responsible for manipulating tag selection and pass-through operations and the supported command sets are shown in Table 2.5 below：

Table 2.5 Felica tag manipulation command set

| Command Code | Command Code | Description                        |
| ------------ | ------------ | ---------------------------------- |
| Felica       | 0x18         | Select the tag and get the tag UID |
| Felica       | 0x9F         | Transparent transmission           |

## Chapter 3 System Control Command Frame Format

- 3.1 Reset System (0x04) When the reader successfully receives this command frame, the reader returns a response frame and resets the system. The specific format of the frame is shown below：
-  Request frames (host requests)：
-  Response frame (reader response)：

Table 3.1 Reset system request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parame ters | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ----------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 0byte       | 2bytes |
| 0x7E55        | 0x08         |                |                | 0x04         | 0x00     |             |        |

Table 3.2 Reset system response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 0byte      | 2bytes |
| 0x7E55        | 0x09         |                |                | 0x1F                 | 0x04         | 0x00     |            |        |

- 3. 2 Set reader configuration parameters (0xF4) When the reader successfully receives this command frame, it updates the current system configuration parameters and writes the configuration parameters to the power-down non-volatile storage area within the device. If the serial port baud rate frame changes, the reader sends a response frame using the new baud rate. The format is shown below：
-  Request frames (host requests)：

Table 3.3 Setting the reader configuration parameters request frame

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters      | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 6bytes          | 2bytes |
| 0x7E55        | 0x0E         |                |                | 0xF4         | 0x00     | See Table 3.3.1 |        |

Table 3.3.1 Configuration parameters for the reader/writer

Table 3.3.2 Reader operating modes

| Working mode    | Reader address | Control words   | AFI   |
| --------------- | -------------- | --------------- | ----- |
| 1byte           | 2bytes         | 2bytes          | 1byte |
| See Table 3.3.2 |                | See Table 3.3.3 |       |

## Working mode

| 1byte  | 1byte     | 1byte                                      | 1byte                                      |
| ------ | --------- | ------------------------------------------ | ------------------------------------------ |
| Bit7-4 | Bit7-4    | Bit3-0（Valid only for ISO15693 protocol） | Bit3-0（Valid only for ISO15693 protocol） |
| 0      | ISO15693  | 1                                          | EAS                                        |
| 1      | ISO4443A  | 2                                          | Inventory                                  |
| 2      | ISO14443B | 2                                          | Inventory                                  |

Table 3.3.3 Reader control words

| 1byte                  | 1byte                  | 1byte                  | 1byte                  | 1byte                    | 1byte                    | 1byte                  | 1byte                  | 1byte     | 1byte     | 1byte    | 1byte  | 1byte       |
| ---------------------- | ---------------------- | ---------------------- | ---------------------- | ------------------------ | ------------------------ | ---------------------- | ---------------------- | --------- | --------- | -------- | ------ | ----------- |
| Bit7-4                 | Bit7-4                 | Bit7-4                 | Bit7-4                 | Bit7-4                   | Bit7-4                   | Bit7-4                 | Bit7-4                 | Bit3-0    | Bit3-0    | Bit 7-1  | Bit0   | Bit0        |
| Inventory mode control | Inventory mode control | Inventory mode control | Inventory mode control | Inventory mode control   | Inventory mode control   | Inventory mode control | Inventory mode control | Baud rate | Baud rate | Reserved | Buzzer | Buzzer      |
| Command method         | Command method         | AFI                    | AFI                    | UID Transfer Mode (Bit5) | UID Transfer Mode (Bit5) | Tags(Bit4)             | Tags(Bit4)             | 0101      | 9600      | 0        | 0      | Prohibition |
| (Bit7) 0               | Automatic              | 0                      | (Bit6) Prohibition     | 0                        | Proactive                | 0                      | Silence                | 0111      | 38400     | 0        | 1      | Enabling    |
| 1                      | Trigger                | 1                      | Enabling               | 1                        | Passive                  | 1                      | No silence             | 1011      | 115200    |          |        |             |

##  Response frames (reader response)：

Table 3.4 Setting the response frame for the reader configuration parameters

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Reserved | Parameters      | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | -------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 1byte    | 2bytes          | 2bytes |
| 0x7E55        | 0x0B         |                |                | 0x1F         | 0xF4     | 0x00     | See Table 3.4.1 |        |

Table 3.4.1 Setting the reader configuration parameters Response frame parameters

| Configuration flags | Configuration flags | Reserved |
| ------------------- | ------------------- | -------- |
| 1byte               | 1byte               | 1byte    |
| 0x00                | Success             | 0x00     |
| 0x01                | Failure             | 0x00     |

## 3. 3 Get the reader configuration parameters (0xF5)

-  Request frames (host requests)：

Table 3.5 Request frame for reader configuration parameters

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 1byte      | 2bytes |
| 0x7E55        | 0x09         |                |                | 0xF5         | 0x00     | 0x00       |        |

##  Response frames (reader response)：

Table 3.6 Getting the response frames for the reader configuration parameters

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters      | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 6bytes          | 2bytes |
| 0x7E55        | 0x0F         |                |                | 0x1F                 | 0xF5         | 0x00     | See Table 3.3.1 |        |

- 3. 4 RF control (0xF0) When the reader turns off the RF signal, the tag in the antenna field is in a power-down or reset state. The specific format is shown below：
-  Request frames (host requests)：
-  Response frame (reader response)：

Table 3.7 RF control request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters      | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 2bytes          | 2bytes |
| 0x7E55        | 0x0A         |                |                | 0xF0         | 0x00     | See Table 3.7.1 |        |

Table 3.7.1 RF control request frame parameters

| RF section control | RF section control                       | Reserved |
| ------------------ | ---------------------------------------- | -------- |
| 1byte              | 1byte                                    | 1byte    |
| 0x00               | Close                                    | 0x00     |
| 0x01               | Open                                     | 0x00     |
| 0x02               | Reset (turn RF off and then on for 20ms) | 0x00     |

Table 3.8 RF control response frames

| Frame headers | Frame length | Source address | Target address | Response frame | Command Code | Reser ved | Paramet ers     | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------- | ------------ | --------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | fl 1byte       | 1byte        | 1byte     | 2bytes          | 2bytes |
| 0x7E55        | 0x0B         |                |                | 0x1F           | 0xF0         | 0x00      | See Table 3.8.1 |        |

Table 3.8.1 RF control response frame parameters

| Configuration flags | Configuration flags | Reserved |
| ------------------- | ------------------- | -------- |
| 1byte               | 1byte               | 1byte    |
| 0x00                | Success             | 0x00     |
| 0x01                | Failure             | 0x00     |

## 3. 5 Trigger control (0xF1)

This command is only valid in the Inventory mode of ISO15693 and when the trigger mode is selected. The specific format is shown below：

##  Request frames (host requests)：

Table 3.9 Trigger control request frames

| Frame headers | Frame length | Source address | Target address | Comman d Code | Reser ved | Parameter s     | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------- | --------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte         | 1byte     | 2bytes          | 2bytes |
| 0x7E55        | 0x0A         |                |                | 0xF1          | 0x00      | See Table 3.9.1 |        |

Table 3.9.1 Trigger control request frame parameters

| Trigger control | Trigger control   | Reserved |
| --------------- | ----------------- | -------- |
| 1byte           | 1byte             | 1byte    |
| 0x00            | Invalid           | 0x00     |
| 0x01            | Trigger Inventory | 0x00     |

##  Response frame (reader response)：

Table 3.10 Trigger control response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 2bytes           | 2bytes |
| 0x7E55        | 0x0B         |                |                | 0x1F                 | 0xF1         | 0x00     | See Table 3.10.1 |        |

Table 3.10.1 Trigger control response frame parameters

| Configuration flags | Configuration flags | Reserved |
| ------------------- | ------------------- | -------- |
| 1byte               | 1byte               | 1byte    |
| 0x00                | Success             | 0x00     |
| 0x01                | Failure             | 0x00     |

- 3. 6 Set Output Pin Status (0xE9) This command allows the user to control the status of each output pin. For the number of OUT pins supported by the device (less than 200), please refer to the appropriate product manual. The specific format of the command is shown below：
-  Request frames (host requests)：

Table 3.11 Setting the output pin status request frame

| Frame headers | Frame length | Source addres | Target address | Command Code | Reser ved | Parameters       | CRC    |
| ------------- | ------------ | ------------- | -------------- | ------------ | --------- | ---------------- | ------ |
| 2bytes        | 1byte        | s 2bytes      | 2bytes         | 1byte        | 1byte     | Nbytes           | 2bytes |
| 0x7E55        | 0x08+N       |               |                | 0xE9         | 0x00      | See Table 3.11.1 |        |

Table 3.11.1 Setting the output pin status request frame parameters

| OUT1                                        | ... | OUTN                                        |
| ------------------------------------------- | --- | ------------------------------------------- |
| 1byte                                       | ... | 1byte                                       |
| 0：Low level 1：High level Other: unchanged | ... | 0：Low level 1：High level Other: unchanged |

##  Response frames (reader response)：

Table 3.12 Setting the output pin status response frame

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 2bytes           | 2bytes |
| 0x7E55        | 0x0B         |                |                | 0x1F                 | 0xE9         | 0x00     | See Table 3.12.1 |        |

Table 3.12.1 Setting the output pin status response frame parameters

| Configuration flags | Configuration flags | Reserved |
| ------------------- | ------------------- | -------- |
| 1byte               | 1byte               | 1byte    |
| 0x00                | Success             | 0x00     |
| 0x01                | Failure             | 0x00     |

- 3. 7 Get Input Pin Status (0xEA) This command allows the user to get the status of each input pin, the number of IN pins supported by the device (less than 200), please refer to the corresponding product manual. The specific format of the command is shown below：
-  Request frames (host requests)：
-  Response frames (reader response)：

Table 3.13 Get input pin status request frame

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 0byte      | 2bytes |
| 0x7E55        | 0x08         |                |                | 0xEA         | 0x00     |            |        |

Table 3.14 Get input pin status response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 2bytes           | 2bytes |
| 0x7E55        | 0x0B+N       |                |                | 0x1F                 | 0xEA         | 0x00     | See Table 3.14.1 |        |

Table 3.14.1 Get input pin response frame parameters

| Input Status                     | Configuration flags | Configuration flags | Reserved |
| -------------------------------- | ------------------- | ------------------- | -------- |
| N bytes                          | 1byte               | 1byte               | 1byte    |
| 0x00：Low level 0x01：High level | 0x00                | Success             | 0x00     |
| 0x00                             | 0x01                | Failure             | 0x00     |

- 3. 8 Antenna Control (0xF2) When multiple antennas are connected to the reader, the antenna can be switched by this command. If the reader has only one antenna, this command is invalid. The specific format is shown below：
-  Request frames (host requests)：
-  Response frames (reader response)：

Table 3.15 Antenna control request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 6bytes           | 2bytes |
| 0x7E55        | 0x0E         |                |                | 0xF2         | 0x00     | See Table 3.15.1 |        |

Table 3.15.1 Antenna control request frame parameters

| Ant1  | Ant1        | Ant2  | Ant2        | Ant3  | Ant3        | Ant4  | Ant4        | Ant5  | Ant5        | Ant6  | Ant6        |
| ----- | ----------- | ----- | ----------- | ----- | ----------- | ----- | ----------- | ----- | ----------- | ----- | ----------- |
| 1byte | 1byte       | 1byte | 1byte       | 1byte | 1byte       | 1byte | 1byte       | 1byte | 1byte       | 1byte | 1byte       |
| 1     | Enabling    | 1     | Enabling    | 1     | Enabling    | 1     | Enabling    | 1     | Enabling    | 1     | Enabling    |
| 0     | Prohibition | 0     | Prohibition | 0     | Prohibition | 0     | Prohibition | 0     | Prohibition | 0     | Prohibition |

Table 3.16 Antenna control response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 2bytes           | 2bytes |
| 0x7E55        | 0x0B         |                |                | 0x1F                 | 0xF2         | 0x00     | See Table 3.16.1 |        |

Table 3.16.1 Antenna control response frame parameters

| Logo  | Logo    | Reserved |
| ----- | ------- | -------- |
| 1byte | 1byte   | 1byte    |
| 0x00  | Success | 0x00     |
| 0x01  | Failure | 0x00     |

- 3. 9 Get Version (0xF7) Gets the device model, hardware and software version information. The exact format is shown below：
-  Request frames (host requests)：
-  Response frames (reader response)：

Table 3.17 Get version request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 0bytes     | 2bytes |
| 0x7E55        | 0x08         |                |                | 0xF7         | 0x00     |            |        |

Table 3.18 Get version response frames

| Frame heade | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ----------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes      | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 52bytes          | 2bytes |
| 0x7E55      | 0x3D         |                |                | 0x1F                 | 0xF7         | 0x00     | See Table 3.18.1 |        |

Table 3.18.1 Get version response frame parameters

| Version information | Logo  |         | Reserved |
| ------------------- | ----- | ------- | -------- |
| 50bytes             | 1byte | 1byte   | 1byte    |
| "Model SV HV"       | 0x00  | Success | 0x00     |
| "Model SV HV"       | 0x01  | Failure | 0x00     |

## 3. 10 Power control (0xFA)

The RF output level of each antenna can be controlled by this command. The format is shown below：

##  Request frames (host requests)：

Table 3.19 Power control request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 6bytes           | 2bytes |
| 0x7E55        | 0x0E         |                |                | 0xFA         | 0x00     | See Table 3.19.1 |        |

Table 3.29.1 Power control request frame parameters

| Ant1  | Ant1                   | Ant2  | Ant3  | Ant4  | Ant5  | Ant6  | Ant6                   |
| ----- | ---------------------- | ----- | ----- | ----- | ----- | ----- | ---------------------- |
| 1byte | 1byte                  | 1byte | 1byte | 1byte | 1byte | 1byte | 1byte                  |
| 0~3   | 0 Minimum output power | ……    | ……    | ……    | ……    | 0~3   | 0 Minimum output power |
| Other | Invalid                | ……    | ……    | ……    | ……    | Other | Invalid                |

##  Response frames (reader response)：

Table 3.20 Antenna control response frames

| Frame header | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters      | CRC    |
| ------------ | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | --------------- | ------ |
| 2bytes       | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 2bytes          | 2bytes |
| 0x7E55       | 0x0B         |                |                | 0x1F                 | 0xFA         | 0x00     | See Table3.20.1 |        |

Table 3.20.1 Power control response frame parameters

| Logo  | Logo    | Reserved |
| ----- | ------- | -------- |
| 1byte | 1byte   | 1byte    |
| 0x00  | Success | 0x00     |
| 0x01  | Failure | 0x00     |

## 3. 11 Get CPUID number (0xF8)

Gets the CPU unique ID number. The format is shown below：

##  Request frames (host requests)：

Table 3.21 Get ID number request frames

| Frame heade | Frame length | Source addres | Target address | Command Code | Reserved | Parameters | CRC    |
| ----------- | ------------ | ------------- | -------------- | ------------ | -------- | ---------- | ------ |
| 2bytes      | 1byte        | 2bytes        | 2bytes         | 1byte        | 1byte    | 0bytes     | 2bytes |
| 0x7E55      | 0x08         |               |                | 0xF8         | 0x00     |            |        |

##  Response frames (reader response)：

Table 3.22 Get ID number response frames

| Frame heade | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters      | CRC    |
| ----------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | --------------- | ------ |
| 2bytes      | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 14bytes         | 2bytes |
| 0x7E55      | 0x17         |                |                | 0x1F                 | 0xF8         | 0x00     | See Table3.22.1 |        |

Table 3.22.1 Get ID number response frame parameters

| ID number | Logo  | Error   | Code  |
| --------- | ----- | ------- | ----- |
| 12bytes   | 1byte | 1byte   | 1byte |
|           | 0x00  | Success |       |
|           | 0x01  | Failure |       |

## Chapter4 ISO15693 Label Operation Command Frame Format

## 4.1 Tag into the field (0x10)

When the reader is in UID active upload mode, if the reader successfully acquires the UID, it will actively upload the tag UID information. The format is shown below：

-  Request frames (reader requests)：

Table 4.1 Tag entry request frames in the field

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters      | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 11bytes         | 2bytes |
| 0x7E55        | 0x13         |                |                | 0x10         | 0x00     | See Table 4.1.1 |        |

Table 4.1.1 Parameters for tag entry request frames in the field

| Reserved | Tags UID         | Reserved |
| -------- | ---------------- | -------- |
| 1byte    | 8bytes           | 2bytes   |
| 0x00     | xxxxxxxxxxxxxxE0 | 0x0000   |

##  Response frames (host response)：

Table 4.2 Tag-in-field response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters      | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 2bytes          | 2bytes |
| 0x7E55        | 0x0B         |                |                | 0x1F                 | 0x10         | 0x00     | See Table 4.2.1 |        |

Table 4.2.1 Label entry response frame parameters in the field

| Configuration flags | Configuration flags | Reserved |
| ------------------- | ------------------- | -------- |
| 1byte               | 1byte               | 1byte    |
| 0x00                | Success             | 0x00     |
| 0x01                | Failure             | 0x00     |

## 4.2 Query field label (0x11)

When the reader is in UID passive upload mode, it responds to the request frame. The format is shown below：

##  Request frames (host requests)：

Table 4.3 Querying in-field tag request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reser ved | Paramet ers     | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | --------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte     | 1byte           | 2bytes |
| 0x7E55        | 0x09         |                |                | 0x11         | 0x00      | See Table 4.3.1 |        |

Table 4.3.1 Parameters for querying in-field tag request frames

## Mode

| 0x00 | Normal mode                                                                                                            |
| ---- | ---------------------------------------------------------------------------------------------------------------------- |
| 0x01 | Repeat mode (in the event of a communication error, this mode can ask the reader to resend the previous frame of data) |

##  Response frames (reader response)：

Table 4.4 Querying in-field tag response frames

| Frame header | Frame length | Source addres | Target address | Response frame flags | Command Code | Reserved | Parameters      | CRC    |
| ------------ | ------------ | ------------- | -------------- | -------------------- | ------------ | -------- | --------------- | ------ |
| 2bytes       | 1byte        | 2bytes        | 2bytes         | 1byte                | 1byte        | 1byte    | Nbytes          | 2bytes |
| 0x7E55       | 0x0B+9\*n    |               |                | 0x1F                 | 0x11         | 0x00     | See Table 4.4.1 |        |

Table 4.4.1 Parameters for querying in-field tag response frames

| UID      | UID      | UID      | UID      | UID      | UID      | UID      | Number of labels remaining | Reserved |
| -------- | -------- | -------- | -------- | -------- | -------- | -------- | -------------------------- | -------- |
| n×9bytes | n×9bytes | n×9bytes | n×9bytes | n×9bytes | n×9bytes | n×9bytes | 1byte                      | 1byte    |
| UID1     | 0xAA     | UID2     | 0xAA     | …        | UIDN     | 0xAA     |                            | 0x00     |

The value of n ranges from 0 to 25, and when there is no tag information, the UID area is 0 bytes, with each UID number followed by 0xAA.

## 4.3 EAS alarm output (0x13)

When the reader is in UID active EAS mode, if the reader successfully acquires EAS information, it will actively upload EAS alarm messages. The format is shown below：

##  Request frames (reader requests)：

Table 4.5 EAS alarm request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters      | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 11bytes         | 2bytes |
| 0x7E55        | 0x13         |                |                | 0x13         | 0x00     | See Table 4.5.1 |        |

Table 4.5.1 EAS alarm request frame parameters

| Reserved | Tags UID | Reserved |
| -------- | -------- | -------- |
| 1byte    | 8bytes   | 2bytes   |
| 0x00     |          | 0x0000   |

##  Response frames (host response)：

Table 4.6 EAS alarm response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters      | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 2bytes          | 2bytes |
| 0x7E55        | 0x0B         |                |                | 0x1F                 | 0x13         | 0x00     | See Table 4.6.1 |        |

Table 4.6.1 EAS alarm response frame parameters

| Configuration flags | Configuration flags | Reserved |
| ------------------- | ------------------- | -------- |
| 1byte               | 1byte               | 1byte    |
| 0x00                | Success             | 0x00     |
| 0x01                | Failure             | 0x00     |

## 4.4 Read multiple blocks of data（0x22）

##  Request frames (host requests)：

Table 4.7 Reading multiple data block request frames

| Frame headers | Frame lengt | Source address | Target address | Command Code | Reserved | Parameters      | CRC    |
| ------------- | ----------- | -------------- | -------------- | ------------ | -------- | --------------- | ------ |
| 2bytes        | 1byte       | 2bytes         | 2bytes         | 1byte        | 1byte    | 10bytes         | 2bytes |
| 0x7E55        | 0x12        |                |                | 0x22         | 0x00     | See Table 4.7.1 |        |

Table 4.7.1 Read multiple data block request frame parameters

| Tags UID         | Block Header Address | Number of blocks |
| ---------------- | -------------------- | ---------------- |
| 8bytes           | 1byte                | 1byte            |
| xxxxxxxxxxxxxxE0 |                      | N                |

##  esponse frames (reader response)：

Table 4.8 Reading multiple data block response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters      | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 2+4\*Nbytes     | 2bytes |
| 0x7E55        | 0x0B+4\*N    |                |                | 0x1F                 | 0x22         | 0x00     | See Table 4.8.1 |        |

Table 4.8.1 Read multiple data block response frame parameters

| Block data | Logo  | Logo    | Type of error | Type of error                      |
| ---------- | ----- | ------- | ------------- | ---------------------------------- |
| 4\*Nbytes  | 1byte | 1byte   | 1byte         | 1byte                              |
|            | 0x00  | Success | 0x00          | No errors                          |
|            | 0x01  | Failure | 0x01          | Label detected error               |
|            | 0x01  | Failure | 0x02          | CRC error for data returned by tag |
|            | 0x01  | Failure | 0x03          | Label not responding               |

The range of values for N is 0 to 32. Each data block occupies 4 bytes.

## 4.5 Write multiple blocks of data (0x23)

##  Request frames (host requests)：

Table 4.9 Writing multiple data block request frames

| Frame header | Frame length | Source address | Target address | Command Code | Reserved | Parameters      | CRC    |
| ------------ | ------------ | -------------- | -------------- | ------------ | -------- | --------------- | ------ |
| 2bytes       | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 10+4\*Nbytes    | 2bytes |
| 0x7E55       | 0x12+4\*N    |                |                | 0x23         | 0x00     | See Table 4.9.1 |        |

Table 4.9.1 Parameters for writing multiple data block request frames

| Tags UID         | Block Header Address | Number of blocks | Data      |
| ---------------- | -------------------- | ---------------- | --------- |
| 8bytes           | 1byte                | 1byte            | 4\*Nbytes |
| xxxxxxxxxxxxxxE0 |                      | N                |           |

##  Response frames (reader response)：

Table 4.10 Writing multiple data block response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 2bytes           | 2bytes |
| 0x7E55        | 0x0B         |                |                | 0x1F                 | 0x23         | 0x00     | See Table 4.10.1 |        |

Table 4.10.1 Parameters for writing multiple data block response frames

| Logo  | Logo    | Type of error | Type of error                      |
| ----- | ------- | ------------- | ---------------------------------- |
| 1byte | 1byte   | 1byte         | 1byte                              |
| 0x00  | Success | 0x00          | No errors                          |
| 0x01  | Failure | 0x01          | Label detected error               |
| 0x01  | Failure | 0x02          | CRC error for data returned by tag |
| 0x01  | Failure | 0x03          | Label not responding               |

The range of values for N is 0 to 32. Each data block occupies 4 bytes.

## 4.6 Locking data block (0x2C)

##  Request frames (host requests)：

Table 4.11 Locking data block request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 9bytes           | 2bytes |
| 0x7E55        | 0x11         |                |                | 0x2C         | 0x00     | See Table 4.11.1 |        |

Table 4.11.1 Locked data block request frame parameters

| Tags UID         | Block Header Address |
| ---------------- | -------------------- |
| 8bytes           | 1byte                |
| xxxxxxxxxxxxxxE0 |                      |

##  Response frames (reader response)：

Table 4.12 Locking data block response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 2bytes           | 2bytes |
| 0x7E55        | 0x0B         |                |                | 0x1F                 | 0x2C         | 0x00     | See Table 4.12.1 |        |

Table 4.12.1 Locked data block response frame parameters

| Logo  | Logo    | Type of error | Type of error                      |
| ----- | ------- | ------------- | ---------------------------------- |
| 1byte | 1byte   | 1byte         | 1byte                              |
| 0x00  | Success | 0x00          | No errors                          |
| 0x01  | Failure | 0x01          | Label detected error               |
| 0x01  | Failure | 0x02          | CRC error for data returned by tag |
| 0x01  | Failure | 0x03          | Label not responding               |

## 4.7 Write AFI (0x24)

##  Request frames (host requests)：

Table 4.13 Writing AFI request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 9bytes           | 2bytes |
| 0x7E55        | 0x11         |                |                | 0x24         | 0x00     | See Table 4.13.1 |        |

Table 4.13.1 Parameters for writing AFI request frames

| Tags UID         | AFI values |
| ---------------- | ---------- |
| 8bytes           | 1byte      |
| xxxxxxxxxxxxxxE0 |            |

##  Response frames (reader response)：

Table 4.14 Writing AFI response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 2bytes           | 2bytes |
| 0x7E55        | 0x0B         |                |                | 0x1F                 | 0x24         | 0x00     | See Table 4.14.1 |        |

Table 4.14.1 Parameters for writing AFI response frames

| Logo  | Logo    | Type of error | Type of error                      |
| ----- | ------- | ------------- | ---------------------------------- |
| 1byte | 1byte   | 1byte         | 1byte                              |
| 0x00  | Success | 0x00          | No errors                          |
| 0x01  | Failure | 0x01          | Label detected error               |
| 0x01  | Failure | 0x02          | CRC error for data returned by tag |
| 0x01  | Failure | 0x03          | Label not responding               |

## 4.8T a b l e 4 . 1 4 . 1 P a r a m e t e r s f o r w r i t i n g t o A F I r e s p o n s e f r a m e s

##  Request frames (host requests)：

Table 4.15 Locking AFI request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 8bytes           | 2bytes |
| 0x7E55        | 0x10         |                |                | 0x25         | 0x00     | See Table 4.15.1 |        |

Table 4.15.1 Parameters for locking AFI request frames

Tags UID

8bytes

xxxxxxxxxxxxxxE0

##  Response frames (reader response)：

Table 4.16 Locking AFI response frames

| Frame header | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------ | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes       | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 2bytes           | 2bytes |
| 0x7E55       | 0x0B         |                |                | 0x1F                 | 0x25         | 0x00     | See Table 4.16.1 |        |

Table 4.16.1 Locking AFI response frame parameters

| Logo  | Logo    | Type of error | Type of error                      |
| ----- | ------- | ------------- | ---------------------------------- |
| 1byte | 1byte   | 1byte         | 1byte                              |
| 0x00  | Success | 0x00          | No errors                          |
| 0x01  | Failure | 0x01          | Label detected error               |
| 0x01  | Failure | 0x02          | CRC error for data returned by tag |
| 0x01  | Failure | 0x03          | Label not responding               |

## 4.9 Write DSFID (0x26)

##  Request frames (host requests)：

Table 4.17 Writing DSFID request frames

| Frame header | Frame length | Source address | Target address | Command Code | Reserved | Parameters       | CRC    |
| ------------ | ------------ | -------------- | -------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes       | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 9bytes           | 2bytes |
| 0x7E55       | 0x11         |                |                | 0x26         | 0x00     | See Table 4.17.1 |        |

Table 4.17.1 Parameters for writing DSFID request frames

Tags UID

DSFID value

8bytes

1byte

xxxxxxxxxxxxxxE0

##  Response frames (reader response)：

Table 4.18 Writing DSFID response frames

| Frame header | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------ | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes       | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 2bytes           | 2bytes |
| 0x7E55       | 0x0B         |                |                | 0x1F                 | 0x26         | 0x00     | See Table 4.18.1 |        |

Table 4.18.1 Parameters for writing DSFID response frames

| Logo  | Logo    | Type of error | Type of error                     |
| ----- | ------- | ------------- | --------------------------------- |
| 1byte | 1byte   | 1byte         | 1byte                             |
| 0x00  | Success | 0x00          | No errors                         |
| 0x01  | Failure | 0x01          | Label detected error              |
| 0x01  | Failure | 0x02          | RC error for data returned by tag |
| 0x01  | Failure | 0x03          | Label not responding              |

## 4.10 Lock DSFID (0x27)

##  Request frames (host requests)：

Table 4.19 Locking DSFID request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 8bytes           | 2bytes |
| 0x7E55        | 0x10         |                |                | 0x27         | 0x00     | See Table 4.19.1 |        |

Table 4.19.1 Locking DSFID request frame parameters

Tags UID

8bytes

xxxxxxxxxxxxxxE0

##  Response frames (reader response)：

Table 4.20 Locking DSFID response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reser ved | Parameters | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | --------- | ---------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte     | 2bytes     | 2bytes |
| 0x7E55        | 0x0B         |                |                | 0x1F                 | 0x27         | 0x00      | See Table  |        |

4

20 1

Table 4.20.1 Locking DSFID response frame parameters

| Logo  | Logo    | Type of error | Type of error                      |
| ----- | ------- | ------------- | ---------------------------------- |
| 1byte | 1byte   | 1byte         | 1byte                              |
| 0x00  | Success | 0x00          | No errors                          |
| 0x01  | Failure | 0x01          | Label detected error               |
| 0x01  | Failure | 0x02          | CRC error for data returned by tag |
| 0x01  | Failure | 0x03          | Label not responding               |

## 4.11 Read tag system information (0x28)

##  Request frames (host requests)：

Table 4.21 Reading tag system information request frames

| Frame headers | Frame length | Source addres | Target address | Command Code | Reser ved | Parameters       | CRC    |
| ------------- | ------------ | ------------- | -------------- | ------------ | --------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes        | 2bytes         | 1byte        | 1byte     | 8bytes           | 2bytes |
| 0x7E55        | 0x10         |               |                | 0x28         | 0x00      | See Table 4.21.1 |        |

Table 4.21.1 Read tag system information request frame parameters

Tags UID

8bytes

xxxxxxxxxxxxxxE0

##  Response frames (reader response)：

Table 4.22 Reading tag system message response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 8bytes           | 2bytes |
| 0x7E55        | 0x11         |                |                | 0x1F                 | 0x28         | 0x00     | See Table 4.22.1 |        |

Table 4.22.1 Tag reading system message response frame parameters

| Logo  | Logo    | Type of error | Type of error                         | Information signs | DSFID | AFI   | Number of blocks | Block size | IC Reference |
| ----- | ------- | ------------- | ------------------------------------- | ----------------- | ----- | ----- | ---------------- | ---------- | ------------ |
| 1byte | 1byte   | 1byte         | 1byte                                 | 1byte             | 1byte | 1byte | 1byte            | 1byte      | 1byte        |
| 0x00  | Success | 0x00          | No errors                             |                   |       |       |                  |            |              |
| 0x01  | Failure | 0x01          | Label detected error                  |                   |       |       |                  |            |              |
| 0x01  | Failure | 0x02          | The tag returns data with a CRC error |                   |       |       |                  |            |              |
| 0x01  | Failure | 0x03          | Label not responding                  |                   |       |       |                  |            |              |

## 4.12 Transparent transmission (0x2F)

##  Request frames (reader requests)：

Table 4.23 Pass-through request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | Nbytes           | 2bytes |
| 0x7E55        | 0x08+N       |                |                | 0x2F         | 0x00     | See table 4.23.1 |        |

Table 4.23.1 Transmission request frame parameters

| Label request frame length | Frame  | Timeout time （us） | Label maximum response frame length |
| -------------------------- | ------ | ------------------- | ----------------------------------- |
| 1byte                      | nbytes | 2bytes              | 1byte                               |
|                            |        | > 330               |                                     |

Note 1: The system sends an EOF signal when the length n of the request frame for a transmission is equal to 0.

- Note 2: The request frame for a pass-through consists of: flags, command codes, parameters and data.
- Note 3: flag b1 (subcarrier flag) must be clear 0: a single subcarrier is used.
- Note 4: flag b2 (data rate) must be set to 1: a high speed rate is used.

Note 5: the timeout time is in us, 2 bytes parameter, lower byte first.

NOTE 6: the length of the response frame also excludes SOF, CRC and EOF.

NOTE 7: the response frame length is the longest length of the response frame for this pass-through request frame.

：

##  Response frames (reader response)

Table 4.24 Transmitted response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | Nbytes           | 2bytes |
| 0x7E55        | 0x0B+n       |                |                | 0x1F                 | 0x2F         | 0x00     | See table 4.24.1 |        |

Table 4.24.1 Transmission response frame parameters

| Tag response frames | Logo  | Logo    | Type of error | Type of error                      |
| ------------------- | ----- | ------- | ------------- | ---------------------------------- |
| nbytes              | 1byte | 1byte   | 1byte         | 1byte                              |
|                     | 0x00  | Success | 0x00          | No errors                          |
|                     | 0x01  | Failure | 0x01          | Label detected error               |
|                     | 0x01  | Failure | 0x02          | CRC error for data returned by tag |
|                     | 0x01  | Failure | 0x03          | Label not responding               |

## 4.13 D i r e c t m a n i p u l a t i o n o f l a b e l d a t a b l o c k s ( 0 x 3 0 )

The reader reads the tag UID and then reads the tag data block directly. The format is shown below：

##  Request frames (host requests)：

Table 4.25 Tag data block direct operation request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 7bytes           | 2bytes |
| 0x7E55        | 0x0F         |                |                | 0x30         | 0x00     | See table 4.25.1 |        |

Table 4.25.1 Parameters of the tag data block direct operation request frame

| Reserved | Mode  | Mode           | Number of data blocks | Data block address | Data block address | Data block address | Data block address |
| -------- | ----- | -------------- | --------------------- | ------------------ | ------------------ | ------------------ | ------------------ |
| 1byte    | 1byte | 1byte          | 1byte                 | 4bytes             | 4bytes             | 4bytes             | 4bytes             |
| 0x00     | 0x01  | Read UID       | 0x00                  | 0x00               | 0x00               | 0x00               | 0x00               |
| 0x00     | 0x03  | Reading blocks | 0x01~0x04             |                    |                    |                    |                    |

If the operation mode is 0x00, the reader will only read the tag UID and not the data block data by default.

##  Response frames (reader response)：

Table 4.26 Response frames for direct manipulation of label data blocks

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | nbytes           | 2bytes |
| 0x7E55        | 0x00         |                |                | 0x1F                 | 0x30         | 0x00     | See table 4.26.1 |        |

Table 4.26.1 Response frame parameters for direct operation of the label data block

| Parameters Length | Reserved | Mode  | Mode       | Data blocks Number (X) | Data block Address | Data block Address | Data block Address | Data block Address | Number of labels Item (Y) | UID       | Data blocks      |
| ----------------- | -------- | ----- | ---------- | ---------------------- | ------------------ | ------------------ | ------------------ | ------------------ | ------------------------- | --------- | ---------------- |
| 2bytes            | 1byte    | 1byte | 1byte      | 1byte                  | 4bytes             | 4bytes             | 4bytes             | 4bytes             | 1byte                     | Y\*8bytes | Y + Y*X*4bytes   |
|                   | 0x00     | 0x01  | read UID   | 0x00                   | 0x00               | 0x00               | 0x00               | 0x00               |                           |           | See table 4.26.2 |
|                   | 0x00     | 0x03  | Read Block | 0x01~0x04              |                    |                    |                    |                    |                           |           | See table 4.26.2 |

Table 4.26.2 Direct manipulation of tag response frame data block parameters

| Read block status | Read block status | Label 1 Data block | …   | Label Y Data block |
| ----------------- | ----------------- | ------------------ | --- | ------------------ |
| Ybytes            | Ybytes            | X\*4bytes          | …   | X\*4bytes          |
| 00                | Failu             |                    | …   |                    |
| 01                | Succe             |                    | …   |                    |

## 4.14 Smart Operation Label (0x3F)

-  Request frames (host requests)：

Table 4.27 Smart Operation Label Request Frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | Nbytes           | 2bytes |
| 0x7E0x55      |              |                |                | 0x3F         | 0x00     | See table 4.27.1 |        |

Table 4.27.1 Smart Operation Tag Request Frame Parameters

| Antenna mode | Antenna mode   | Antennae Number (M) | Antenna Index | Mode  | Mode                     | Number of data blocks | Data block |
| ------------ | -------------- | ------------------- | ------------- | ----- | ------------------------ | --------------------- | ---------- |
| 1byte        | 1byte          |                     |               | 1byte | 1byte                    |                       | address    |
| 0x00~ 0xFE   | Single Antenna | 0byte               | 0byte         | 0x01  | Read UID                 | 0byte                 | 0byte      |
| 0xFF         | Multi-         | 1byte               | Mbyte s       | 0x03  | Read UID and data blocks | 1byte                 | Nbytes     |
| 0xFF         | antenna        | 1byte               | Mbyte s       | 0x03  |                          | N=0x01~0x20           | Nbytes     |

Antenna mode: single antenna mode, this byte is the antenna index; 0xFF means multi-antenna mode, e.g. antenna index 0x00,0x01,0x02 means 1,2,3 antennas are automatically scanned.

##  Response frame (reader response).

Table 4.28 Smart Operation Tag Response Frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | nbytes           | 2bytes |
| 0x7E0x55      | 0x00         |                |                | 0x1F                 | 0x3F         | 0x00     | See table 4.28.1 |        |

Table 4.28.1 Smart Operation Tag Response Frame Parameters

| Parameter length | Antenna parameters |                    |       | Mode              | Data blocks Number (X) | Data block address | Label Number (Y) UID Y\*8bytes | Data blocks                       |
| ---------------- | ------------------ | ------------------ | ----- | ----------------- | ---------------------- | ------------------ | ------------------------------ | --------------------------------- |
| 2bytes           | 1byte              | 1byte              | 1byte | 1byte             |                        |                    | 1byte                          |                                   |
|                  | Single Day Line    | Antennas Index     | 0x01  | Read UID          | 0byte                  | 0byte              |                                | 0byte                             |
|                  | Multi- antenna     | Number of antennas | 0x03  | Read UID and data | 1byte 0x01~0x1F        | Xbytes             |                                | Y+Y*X*4bytes （See table 4.28.2） |

Table 4.28.2 Smart Operation Tag Response Frame Data Block Parameters

| Read block status | Read block status | Label 1 Data block | …   | Label Y Data block |
| ----------------- | ----------------- | ------------------ | --- | ------------------ |
| Ybytes            | Ybytes            | X\*4bytes          | …   | X\*4bytes          |
| 00                | Success           |                    | …   |                    |
| 01                | Failure           | X 个 FFFFFFFF      | …   | X 个 FFFFFFFF      |

Note: When a tag fails to read a data block, the corresponding status is 0x01 and the data block is FFFFFFFF filled.

## 4.15 L a b e l d a t a b l o c k d i r e c t w r i t e o p e r a t i o n ( 0 x 3 1 )

The tag data block is manipulated directly according to the UID provided by the master device. The format is shown below：

-  Request frames (host requests)：

Table 4.29 Direct write tag request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 2bytes     | Nbytes           | 2bytes |
| 0x7E55        | 0x00         |                |                | 0x31         | 0x00     | Length     | See table 4.29.1 |        |

Table 4.29.1 Direct write tag request frame parameters

| Label response Timeout time min | Label response Timeout max | Tags Number | Data blocks Number | Data block | UID       | Data blocks Data |
| ------------------------------- | -------------------------- | ----------- | ------------------ | ---------- | --------- | ---------------- |
| 2bytes                          | 2bytes                     | 1byte       | 1byte              | address    | n\*8bytes | n*m*4bytes       |
| Unit：us                        | Unit：us                   | n           | m（0x01~0x04）     | 4bytes     |           |                  |
| Unit：us                        | Unit：us                   | n           | m > 0x04           | mbytes     |           |                  |

Tag UID Format: XXXXXXXXXXXXXXXXXXXE0

：

##  Response frames (reader response)

Table 4.30 Direct Write Tag Response Frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | Mbytes           | 2bytes |
| 0x7E55        | 0x00         |                |                | 0x1F                 | 0x31         | 0x00     | See table 4.30.1 |        |

Table 4.30.1 Direct write tag response frame parameters

| Parameters Length | Results                   |
| ----------------- | ------------------------- |
| 2bytes            | n*m*1bytes                |
|                   | 0x01: Block write success |

Tag response timeout: indicates that the tag response time is within this time

interval； Primarily to address the potential for multiple ISO15693 label response time inconsistencies；

The smaller the interval, the faster and more accurate the decoding

## 4.16 Label AFI direct write operation (0x32)

The tag AFI is operated directly according to the UID provided by the master device in the format shown below：

-  Request frames (host requests)：

Table 4.31 Direct write tag request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 2bytes     | Nbytes           | 2bytes |
| 0x7E55        | 0x00         |                |                | 0x32         | 0x00     | Length     | See table 4.31.1 |        |

Table 4.31.1 Direct write tag request frame parameters

| Label response Timeout time min | Label response Timeout max | Reserved | AFI values | Tags Number | UID       |
| ------------------------------- | -------------------------- | -------- | ---------- | ----------- | --------- |
| 2bytes                          | 2bytes                     | 1byte    | 1byte      | 1byte       | n\*8bytes |
| Unit：us                        | Unit：us                   | 0x00     |            | n           |           |

## Tag UID Format: XXXXXXXXXXXXXXXXXXXE0

-  Response frames (reader response)：

Table 4.32 Direct Write Tag Response Frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | Mbytes           | 2bytes |
| 0x7E55        | 0x00         |                |                | 0x1F                 | 0x32         | 0x00     | See table 4.32.1 |        |

Table 4.32.1 Direct write tag response frame parameters

| Parameters Length | Results                                          |
| ----------------- | ------------------------------------------------ |
| 2bytes            | n\*1bytes                                        |
|                   | 0x01: Write AFI success 0x00: Writing AFI failed |

Label response timeout: indicates that the label response time is within this time interval.

This is mainly to solve the problem of inconsistent

response times for multiple ISO15693 labels; the smaller the interval, the faster and more accurate the decoding speed

## 4.17 Tags AFI direct read operation（0x33）

The operation tag AFI is read directly from the UID provided by the master device in the format shown below：

-  Request frames (host requests)：

Table 4.33 Direct Read Label AFI Request Frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 2bytes     | Nbytes           | 2bytes |
| 0x7E55        | 0x00         |                |                | 0x33         | 0x00     | Length     | See table 4.33.1 |        |

Table 4.33.1 Direct read tag AFI request frame parameters

| Reserved | Number of labels | UID       |
| -------- | ---------------- | --------- |
| 1byte    | 1byte            | n\*8bytes |
| 0x00     | n                |           |

Tag UID Format: XXXXXXXXXXXXXXXXXXXE0

-  Response frames (reader response)：

Table 4.34 Direct Read Label AFI Response Frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | Mbytes           | 2bytes |
| 0x7E55        | 0x00         |                |                | 0x1F                 | 0x32         | 0x00     | See table 4.34.1 |        |

Table 4.34.1 Direct read tag AFI response frame parameters

| Parameters Length | Results                                          | AFI        |
| ----------------- | ------------------------------------------------ | ---------- |
| 2bytes            | n\*1bytes                                        | n\*1bytes  |
|                   | 0x01: Write AFI success 0x00: Writing AFI failed | AFI values |

## Chapter 5 ISO14443A Label manipulation command frame format

## 5.1 Tag into the field (0x15)

When the reader is in UID active upload mode, if the reader successfully acquires the UID, it will actively upload the tag UID information. The format is shown below：

##  Request frames (reader requests)：

Table 5.1 Tag entry request frames in the field

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters      | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 14bytes         | 2bytes |
| 0x7E55        | 0x16         |                |                | 0x15         | 0x00     | See table 5.1.1 |        |

Table 5.1.1 Tag entry field upload message parameters

| Label Type | UID Length | UID     | SAK   |
| ---------- | ---------- | ------- | ----- |
| 2bytes     | 1byte      | 10bytes | 1byte |
|            | 4/7/10     |         |       |

##  Response frames (host response)：

Table 5.2 Tag-in-field response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters      | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 2bytes          | 2bytes |
| 0x7E55        | 0x0B         |                |                | 0x1F                 | 0x15         | 0x00     | See table 5.2.1 |        |

Table 5.2.1 Label entry response frame parameters in the field

| Configuration flags | Configuration flags | Reserved |
| ------------------- | ------------------- | -------- |
| 1byte               | 1byte               | 1byte    |
| 0x00                | Success             | 0x00     |
| 0x01                | Failure             | 0x00     |

## 5.2 Query field label (0x16)

When the reader is in UID passive upload mode, it responds to the request frame. The format is shown below：

##  Request frames (host requests)：

Table 5.3 Querying in-field tag request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters      | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 1byte           | 2bytes |
| 0x7E55        | 0x09         |                |                | 0x16         | 0x00     | See table 5.3.1 |        |

Table 5.3.1 Parameters for querying in-field tag request frames

| Mode | Mode              |
| ---- | ----------------- |
| 0x00 | Read idle tag Uid |
| 0x01 | Read all tags Uid |

##  Response frames (reader response)：

Table 5.4 Querying in-field tag response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters      | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | (2+14\*N)bytes  | 2bytes |
| 0x7E55        | 0x0B+14\*N   |                |                | 0x1F                 | 0x16         | 0x00     | See table 5.4.1 |        |

Table 5.4.1 Parameters for querying in-field tag response frames

| UID       | UID       | UID       | Number of labels remaining | Reserved |
| --------- | --------- | --------- | -------------------------- | -------- |
| N×14bytes | N×14bytes | N×14bytes | 1byte                      | 1byte    |
| UID1      | …         | UIDN      |                            | 0x00     |

The UID format is described in Table 5.1.1.

## 5.3 Authorisation to read M1 data block (0x70)

-  Request frames (host requests)：

Table 5.5 Authorised read M1 data block request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters      | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | Nbytes          | 2bytes |
| 0x7E55        | 0x08+N       |                |                | 0x70         | 0x00     | See table 5.5.1 |        |

Table 5.5.1 Authorization to read M1 data block request frame parameters

| Label UID (optional) | Label UID (optional) | Label UID (optional) | Key Type | Key Type | Key    | Block Address | Number |
| -------------------- | -------------------- | -------------------- | -------- | -------- | ------ | ------------- | ------ |
| 13bytes              | 13bytes              | 13bytes              | 1byte    | 1byte    | 6bytes | 1byte         | 1byte  |
| Label Type           | UID Length           | UID                  | 0x60     | KeyA     |        |               | 0x01   |
| 2bytes               | 1byte                | 10bytes              | 0x61     | KeyB     |        |               | 0x01   |

If the system is in Trigger Mode, then the reader can only operate on a single tag. At this point there is no need for the host to send command frame with the tag UID.

：

##  Response frames (reader response)

Table 5.6 Authorised read M1 data block response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters      | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | Nbytes          | 2bytes |
| 0x7E55        | 0x09+N       |                |                | 0x1F                 | 0x70         | 0x00     | See table 5.6.1 |        |

Table 5.6.1 Authorised read M1 data block response frame parameters

| Data blocks | Logo  | Logo    | Type of error | Type of error                      |
| ----------- | ----- | ------- | ------------- | ---------------------------------- |
| nbytes      | 1byte | 1byte   | 1byte         | 1byte                              |
| 16bytes     | 0x00  | Success | 0x00          | No errors                          |
| 0byte       | 0x01  | Failure | 0x01          | Label detected error               |
| 0byte       | 0x01  | Failure | 0x02          | CRC error for data returned by tag |
| 0byte       | 0x01  | Failure | 0x03          | Label not responding               |

## 5.4 Authorization to write M1 data block (0x71)

##  Request frames (host requests)：

Table 5.7 Authorised write M1 data block request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters      | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | Nbytes          | 2bytes |
| 0x7E55        | 0x08+N       |                |                | 0x71         | 0x00     | See table 5.7.1 |        |

Table 5.7.1 Authorization to write M1 data block request frame parameters

| Label UID (optional) | Label UID (optional) | Label UID (optional) | Key Type | Key Type | Key    | Block Address | Number | Data    |
| -------------------- | -------------------- | -------------------- | -------- | -------- | ------ | ------------- | ------ | ------- |
| 13bytes              | 13bytes              | 13bytes              | 1byte    | 1byte    | 6bytes | 1byte         | 1byte  | 16bytes |
| Label Type           | UID Length           | UID                  | 0x60     | KeyA     |        |               | 0x01   |         |
| 2bytes               | 1byte                | 10bytes              | 0x61     | KeyB     |        |               |        |         |

If the system is in trigger mode, then the reader can only operate on a single tag. At this point there is no need for the host to send command frame with the tag UID.

##  Response frame (reader response)：

Table 5.8 Authorised write M1 data block response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters      | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 2bytes          | 2bytes |
| 0x7E55        | 0x0B         |                |                | 0x1F                 | 0x71         | 0x00     | See table 5.8.1 |        |

Table 5.8.1 Authorization to write M1 data block response frame parameters

| Logo  | Logo    | Type of error | Type of error                      |
| ----- | ------- | ------------- | ---------------------------------- |
| 1byte | 1byte   | 1byte         | 1byte                              |
| 0x00  | Success | 0x00          | No errors                          |
| 0x01  | Failure | 0x01          | Label detected error               |
| 0x01  | Failure | 0x02          | CRC error for data returned by tag |
| 0x01  | Failure | 0x03          | Label not responding               |

## 5.5 Authorised reading of M1 value (0x72)

##  Request frames (host requests)：

Table 5.9 Authorised write M1 value request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters      | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | Nbytes          | 2bytes |
| 0x7E55        | 0x08+N       |                |                | 0x72         | 0x00     | See table 5.9.1 |        |

Table 5.9.1 Authorization to read M1 value request frame parameters

| Label UID (optional) | Label UID (optional) | Label UID (optional) | Key Type | Key Type | Key    | Block Address |
| -------------------- | -------------------- | -------------------- | -------- | -------- | ------ | ------------- |
| 13bytes              | 13bytes              | 13bytes              | 1byte    | 1byte    | 6bytes | 1byte         |
| Label Type           | UID Length           | UID                  | 0x60     | KeyA     |        |               |
| 2bytes               | 1byte                | 10bytes              | 0x61     | KeyB     |        |               |

If the system is in trigger mode, then the reader can only operate on a single tag. At this point there is no need for the host to send command frame with the tag UID.

##  Response frames (reader response)：

Table 5.10 Authorised reading of M1 value response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | Nbytes           | 2bytes |
| 0x7E55        | 0x09+N       |                |                | 0x1F                 | 0x72         | 0x00     | See table 5.10.1 |        |

Table 5.10.1 Authorization to read M1 values for frame parameters

| Value  | Backup address | Logo  | Logo    | Type of error | Type of error                      |
| ------ | -------------- | ----- | ------- | ------------- | ---------------------------------- |
| nbytes | n1bytes        | 1byte | 1byte   | 1byte         | 1byte                              |
| 4bytes | 1byte          | 0x00  | Success | 0x00          | No errors                          |
| 0byte  | 0byte          | 0x01  | Failure | 0x01          | Label detected error               |
| 0byte  | 0byte          | 0x01  | Failure | 0x02          | CRC error for data returned by tag |
| 0byte  | 0byte          | 0x01  | Failure | 0x03          | Label not responding               |

## 5.6 Authorisation to write M1 value (0x73)

##  Request frames (host requests)：

Table 5.11 Authorised write M1 value request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | Nbytes           | 2bytes |
| 0x7E55        | 0x08+N       |                |                | 0x73         | 0x00     | See table 5.11.1 |        |

Table 5.11.1 Authorization to write M1 value request frame parameters

| Label UID (optional) | Label UID (optional) | Label UID (optional) | Key Type | Key Type | Key    | Block Addres | Value  | Backup address |
| -------------------- | -------------------- | -------------------- | -------- | -------- | ------ | ------------ | ------ | -------------- |
| 13bytes              | 13bytes              | 13bytes              | 1byte    | 1byte    | 6bytes | 1byte        | 4bytes | 1byte          |
| Label Type           | UID Length           | UID                  | 0x60     | KeyA     |        |              |        |                |
| 2bytes               | 1byte                | 10bytes              | 0x61     | KeyB     |        |              |        |                |

If the system is in trigger mode, then the reader can only operate on a single tag. At this point there is no need for the host to send command frame with the tag UID.

##  Response frames (reader response)：

Table 5.12 Authorisation to write M1 value response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 2bytes           | 2bytes |
| 0x7E55        | 0x0B         |                |                | 0x1F                 | 0x73         | 0x00     | See table 5.12.1 |        |

Table 5.12.1 Authorization to write M1 value response frame parameters

| Logo  | Logo    | Type of error | Type of error                      |
| ----- | ------- | ------------- | ---------------------------------- |
| 1byte | 1byte   | 1byte         | 1byte                              |
| 0x00  | Success | 0x00          | No errors                          |
| 0x01  | Failure | 0x01          | Label detected error               |
| 0x01  | Failure | 0x02          | CRC error for data returned by tag |
| 0x01  | Failure | 0x03          | Label not responding               |

## 5.7 Authorised operation M1 value (0x74)

##  Request frames (host requests)：

Table 5.13 Authorised operation M1 value request frame

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | Nbytes           | 2bytes |
| 0x7E55        | 0x08+N       |                |                | 0x74         | 0x00     | See table 5.13.1 |        |

Table 5.13.1 Authorization operation M1 value request frame parameters

| Label UID (optional) | Label UID (optional) | Label UID (optional) | Key Type | Key Type | Key    | Block Address | Value  | Operati on Code | Backup address |
| -------------------- | -------------------- | -------------------- | -------- | -------- | ------ | ------------- | ------ | --------------- | -------------- |
| 13bytes              | 13bytes              | 13bytes              | 1byte    | 1byte    | 6bytes | 1byte         | 4bytes | 1byte           | 1byte          |
| Label Type           | UID Length           | UID                  | 0x60     | KeyA     |        |               |        |                 |                |
| 2bytes               | 1byte                | 10bytes              | 0x61     | KeyB     |        |               |        |                 |                |

If the system is in trigger mode, then the reader can only operate on a single tag. At this point there is no need for the host to send command frame with the tag UID.

##  Response frames (reader response)：

Table 5.14 Response frames for M1 values for authorised operations

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 2bytes           | 2bytes |
| 0x7E55        | 0x0B         |                |                | 0x1F                 | 0x74         | 0x00     | See table 5.14.1 |        |

Table 5.14.1 Response frame parameters for the M1 value of the authorisation operation

| Logo  | Logo    | Type of error | Type of error                      |
| ----- | ------- | ------------- | ---------------------------------- |
| 1byte | 1byte   | 1byte         | 1byte                              |
| 0x00  | Success | 0x00          | No errors                          |
| 0x01  | Failure | 0x01          | Label detected error               |
| 0x01  | Failure | 0x02          | CRC error for data returned by tag |
| 0x01  | Failure | 0x03          | Label not responding               |

## 5.8 Read M0 data page (0x75)

##  Request frames (host requests)：

Table 5.15 Read M0 data page request frame

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | Nbytes           | 2bytes |
| 0x7E55        | 0x08+N       |                |                | 0x75         | 0x00     | See table 5.15.1 |        |

Table 5.15.1 Read M0 data page request frame parameters

| Label UID (optional) | Label UID (optional) | Label UID (optional) | Key Type | Key    | Page address | Number |
| -------------------- | -------------------- | -------------------- | -------- | ------ | ------------ | ------ |
| 13bytes              | 13bytes              | 13bytes              | 1byte    | nbytes | 1byte        | 1byte  |
| Label Type           | UID Length           | UID                  | 0x00     | 0byte  |              | m      |
| 2bytes               | 1byte                | 10bytes              | 0x01     | 4bytes |              | m      |

If the system is in trigger mode, then the reader can only operate on a single tag. At this point there is no need for the host to send command frame with the tag UID.

Up to 52 M0 data pages can be read (4 bytes/page).

##  Response frames (reader response)：

Table 5.16 Read M0 data page response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | Nbytes           | 2bytes |
| 0x7E55        | 0x09+N       |                |                | 0x1F                 | 0x75         | 0x00     | See table 5.16.1 |        |

Table 5.16.1 Read M0 data page response frame parameters

| Data page | Logo  | Logo    | Type of error | Type of error                      |
| --------- | ----- | ------- | ------------- | ---------------------------------- |
| nbytes    | 1byte | 1byte   | 1byte         | 1byte                              |
| m\*4bytes | 0x00  | Success | 0x00          | No errors                          |
| 0byte     | 0x01  | Failure | 0x01          | Label detected error               |
| 0byte     | 0x01  | Failure | 0x02          | CRC error for data returned by tag |
| 0byte     | 0x01  | Failure | 0x03          | Label not responding               |

## 5.9 Write M0 data page (0x76)

##  Request frames (host requests)：

Table 5.17 Write M0 data page request frame

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | Nbytes           | 2bytes |
| 0x7E55        | 0x08+N       |                |                | 0x76         | 0x00     | See table 5.17.1 |        |

Table 5.17.1 Write M0 data page request frame parameters

| Label UID (optional) | Label UID (optional) | Label UID (optional) | Key Type | Key    | Block Address | Number | Data      |
| -------------------- | -------------------- | -------------------- | -------- | ------ | ------------- | ------ | --------- |
| 13bytes              | 13bytes              | 13bytes              | 1byte    | nbytes | 1byte         | 1byte  | m\*4bytes |
| Label Type           | UID Length           | UID                  | 0x00     | 0byte  |               | m      |           |
| 2bytes               | 1byte                | 10bytes              | 0x01     | 4bytes |               | m      |           |

If the system is in trigger mode, then the reader can only operate on a single tag. At this point there is no need for the host to send command frame with the tag UID.

Up to 52 M0 data pages can be written (4 bytes/page).

##  Response frames (reader response)：

Table 5.18 Write M0 data page response frame

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 2bytes           | 2bytes |
| 0x7E55        | 0x0B         |                |                | 0x1F                 | 0x76         | 0x00     | See table 5.18.1 |        |

Table 5.18.1 Write M0 data page response frame parameters

| Logo  | Logo    | Type of error | Type of error                      |
| ----- | ------- | ------------- | ---------------------------------- |
| 1byte | 1byte   | 1byte         | 1byte                              |
| 0x00  | Success | 0x00          | No errors                          |
| 0x01  | Failure | 0x01          | Label detected error               |
| 0x01  | Failure | 0x02          | CRC error for data returned by tag |
| 0x01  | Failure | 0x03          | Label not responding               |

## 5.10 RATS（0x77）

##  Request frames (host requests)：

Table 5.19 RATS request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 0byte      | 2bytes |
| 0x7E55        | 0x08         |                |                | 0x77         | 0x00     |            |        |

##  Response frames (reader response)：

Table 5.20 RATS response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | Nbytes           | 2bytes |
| 0x7E55        | 0x09+N       |                |                | 0x1F                 | 0x77         | 0x00     | See table 5.20.1 |        |

Table 5.20.1 RATS response frame parameters

| Data page | Logo  | Logo    | Type of error | Type of error                      |
| --------- | ----- | ------- | ------------- | ---------------------------------- |
| nbytes    | 1byte | 1byte   | 1byte         | 1byte                              |
| ATS       | 0x00  | Success | 0x00          | No errors                          |
| 0byte     | 0x01  | Failure | 0x01          | Label detected error               |
| 0byte     | 0x01  | Failure | 0x02          | CRC error for data returned by tag |
| 0byte     | 0x01  | Failure | 0x03          | Label not responding               |

## 5.11 Contact card (PSAM/ESAM) control (0x78)

##  Request frames (host requests)：

Table 5.21 Contact card control request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 2byte            | 2bytes |
| 0x7E55        | 0x0A         |                |                | 0x78         | 0x00     | See table 5.21.1 |        |

Table 5.21.1 Contact card control request frame parameters

| Index | Index | Control   | Control           | Control |
| ----- | ----- | --------- | ----------------- | ------- |
| 1byte | 1byte | 1byte     | 1byte             | 1byte   |
| 0x01  | 0x02  | 0x00      | 0x01              | 0x02    |
| SAM1  | SAM2  | Power off | Turn on the power | Reset   |

##  Response frames (reader response)：

Table 5.22 Contact card control response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | Nbytes           | 2bytes |
| 0x7E55        | 0x09+N       |                |                | 0x1F                 | 0x78         | 0x00     | See table 5.22.1 |        |

Table 5.22.1 Contact card control response frame parameters

| Data   | Logo  | Logo    | Type of error | Type of error                |
| ------ | ----- | ------- | ------------- | ---------------------------- |
| nbytes | 1byte | 1byte   | 1byte         | 1byte                        |
| ATS    | 0x00  | Success | 0x00          | No errors                    |
| 0byte  | 0x01  | Failure | 0x01          | SAM error detected           |
| 0byte  | 0x01  | Failure | 0x02          | CRC error in SAM return data |
| 0byte  | 0x01  | Failure | 0x03          | SAM not responding           |

## 5.12 APDU（0x7A）

##  Request frames (host requests)：

Table 5.23 APDU request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | Nbytes           | 2bytes |
| 0x7E55        | 0x08+N       |                |                | 0x7A         | 0x00     | See table 5.23.1 |        |

Table 5.23.1 APDU request frame parameters

| Index       | Index | Index | Request data |
| ----------- | ----- | ----- | ------------ |
| 1byte       | 1byte | 1byte | nbytes       |
| 0x00        | 0x01  | 0x02  |              |
| non-contact | SAM1  | SAM2  |              |

##  Response frames (reader response)：

Table 5.24 APDU response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | Nbytes           | 2bytes |
| 0x7E55        | 0x09+N       |                |                | 0x1F                 | 0x7A         | 0x00     | See table 5.24.1 |        |

Table 5.24.1 APDU response frame parameters

| Data            | Logo  | Logo    | Type of error | Type of error                                      |
| --------------- | ----- | ------- | ------------- | -------------------------------------------------- |
| nbytes          | 1byte | 1byte   | 1byte         | 1byte                                              |
| Response frames | 0x00  | Success | 0x00          | No errors                                          |
| 0byte           | 0x01  | Failure | 0x01          | SAM/non-contact tag detection error                |
| 0byte           | 0x01  | Failure | 0x02          | SAM/Non-contact CRC error for data returned by tag |
| 0byte           | 0x01  | Failure | 0x03          | SAM/Non-contact Label not responding               |

## 5.13 Hang up (0x7B)

##  Request frames (host requests)：

Table 5.25 Hanging request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 0byte      | 2bytes |
| 0x7E55        | 0x08         |                |                | 0x7B         | 0x00     |            |        |

##  Response frames (reader response)：

Table 5.26 Hanging response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 2bytes           | 2bytes |
| 0x7E55        | 0x0B         |                |                | 0x1F                 | 0x7B         | 0x00     | See table 5.26.1 |        |

Table 5.26.1 Hanging response frame parameters

| Logo  | Logo    | Type of error | Type of error                      |
| ----- | ------- | ------------- | ---------------------------------- |
| 1byte | 1byte   | 1byte         | 1byte                              |
| 0x00  | Success | 0x00          | No errors                          |
| 0x01  | Failure | 0x01          | Label detected error               |
| 0x01  | Failure | 0x02          | CRC error for data returned by tag |
| 0x01  | Failure | 0x03          | Label not responding               |

## 5.14 DESELECT（0x7C）

##  Request frames (host requests)：

Table 5.27 DESELECT request frames

| Frame headers | Frame length Degree | Source address | Target address | Command Code | Reserved | Parameters | CRC    |
| ------------- | ------------------- | -------------- | -------------- | ------------ | -------- | ---------- | ------ |
| 2bytes        | 1byte               | 2bytes         | 2bytes         | 1byte        | 1byte    | 0byte      | 2bytes |
| 0x7E55        | 0x08                |                |                | 0x7C         | 0x00     |            |        |

##  Response frames (reader response：

Table 5.28 DESELECT response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 2bytes           | 2bytes |
| 0x7E55        | 0x0B         |                |                | 0x1F                 | 0x7C         | 0x00     | See table 5.28.1 |        |

Table 5.28.1 DESELECT response frame parameters

| Logo  | Logo    | Type of error | Type of error                      |
| ----- | ------- | ------------- | ---------------------------------- |
| 1byte | 1byte   | 1byte         | 1byte                              |
| 0x00  | Success | 0x00          | No errors                          |
| 0x01  | Failure | 0x01          | Label detected error               |
| 0x01  | Failure | 0x02          | CRC error for data returned by tag |
| 0x01  | Failure | 0x03          | Label not responding               |

## 5.15 Pass-through (0x7F)

##  Request frames (reader requests)：

Table 5.29 Pass-through request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | Nbytes           | 2bytes |
| 0x7E55        | 0x08+N       |                |                | 0x7F         | 0x00     | See table 5.29.1 |        |

Table 5.29.1 Transmission request frame parameters

| Request Frame Length | Last byte Number of valid bits | Frame  | Timeout time （us） | Response frame Length | Last byte Number of valid bits |
| -------------------- | ------------------------------ | ------ | ------------------- | --------------------- | ------------------------------ |
| 1byte                | 1byte                          | nbytes | 2bytes              | 1byte                 | 1byte                          |
|                      | 0 means All valid              |        | > 330               |                       | 0 means All valid              |

Note 1: If CRC is required at the end of the frame, please calculate CRC and add it to the end of the frame.

Note 2: If SUM is required at the end of the frame, calculate SUM and add it to the end of the frame.

Note 3: The reader automatically calculates the byte check bits

##  Response frames (reader response)：

Table 5.30 Transmitted response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | Nbytes           | 2bytes |
| 0x7E55        | 0x09+N       |                |                | 0x1F                 | 0x7F         | 0x00     | See table 5.30.1 |        |

Table 5.30.1 Transmission response frame parameters

| Response frames | Logo  | Logo    | Type of error | Type of error                      |
| --------------- | ----- | ------- | ------------- | ---------------------------------- |
| nbytes          | 1byte | 1byte   | 1byte         | 1byte                              |
| mbytes          | 0x00  | Success | 0x00          | No errors                          |
| 0bytes          | 0x01  | Failure | 0x01          | Label detected error               |
| 0bytes          | 0x01  | Failure | 0x02          | CRC error for data returned by tag |
| 0bytes          | 0x01  | Failure | 0x03          | Label not responding               |

## 5.16 Authorised by UltralightC（0x80）

##  Request frames (host requests)：

Table 5.31 Authorised UltralighC reques t frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 16bytes    | 2bytes |
| 0x7E55        | 0x08+N       |                |                | 0x80         | 0x00     | Key        |        |

##  Response frames (reader response)：

Table 5.32 Authorised UltralighC response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 2bytes           | 2bytes |
| 0x7E55        | 0x0B         |                |                | 0x1F                 | 0x80         | 0x00     | See table 5.32.1 |        |

Table 5.32.1 Authorised UltralighC response frame parameters

| Logo  | Logo    | Type of error | Type of error                      |
| ----- | ------- | ------------- | ---------------------------------- |
| 1byte | 1byte   | 1byte         | 1byte                              |
| 0x00  | Success | 0x00          | No errors                          |
| 0x01  | Failure | 0x01          | Label detected error               |
| 0x01  | Failure | 0x02          | CRC error for data returned by tag |
| 0x01  | Failure | 0x03          | Label not responding               |

## 5.17 Read Topaz data block (0x81)

##  Request frames (host requests)：

Table 5.33 Read Topaz data block request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | Nbytes           | 2bytes |
| 0x7E55        | 0x08+N       |                |                | 0x81         | 0x00     | See table 5.33.1 |        |

Table 5.33.1 Topaz data block request frame parameters

| Label UID (optional) | Label UID (optional) | Label UID (optional) | Addre ss | Numbe r |
| -------------------- | -------------------- | -------------------- | -------- | ------- |
| 13bytes              | 13bytes              | 13bytes              | 1byte    | 1byte   |
| Label Type           | UID Length           | UID                  |          | m       |
| 2bytes               | 1byte                | 10bytes              |          |         |

If the system is in trigger mode, then the reader can only operate on a single tag. At this point there is no need for the host to send command frame with the tag UID. Up to 26 Topaz blocks (8 bytes/block) can be read.

-  Response frames (reader response)：

Table 5.34 Topaz data block response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | Nbytes           | 2bytes |
| 0x7E55        | 0x09+N       |                |                | 0x1F                 | 0x81         | 0x00     | See table 5.34.1 |        |

Table 5.34.1 Topaz data block response frame parameters

| Data page | Logo  | Logo    | Type of error | Type of error                      |
| --------- | ----- | ------- | ------------- | ---------------------------------- |
| nbytes    | 1byte | 1byte   | 1byte         | 1byte                              |
| m\*8bytes | 0x00  | Success | 0x00          | No errors                          |
| 0byte     | 0x01  | Failure | 0x01          | Label detected error               |
| 0byte     | 0x01  | Failure | 0x02          | CRC error for data returned by tag |
| 0byte     | 0x01  | Failure | 0x03          | Label not responding               |

## 5.18 Write Topaz data block (0x82)

##  Request frames (host requests)：

Table 5.35 Write Topaz data block request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | Nbytes           | 2bytes |
| 0x7E55        | 0x08+N       |                |                | 0x82         | 0x00     | See table 5.35.1 |        |

Table 5.35.1 Write Topaz data block request frame parameters

| Label UID (optional) | Label UID (optional) | Label UID (optional) | Block Addres | Number | Data      |
| -------------------- | -------------------- | -------------------- | ------------ | ------ | --------- |
| 13bytes              | 13bytes              | 13bytes              | 1byte        | 1byte  | m\*8bytes |
| Label Type           | UID Length           | UID                  |              | m      |           |
| 2bytes               | 1byte                | 10bytes              |              | m      |           |

- If the system is in trigger mode, then the reader can only operate on a single tag. At this point there is no need for the host to send command frame with the tag UID.

Up to 26 write blocks of Topaz data (8 bytes/block) can be written.

##  Response frames (reader response)：

Table 5.36 Writing Topaz data block response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters       | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 2bytes           | 2bytes |
| 0x7E55        | 0x0B         |                |                | 0x1F                 | 0x82         | 0x00     | See table 5.36.1 |        |

Table 5.36.1 Write Topaz data block response frame parameters

| Logo  | Logo    | Type of error | Type of error                      |
| ----- | ------- | ------------- | ---------------------------------- |
| 1byte | 1byte   | 1byte         | 1byte                              |
| 0x00  | Success | 0x00          | No errors                          |
| 0x01  | Failure | 0x01          | Label detected error               |
| 0x01  | Failure | 0x02          | CRC error for data returned by tag |
| 0x01  | Failure | 0x03          | Label not responding               |

## Chapter 6 ISO14443B Label Operation Command Frame Format

## 6.1 Select Tag (0x1A)

Selecting a unique label in the field using the pattern of time slot 1。

-  Request frames (reader requests)：

Table 6.1 Selecting tag request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 1bytes     | 2bytes |
| 0x7E55        | 0x09         |                |                | 0x1A         | 0x00     | RFU        |        |

##  Response frames (host response)：

Table 6.2 Selecting label response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters      | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 12bytes         | 2bytes |
| 0x7E55        | 0x15         |                |                | 0x1F                 | 0x1A         | 0x00     | See table 6.2.1 |        |

Table 6.2.1 Selection of tag response frame parameters

| PUPI   | Application information | Agreement information |
| ------ | ----------------------- | --------------------- |
| 4bytes | 4bytes                  | 4bytes                |

## 6.2 Read Chinese ID tag UID (0xA0)

The ID tag UID is 8 bytes in length.

##  Request frames (reader requests)：

Table 6.3 Reading ID card UID request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 1bytes     | 2bytes |
| 0x7E55        | 0x09         |                |                | 0xA0         | 0x00     | RFU        |        |

##  Response frames (host response)：

Table 6.4 Response frames for reading the ID card UID

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | ---------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 8bytes     | 2bytes |
| 0x7E55        | 0x15         |                |                | 0x1F                 | 0xA0         | 0x00     | UID        |        |

## 6.3 Pass-through (0xAF)

##  Request frames (reader requests)：

Table 6.5 Pass-through request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters      | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | Nbytes          | 2bytes |
| 0x7E55        | 0x08+N       |                |                | 0xAF         | 0x00     | See table 6.5.1 |        |

Table 6.5.1 Transmission request frame parameters

| Request Frame Length | Frame  | Timeout time (us) | Response frame Length |
| -------------------- | ------ | ----------------- | --------------------- |
| 1byte                | nbytes | 2bytes            | 1byte                 |

##  Response frames (reader response)：

Table 6.6 Transmitted response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters      | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | Nbytes          | 2bytes |
| 0x7E55        | 0x09+N       |                |                | 0x1F                 | 0xAF         | 0x00     | See table 6.6.1 |        |

Table 6.6.1 Transmission response frame parameters

| Response frames | Logo  | Logo    | Type of error | Type of error                      |
| --------------- | ----- | ------- | ------------- | ---------------------------------- |
| nbytes          | 1byte | 1byte   | 1byte         | 1byte                              |
| mbytes          | 0x00  | Success | 0x00          | No errors                          |
| 0bytes          | 0x01  | Failure | 0x01          | Label detected error               |
| 0bytes          | 0x01  | Failure | 0x02          | CRC error for data returned by tag |
| 0bytes          | 0x01  | Failure | 0x03          | Label not responding               |

## 6.4 Hang up（0xAE）

##  Request frames (host requests)：

Table 6.7 Hanging request frames

| Frame headers | Frame length Degree | Source address | Target address | Command Code | Reserved | Parameters | CRC    |
| ------------- | ------------------- | -------------- | -------------- | ------------ | -------- | ---------- | ------ |
| 2bytes        | 1byte               | 2bytes         | 2bytes         | 1byte        | 1byte    | 0byte      | 2bytes |
| 0x7E55        | 0x08                |                |                | 0xAE         | 0x00     |            |        |

##  Response frames (reader response)：

Table 6.8 Hanging response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters      | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 2bytes          | 2bytes |
| 0x7E55        | 0x0B         |                |                | 0x1F                 | 0xAE         | 0x00     | See table 6.8.1 |        |

Table 6.8.1 Hanging response frame parameters

| Logo  | Logo    | Type of error | Type of error                      |
| ----- | ------- | ------------- | ---------------------------------- |
| 1byte | 1byte   | 1byte         | 1byte                              |
| 0x00  | Success | 0x00          | No errors                          |
| 0x01  | Failure | 0x01          | Label detected error               |
| 0x01  | Failure | 0x02          | CRC error for data returned by tag |
| 0x01  | Failure | 0x03          | Label not responding               |

## Chapter 7 Felica tag manipulation command frame format 7.1 Get UID (0x18)

Selects a unique tag in the field using a time slot 1 pattern with a 16-byte long tag UID。

-  Request frames (reader requests)：
-  Response frames (host response)：

Table 7.1 Get UID request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | ---------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | 1bytes     | 2bytes |
| 0x7E55        | 0x09         |                |                | 0x18         | 0x00     | RFU        |        |

Table 7.2 Get UID response frames

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters      | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | 16bytes         | 2bytes |
| 0x7E55        |              |                |                | 0x1F                 | 0x18         | 0x00     | See table 7.2.1 |        |

Table 7.2.1 Get UID response frame parameters

| UID    | Logo  | Logo    | Type of error | Type of error                      |
| ------ | ----- | ------- | ------------- | ---------------------------------- |
| UID    | 1byte | 1byte   | 1byte         | 1byte                              |
| 16byte | 0x00  | Success | 0x00          | No errors                          |
| 0byte  | 0x01  | Failure | 0x01          | Label detected error               |
| 0byte  | 0x01  | Failure | 0x02          | CRC error for data returned by tag |
| 0byte  | 0x01  | Failure | 0x03          | Label not responding               |

## 7.2 Pass-through (0x9F)

##  Request frames (reader requests)：

Table 7.3 Pass-through request frames

| Frame headers | Frame length | Source address | Target address | Command Code | Reserved | Parameters      | CRC    |
| ------------- | ------------ | -------------- | -------------- | ------------ | -------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte        | 1byte    | Nbytes          | 2bytes |
| 0x7E55        | 0x08+N       |                |                | 0x9F         | 0x00     | See table 7.3.1 |        |

Table 7.3.1 Transmission request frame parameters

| Request Frame Length | Frame  | Timeout time (us) | Response frame Length |
| -------------------- | ------ | ----------------- | --------------------- |
| 1byte                | nbytes | 2bytes            | 1byte                 |

##  Response frames (reader response)：

Table 7.3.1 Transmission request frame parameters

| Frame headers | Frame length | Source address | Target address | Response frame flags | Command Code | Reserved | Parameters      | CRC    |
| ------------- | ------------ | -------------- | -------------- | -------------------- | ------------ | -------- | --------------- | ------ |
| 2bytes        | 1byte        | 2bytes         | 2bytes         | 1byte                | 1byte        | 1byte    | Nbytes          | 2bytes |
| 0x7E55        | 0x09+N       |                |                | 0x1F                 | 0x9F         | 0x00     | See table 7.4.1 |        |

Table 7.4.1 Transmission response frame parameters

| Response frames | Logo  | Logo    | Type of error | Type of error                      |
| --------------- | ----- | ------- | ------------- | ---------------------------------- |
| nbytes          | 1byte | 1byte   | 1byte         | 1byte                              |
| mbytes          | 0x00  | Success | 0x00          | No errors                          |
| 0bytes          | 0x01  | Failure | 0x01          | Label detected error               |
| 0bytes          | 0x01  | Failure | 0x02          | CRC error for data returned by tag |
| 0bytes          | 0x01  | Failure | 0x03          | Label not responding               |

## Appendix A CRC16 Checksum C Program Code

```
// #define RUF_MASK 0x80 //x^16 + x^12 + x^5 + 1 // #define POLYNOMIAL 0x8408 #define PRESET_VALUE 0xFFFF #define CHECK_VALUE 0xF0B8 #define CALC_CRC 0x1 #define CHECK_CRC 0x0 // unsigned calc_crc( unsigned int byte_len, unsigned int *data_byte) { unsigned int current_crc_value; unsigned int i,j; current_crc_value=PRESET_VALUE; for(i=0;i<byte_len;i++) { current_crc_value=current_crc_value^data_byte[i]; for(j=0;j<8;j++) { if(current_crc_value&0x0001) { current_crc_value=(current_crc_value>>1)^POLYNOMIAL; } else { current_crc_value=(current_crc_value>>1); } } } current_crc_value = ~current_crc_value; return(current_crc_value); }
```
