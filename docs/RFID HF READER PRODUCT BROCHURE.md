## Technical Document

Technical Document Name ：

RFIDStation. User Manual

Technical document number:

Edition ：

V2.0.1.1

Preparation.

Review.

Sign .

Standardization.

Approve .

## The    list.

1.Overview. ...............................................................................................................................  1

| 2. Interface Introduction............................................................................................................2                                                                                                      |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 2.1 Communication settings..............................................................................................3                                                                                                                   |
| 2.1.1 Serial Port settings............................................................................................3                                                                                                                     |
| 2.1.2 USB Port settings .............................................................................................3                                                                                                                      |
| 2.1.3 Network Port Settings ......................................................................................4                                                                                                                         |
| 2.1.4 Communication Fault Handling.......................................................................5                                                                                                                                  |
| 2.2 Parameter configuration..............................................................................................6                                                                                                                  |
| 2.2.1 Short range ISO15693 reader parameters ........................................................8                                                                                                                                      |
| 2.2.2 Middle range and long range ISO15693 reader parameters...........................10                                                                                                                                                   |
| 2.2.3 ISO14443 parameter configuration................................................................12                                                                                                                                    |
| 2.3 Reader control...........................................................................................................13                                                                                                             |
| 2.4 Reader information....................................................................................................13                                                                                                                |
| 3. Label operation ...................................................................................................................15                                                                                                    |
| 3.1 ISO15693 label operation .........................................................................................15                                                                                                                    |
| 3.1.1 UID output .....................................................................................................15                                                                                                                    |
| 3.1.2 Label operation 1............................................................................................15                                                                                                                       |
| 3.1.3 Label operation 2............................................................................................18                                                                                                                       |
| 3.1.4 Passthrough ....................................................................................................19                                                                                                                    |
| 3.1.5 Direct operation of labels ...............................................................................20                                                                                                                          |
| 3.1.6 IM operation...................................................................................................22                                                                                                                     |
| 3.1.7 Channel gate...................................................................................................24                                                                                                                     |
| 3.2 ISO14443A label operation.......................................................................................25 3.2.1 Information output .........................................................................................25 |
| 3.2.2 M1 operation Ⅰ ..............................................................................................27                                                                                                                       |
| 3.2.3 M1 operation II                                                                                                                                                                                                                       |
| ..............................................................................................30                                                                                                                                            |
| ESAM.............................................................................................................33                                                                                                                         |
| 3.2.4 NTag operation （ M0 operation ） .................................................................31                                                                                                                                   |
| 3.2.5                                                                                                                                                                                                                                       |
| 3.2.8 Intelligent operation .......................................................................................38                                                                                                                       |

## 1. Overview.

【 RFIDStation 】 is an operating software demo that designed for high frequency reader of ISO15693 and ISO14443 protocols. Users will understand the functions of high frequency reader products based on ISO15693 and ISO14443 protocols quickly through  this  software.  This  software  Demo  currently  known  to  support  bellow devices: M321 、 M321A 、 M321B 、 M324 、 M324U 、 M325 、 M325Y 、 M327 、 D322 、 D322p 、 D322p 、 D322ED322E 、 D322Y 、 D322SE 、 D322SY 、 D330S 、 D330N 、 D330L 、 D332 、 D332N 、 D334A 、 D343 、 D343X 、 D335X 、 R321 、 R321E 、 R321Y 、 R343D 、 R331 、 R331L 、 R3332 、 R332N 、 R332A 、 R342 、 R342N 、 R345 、 R345H 、 R342 、 R343D 、 R342N etc.

## 2. Interface Introduction

Open 【 RFIDStation 】 , the interface is as Figure 2.1:

Figure 2.1 RFIDStation main interface

<!-- image -->

【 RFIDStation 】 It supports ISO15693 and ISO14443 A/B dual protocols. The main interface includes five areas: communication setting area, parameter configuration area, data display area, tools area and label operation area.

Communication  setting  area: Select USB,  serial port (RS232/RS485)  or network port (RJ45) according to the interface type supported by the reader.

Configuration parameter area: Configure the parameters related to ISO15693 and ISO14443 protocols.

Data display area: Displays communication data between the DEMO and the reader.

Label operation: Operates (read UID, read data block, write data block, etc.)  label (supports ISO15693 or ISO14443 protocol).

The communication setting area, configuration parameter area, and the DEMO's UID reading, data block reading/writing and pass-through for ISO15693 and ISO14443A tags are described in more detail in a later section.

## 2.1 Communication settings

## 2.1.1 Serial Port settings

As  shown  in  Figure  2.2,  select  'COM'  for  port.  Please  refer  to  the  device manager for serial port selection. Select 38400-8-N-1 baud rate (factory default baud rate is 38400bit/s, fixed 8-bit data length, 1-bit stop bit, no parity bit). Ensure that the serial  port  cable  is  connected  properly.  Click  "Open"  to  complete  the  serial  port setting.  The  software  reads  the  device  version  and  displays  it  in  the  display  area (example device: D334A).

Figure 2.2 Serial Port settings

<!-- image -->

## 2.1.2 USB Port settings

As  shown in  Figure 2.3,  s elect "USB" for port, click "open" to do the USB port settings.  The  software  reads  the  device  version  and  displays  it  in  the  display  area (example device: R321). USB port supports simultaneous access of multiple devices.

Figure 2.3 USB connector settings.

<!-- image -->

## 2.1.3 Network Port Settings

As shown in Figure 2.4, select 'TCP' for port, fill in the device parameters for IP address  and  port.  (IP  address  and  port  information  can  be  looked  up  by  using 【 DeviceComTool 】 software's Network Port Parameter Function. 【 RFIDStation 】 only supports TcpSever mode. The IP address of the upper computer and the IP address of the  device  should  be  in  the  same  network  segment).  Click  'Open'  to  complete network port setting,  and  software  reads  the  device  version  and  displays  it  in  the display area (example device: D322p) .

Figure 2.4 Network Port Settings

<!-- image -->

## 2.1.4 Communication Fault Handling

If there is no communication between the device and Demo when in use, fault handling is as below:

- ① If  it  is  serial  port  connection  mode,  check  whether  the  COM  port  of  the device is correctly selected (check through device management), and whether the  baud  rate  is  selected  correctly  (the  general  factory  configuration  is 38400bit/s. If the baud rate communication fails, select 3 baud rates to try to communicate).  Set  the  device  address  the  broadcast  address:  FFFF  for troubleshooting.
- ② If  it  is  network  port  cnnection  mode,  check  whether  IP  address  and  port information are correct. (IP address and port information can be looked up by using 【 DeviceComTool 】 software's Network Port Parameter Function. 【 RFIDStation 】 only supports TcpSever mode.)
- ③ If both of the previous communication modes fail, restart the reader, restart the Demo, and then try the communication again;
- ④ Check whether the serial port cable itself can communicate well;
- ⑤ Check whether the port of the upper computer is correctly connected;
- ⑥ Check  whether  the  device's  IP  address  conflicts  with  the  upper  machine  or whether it is in the same network segment.

## 2.2 Parameter configuration

The parameter configuration consists of three parts:

The first part includes the selection of 'protocol type', 'command mode', 'label control' and 'buzzer control'.

The second part includes the setting of "device new address", "AFI mode", and "baud rate control".

The third part includes "set parameters" and "get parameters".

When users use it for the first  time,  please  click  "get  parameters"  to  view  the parameter  configuration  of  the  reader.  After  that,  users  can  select  parameters according  to  their  own  requirements,  and  click  "set  parameters"  to  complete parameter settings.

The definition of specific parameters is shown in the table below:

| Parameters    | Options    | Description                                                                                                                                                                                             |
|---------------|------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Protocol Type | ISO 15693  | Select the ISO 15693 protocol as needed                                                                                                                                                                 |
| Protocol Type | ISO 14443A | Select the ISO 14443A protocol as needed                                                                                                                                                                |
| Protocol Type | ISO 14443B | Select the ISO 14443B protocol as needed                                                                                                                                                                |
| Command mode  | Automatic  | When the RF is turned on, the reader automatically sends the Inventory command to count the labels                                                                                                      |
| Command mode  | Trigger    | After the RF is turned on, the reader waits for the command to count labels                                                                                                                             |
| Label control | Silent     | After the reader gets the label UID, it sets the label silent so that the label no longer responds to the reader's Inventory command unless the label leaves the antenna RF field and then enters again |
| Label control | Not silent | After the reader gets the label UID, the label still responds to the reader's Inventory command, which is typically used to test the                                                                    |

|                   |               | reading distance of the label                                                                              |
|-------------------|---------------|------------------------------------------------------------------------------------------------------------|
| Buzzer control    | Ban           | The buzzer does not respond (no sound) when the reader recognizes the label for the corresponding protocol |
| Buzzer control    | Enable        | When the reader recognizes the label for the corresponding protocol, the buzzer responds (with a 'beep')   |
| Device address    | 0x0000~0xFFFF | Reader device address, where 0xFFFF is the broadcast address                                               |
| AFI mode          | Ban           | AFI domain is banned in inventory command fram                                                             |
| AFI mode          | Enable        | AFI domain is enabled in inventory command fram                                                            |
| Baud rate control | 9600          | Baud rate: 9600 bit/s .                                                                                    |
| Baud rate control | 38400         | Baud rate: 38400 bit/s .                                                                                   |
| Baud rate control | 115200        | Baud rate: 115200 bit/s .                                                                                  |

## 2.2.1 Short range ISO15693 reader parameters

As shown in figure 2.5, select 'ISO15693' for protocol type, 'trigger' for command mode, 'silent' for  label  control,  'enable'  for  the  buzzer,  'banned'  for  AFI  mode,  38400  for  baud  rate.  After these  settings,  click  'parameter  configuration'  to  complete  the  configuration  of  ISO15693 protocol.

Figure 2.5 ISO15693 parameter configuration

<!-- image -->

Then  select  'ISO15693'  protocol  as  shown  in  figure  2.6,  and  an  'ISO15693' label operation window pops up as shown in figure 2.7.

<!-- image -->

Figure 2.6 Label Operation selection

<!-- image -->

## Figure 2.7 ISO15693 Label Operation window

## Attention:

① If ISO15693 label operation window shown in Figure 2.7 was closed unexpectedly during operation,

click the label operation selection box shown in Figure 2.6 again.

## 2.2.2 Middle range and long range ISO15693 reader parameters

As  shown in  figure  2.8,  select  'ISO15693'  for  protocol  type,  'automatic'  for  command  mode, 'silent' for label control, 'enable' for the buzzer, 'banned' for AFI mode, 38400 for baud rate. After these settings, click 'parameter configuration' to complete the configuration of ISO15693 protocol.

Figure 2.8 ISO15693 parameter configuration

<!-- image -->

Then  select  'ISO15693'  protocol  as  shown  in  figure  2.9,  and  an  'ISO15693' label operation window pops up as shown in figure 2.10

Figure 2.9 Label Operation selection

<!-- image -->

Figure 2.10 ISO15693 Label Operation window

<!-- image -->

## Attention:

① If ISO15693 label operation window shown in Figure 2.10 was closed unexpectedly during operation, click the label operation selection box shown in Figure 2.9 again.

② Not all devices support reading data stored in the reader, i.e. it is possible that the UID information reading failed.

## 2.2.3 ISO14443 parameter configuration

As shown in figure 2.11, select 'ISO14443A' for protocol type, 'trigger' for command mode, 'no silent' for label control, 'enable' for the buzzer, 38400 for baud rate. After these settings, click  'parameter  configuration'  to  complete  the  configuration  of  ISO14443  protocol.  (  below device D322 as example)

Figure 2.11 ISO14443 protocol reader configuration

<!-- image -->

Then select 'ISO14443A' protocol as shown in figure 2.12, an 'ISO14443A' label operation window pops up as figure 2.13.

<!-- image -->

Figure 2.12

Label Operation selection

Figure 2.13 ISO14443 Label Operation window

<!-- image -->

Attention:

If ISO14443 label operation window shown in Figure 2.13 was closed unexpectedly during operation, click the label operation selection box shown in Figure 2.12 again.

## 2.3 Reader control

As shown in figure 2.14, reader control interface is composed of three areas: RF control, antenna control and power control.

RF control ： turn on/off RF output; reset RF. (start RF output 20ms after RF is turned off)

Antenna control ： Number of antennas should be the same as device actual number of antennas, so that the antenna to be connected can be selected.

Power control ： select the number of corresponding antenna, and set the level of power (from low to high LV0 、 LV1 、 LV2 、 LV3 ).

Figure 2.14 Reader control

<!-- image -->

Attention ：

- ① Only multiple antennae supported devices have antennae control fuction, otherwise it is invalid;
- ② Only power adjustable devices have power control function, otherwise it is invalid.

## 2.4 Reader information

After  the  device  is  connected  successfully,  device  and  software  and  hardware

information  can  be  obtained  by  click  'OK'  button  in  'reader  information'  area,  as shown in figure 2.15.

Figure 2.15 Reader control

<!-- image -->

<!-- image -->

## 3. Label operation

## 3.1 ISO15693 label operation

Based  on  ISO15693  parameter  configuration  according  to  chapter  2.2.1,  ISO15693  label operation function of the software is introduced as blow.

## 3.1.1 UID output

Put an ISO15693 label in reader working field. Set up the parameters, reset RF, and click 'read' button in ISO15693 operation frame, UID read displays in 'UID information' frame, as shown in figure 3.1. (device D322 as example)

Figure 3.1 read ISO15693 UID

<!-- image -->

## 3.1.2 Label operation 1

Read data block ： a label's UID must be selected before the label's data block is read. (as  shown  in  figure  3.1,  click  'label  UID'  in  'UID  information  frame'  with  left mouse button, 'UID information' frame on top changes to the label UID). Click 'read', and 'data' frame displays label's data block, as shown in figure 3.2.

Figure 3.2 Read label's data block

<!-- image -->

Attention ： as shown in figure 3.2, when inputting data block's head address and block number, the data format should be hexadecimal, and the data length should be 1 byte.

Write data block ： a label's UID must be selected before the label's data block is written (as shown in figure 3.1, click 'label UID' in 'UID information frame' with left mouse button, 'UID information' frame on top changes to the label UID). Click 'write'.  Data  block  is  written  successfully  if  the  return  result  of  multiple  blocks writing in 'output' frame is not blank. As it is shown in figure 3.3.

Figure 3.3 write ISO15693 data block

<!-- image -->

format should be hexadecimal, and the data length should be 1 byte.

- ① Data format written in label is hexadecimal;
- ② The length of a data block is 4 byte, so the length of the data written in a 'data' frame must be 4 times of the number of blocks;
- ③ Block address must be within the label's actual memory address;
- ④
- If the address of the data block to be written to the label is locked and cannot be written, the "output" frame shows that the write multiple data block returns blank;
- ⑤ The  lock  block  operation  is  irreversible.  Once  the  data  block  of  the  label  is  locked,  the  address corresponding to the label will never be written into data.

## 3.1.3 Label operation 2

As  shown  in  figure  3.4, 'label  operation  2'  is  composed  of  four  areas:  AFI operation, EAS operation, DSFID operation and information acquisition.

AFI  operation:  input  data  format  should  be  hexadecimal,  and  the  data  length should be 1 byte. Operation is irreversible.

EAS operation: e lectronic anti-theft system.

DSFID operation: input data format should be hexadecimal, and the data length should be 1 byte. Operation is irreversible.

Information acquisition ： click 'OK' and get label information.

Figure 3.4 ISO15693 label special function mark operation

<!-- image -->

## 3.1.4 Passthrough

Passthrough function enables users operate the cards using readers directly. The operation  specification  must  strictly  comply  with  ISO15693  protocol.  Open  the Passthrough  page,  send  the  data  frame  to  the  label,  and  receive  the  information returned by the label. It is shown as figure 3.5. (device D322 as example)

Figure 3.5    ISO15693 label passthrough

<!-- image -->

Attention ：

```
① Label response time ： :15000 :15000 : 20000 Inventory s Read s Write s   
```

- ② data format is hexadecimal, and no interval between bytes, e.g. 120325…

## Examples ：

```
: E00222252B831BE6 UID : 260100 0000E61B832B252202E0 Inventory  
```

```
: >>>2221E61B832B252202E00022222222 <<<00 Write Block  : 2220E61B832B252202E000 0022222222 Read Block    : 222BE61B832B252202E0 000FE61B832B252202E000003F0322 Read Inf   
```

## 3.1.5 Direct operation of labels

As  it  is  shown  in  figure  3.6,  this  function  can  operate  batch  label  directly  such  as  UID reading,  data  block  reading,  data  block  writing,  AFI  writing  without  reading  label  UID  first (support multiple label devices). This function is applicable to some of the M-series, D-series and R-Series devices supporting ISO15693 protocol. (D322 、 D322p 、 D322E 、 D322Y 、 D322SE 、 D322SY 、 D330S 、 D330N 、 D330L 、 D332 、 D332N 、 D343 、 D343X 、 D335X 、 R343D etc. ）

Figure 3.6.0 Function select

<!-- image -->

UID reading ： After the device communicates with the upper computer normally, put the label in the device's working field, and click 'start' to output the label UID and time used.

Block  reading ： After  the  device  communicates  with  the  upper  computer normally, put the label in the device's working field, and click 'start' to output the label UID and time used. The block reading address and number can be set.

Block  writing ： After  the  device  communicates  with  the  upper  computer normally, put the label in the device's working field, and click 'start' to output the label UID and time used. The block reading address and number can be set.

AFI writing ： AFI value can be written in the range of 0-255. After the device communicates  with  the  upper  computer  normally,  put  the  label  in  the  device's working field, and then input AFI value, and click 'start' to output the label UID and time used.

## 3.1.6 IM operation

As it is shown in figure 3.7, this function enables batch labels operation (use multiple labels supported devices) of UID reading, data block reading without reading the label UID first. This function is applicable to some R-Series devices of our company that support ISO15693 protocol （ R332 、 R332N 、 R342 、 R342N 、 R345 、 R345H etc. ）

UID reading : After the device communicates with the upper computer normally, put the label in the device's working field, and select the antenna to work (it can be single antenna or multi round scanning antenna). Click 'start' to output the label UID and time used.

Block reading ： After the device communicates with the upper computer normally, put the label in the device's working field, and select the antenna to work (it can be single antenna or multi round scanning antenna). Click 'start' to output the label UID and time used. The address and number of read blocks can be set.

Figure 3.7 label reading of IM operation

<!-- image -->

Figure 3.8 select antenna to work of IM operation

<!-- image -->

## Attention ：

- ① To avoid antenna damage, do not turn on the RF to the port which doesn't connected to an antenna.
- ② Process of multiple antennae turning: select antenna --reset RF --counting label times completed

or timeout --turn off RF --switch antenna

## 3.1.7 Channel gate

As it is shown in figure 3.9, make single select or multiple select to the antennae 可 ports (corresponding to the antenna connected with the reader). Click 'set' so that the  selection  is  confirmed.  Select  'enable  scan  antennae'  and  confirm  selection. Click 'start display alarming UID', as a result label UID is displayed. This function is  applicable  to  some  R-Series  devices  of  our  company  that  support  ISO15693 protocol (R342 、 R342N etc.).

Figure 3.9 select antenna

<!-- image -->

"Disable  scanning  antenna  /  enable  scanning  antenna"  is  to  turn  off  and  turn  on  antenna scanning function respectively. Select "enable scanning antenna", click "set", and the reader will start to install the selected antenna round scanning labels in antenna field.

"Start displaying alarm UID" is a special AFI alarm function, which gives alarm prompt to the label with specific AFI value written in, and displays its UID in the output port below.

## 3.2 ISO14443A label operation

Based on ISO14443A parameter configuration according to chapter 2.2.2, ISO14443A label operation function of the software is introduced as blow.

## 3.2.1 Information output

Put an ISO14443A label in reader working field. Set up the parameters, and click 'read'  button  in  ISO14443A  operation  'UID  output'  frame.  UID  read  displays  in 'UID information' frame, as shown in figure 3.10. (device D322 as example)

Read UID sending instruction: REQA-AC-SELECT three instructions. If the UID is read successfully, the label will be in active state. If the first read UID is successful, the  second  read  UID  will  send  the  same  instruction.  According  to  ISO14443A protocol, the label returns to the IDLE state, so the read fails.

Figure 3.10 read ISO14443A label UID

<!-- image -->

Attention ：

- ① Read: this operation (read label UID) is a necessary prerequisite for other operations;

- ② Suspend: the suspended label will not be able to perform other operations (unless you return it to the factory to read the label UID after leaving the factory; or change the label mode to 'ALL'l). Please refer to ISO14443A protocol for details.

## 3.2.2 M1 operationⅠ

Data  block  writing: in M1  operationⅠ, write  the  head  "address"  of  the  data block. The key type ( KeyA/KeyB ) and key (6 bytes) strictly comply with ISO14443A protocol  (label  factory  default  key:  FFFFFFFFFFFF).  Click  the  "write  data  block" button, the "output" window returns "operation successful", which indicates that the write data block is successful.

Figure 3.11 write M1 data block

<!-- image -->

Attention ：

- ① Before  this  operation,  the  label  UID  must  be  read  once  (entering  the  third  layer),  and  after  the operation error, the label UID must be read again;
- ② The input data format is hexadecimal;
- ③ Block 3 of each sector is the cipher area, which should be written carefully. As shown in Figure 3.12;
- ④ Block 0 of sector 0 is the manufacturer flag code. If you fill in 00 in the address column, a write error will occur. Then a startover from reading UID is needed after the error;
- ⑤ The block address must be within the label's actual memory address. The number of blocks has been set to 1 by default. One block (16bytes) is written at a time.

Attention ：

<!-- image -->

Figure 3.12 M1 card storage structure

<!-- image -->

Read data block ： in M1opertion I, write the head "address" of the read data block. The key type ( KeyA/KeyB ) and key (6 bytes) strictly comply with ISO14443A protocol  (label  factory  default  key:  FFFFFFFFFFFF).  Click  the  "read  data  block" button, the "output" window returns "operation successful", which indicates that the read data block is successful. As shown in figure 3.13.

Figure 3.13 read data block

<!-- image -->

operation error, the label UID must be read again;

- ② The block address must be within the label's actual memory address. The number of blocks has been set to 1 by default. One block (16bytes) is read at a time.

## 3.2.3 M1 operation II

As shown in figure 3.14, in M1opertion II, write the head "address" of the value operation.  The  key  type  ( KeyA/KeyB ) and  key  (6  bytes)  strictly  comply  with ISO14443A protocol (label factory default key: FFFFFFFFFFFF). Click 'read value, write  value,  decrease  value,  add  value,  transfer'  button,  and  the  "output"  window returns "operation successful", which indicates that the value operation is successful.

Figure 3.14 M1operation II

<!-- image -->

Attention ：

- ① Before  this  operation,  the  label  UID  must  be  read  once  (entering  the  third  layer),  and  after  the operation error, the label UID must be read again;
- ② This value address and data block address are not of the same concept.

## 3.2.4 NTag operation （ M0 operation ）

Read data page: Write the head "address" and "number" of the data page, click the "read data  page"  button,  and  "success"  in  the  "output"  window  indicates  that  the  data  page  is  read successfully. As shown in Figure 3.15.

Figure 3.15 read M0 label data page

<!-- image -->

Write data page: Write the head "address" and "number" of the read data block. Click the "write data page" button, and "success" is returned in the output window, indicating that the data page is successfully written, as shown in Figure 3.16.

Figure 3.16 M0 label write data page

<!-- image -->

## Attention ：

- ①
- Before  this  operation,  the  label  UID  must  be  read  once  (entering  the  third  layer),  and  after  the operation error, the label UID must be read again;
- ② The input data format is hexadecimal, and M0 card data page address starts from 04;
- ③ The page address must be within the label's actual memory address;
- ④ The length of the input data is 4 times of the number, that is, a data page is of 4 bytes.

## 3.2.5 ESAM

As shown in figure 3.17, the function of this interface can control ESAM1/ESAM2  to  power  on,  power  off  or  reset  (the  device  in  this  example  is M327).

Figure 3.17 ESAM

<!-- image -->

## 3.2.6 APDU

As shown in figure 3.18, at this time, the test label is CPU card. Click "Rats", and the label information will be displayed in the display frame. For details, please refer to ISO / IEC 14443-4 protocol (example device: R321).

Figure 3.18 RATS

<!-- image -->

Attention ：

- ① Before this operation, the label UID must be read once (entering the third layer), and after the operation error, the label UID must be read again.

As shown in Figure 3.19, select the index type to be communicated, edit the data in the data frame input box, and click "APDU" and the Information for index type communication returned. For details, please refer to ISO/IEC7816-1/2/3/4 protocol (example device: M327).

Figure 3.19 APDU

<!-- image -->

## Attention ：

- ① Before this operation, the power on operation in section 3.2.5 must be performed, otherwise the communication fails.

## 3.2.7 Passthrough

The passthrought function allows users to operate the card directly through the reader, and the operation specification must strictly comply with ISO14443A protocol. Open the passthrough page, send the data frame (the data content of REQA is "26") to the label, and receive the information returned by the label, as shown in Figure 3.20 (example device is D322).

Figure 3.20 passthrough

<!-- image -->

attention ：

s

<!-- formula-not-decoded -->

- ② Label response frame length is not required;
- ③ Click Crc button in Figure 3.20 to add Crc verification;
- ④ The number of bits sent by the last byte strictly follows the protocol specification;
- ⑤ The data is sent in hexadecimal format with no space between bytes, such as 120325…

## Example ：

short range reader

```
UID:0004 04 1E06CEF7 （ M1 card ） Inventory: ＞＞＞ 26 （ Bit number of last byte sent ： 07 ） ＜＜＜ 0400 ＞＞＞ 9320 （ Bit number of last byte sent ： 00 ） ＜＜＜ 1E06CEF721 ＞＞＞ 93701E06CEF721+CRC （ Bit number of last byte sent ： 00 ） ＜＜＜ 68B0BE
```

Please refer to your label manual for label timeout, label response

Middle/long range reader ： frame length, and the number of bits sent in the last byte.

## 3.2.8 Intelligent operation

Put an ISO14443A label into the reader's workplace, set the parameters, select the working  mode  "read  UID  /  read  block  /  write  block"  in  the  "intelligent  operation" column of the ISO14443A operation box, and click the "start" button. The read UID will be displayed in the "result" box, and the read data block will be displayed in the "data block" box, as shown in Figure 3.21 (example device: D334A).

Figure 3.21 IM operation

<!-- image -->

## Attention ：

- ① When "read UID" is selected, the address and number of blocks do not need to be changed;
- ② When "read block" or "write block" is selected, the range of data block address should be defined according to the type of test label (M1 card data block address starts from 01, M0 card data page address starts from 04);
- ③ Check "continuous operation" to repeat one of the three operations of "read UID", "read block" and "write block";
- ④ When "write block" is checked, the data to be written into the data block is edited in the "data" box in Figure 3.20. The input data format is hexadecimal, and the data length is determined by the type of label and the number of blocks to be written.