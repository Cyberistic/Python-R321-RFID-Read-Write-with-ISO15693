# Special thanks to:
# https://github.com/charlysan/pyrfidhid/wiki/Reverse-Engineering-A-USB-HID-RFID-Reader-Writer

import usb.core
import usb.util
import time

# ========== CONFIGURATION ==========
# I got the vendor/product ID using:
# $ system_profiler SPUSBDataType
# Or you can use the find_hid_devices.py script 


VENDOR_ID = 0x0505
PRODUCT_ID = 0x5050
SLEEP = 0.05



# ========== HELPER FUNCTIONS ==========

def sleepy():
    """Sleep to avoid USB errors"""
    time.sleep(SLEEP)

def init_device():
    """Initialize RFID device and handle USB setup
    Returns: 
        usb.core.Device or None: Initialized device if successful, None if failed
    """
    try:
        # Initialize device
        dev = usb.core.find(idVendor=VENDOR_ID, idProduct=PRODUCT_ID)
        if dev is None:
            print("Device not found")
            return None
            
        print("Device found")
        
        # Set configuration and claim interface
        dev.set_configuration()
        interface = 0
        if dev.is_kernel_driver_active(interface):
            dev.detach_kernel_driver(interface)
        usb.util.claim_interface(dev, interface)
        
        return dev

    except usb.core.USBError as e:
        print(f"USB Error during initialization: {e}")
        return None
    except Exception as e:
        print(f"Error during initialization: {e}")
        return None

def cleanup_device(dev, interface=0):
    """Clean up USB device resources
    Args:
        dev: USB device to cleanup
        interface: Interface number to release (default 0)
    """
    try:
        if dev:
            usb.util.release_interface(dev, interface)
            if dev.is_kernel_driver_active(interface):
                dev.attach_kernel_driver(interface)
    except:
        pass


def calc_crc(data_bytes):
    """Calculate CRC16 as specified in protocol
    CRC is calculated from frame length byte to end of parameters"""
    POLYNOMIAL = 0x8408
    PRESET_VALUE = 0xFFFF
    
    current_crc_value = PRESET_VALUE
    
    for byte in data_bytes:
        current_crc_value = current_crc_value ^ byte
        for _ in range(8):
            if current_crc_value & 0x0001:
                current_crc_value = (current_crc_value >> 1) ^ POLYNOMIAL
            else:
                current_crc_value = (current_crc_value >> 1)
    
    return ~current_crc_value & 0xFFFF


def add_crc(cmd):
    """Add CRC to command"""
    # Calculate CRC from length byte to end of parameters
    crc = calc_crc(cmd[3:])  # Start from length byte after header (index 3)
    crc_high = (crc >> 8) & 0xFF  # High byte
    crc_low = crc & 0xFF         # Low byte
    # Append CRC to command
    cmd.append(crc_low)
    cmd.append(crc_high)
    return cmd


def pad_to_64_bytes(data):
    """Pad data to 64 bytes with zeroes"""
    if len(data) < 64:
        data += [0x00] * (64 - len(data))
    return data

def uid_to_bytes(uid):
    """Convert UID string to bytes"""
    # Example UID: E0040150CABD51B9
    # Convert back to original format
    uid_bytes = []
    for i in range(0, len(uid), 2):
        byte = int(uid[i:i+2], 16)
        uid_bytes.append(byte)

    return reversed(uid_bytes)



# ========== MAIN FUNCTIONS ==========

def read_tag_UID(dev, mode="passive"):
    """Read tag UID
    Based on sniffed Packet 11:
    0C 7E 55 09 00 00 01 00 11 00 00 7D FB
    """


    sleepy()
    # Command from packet 11
    write_cmd = [
        0x0C, # Length + 3 
        0x7E, 0x55, # Header
        0x09, # Length from src to CRC inclusive
        0x00, 0x00,  # Source address
        0x01, 0x00,  # Target address   
        0x11, # Command (read tag UID passive)
        0x00, # Reserved
        0x00, # Normal mode
    ] 

    if mode == "active":
        write_cmd[8] = 0x10
    


    # Add CRC // should equal  0x7D, 0xFB
    write_cmd = add_crc(write_cmd)

    # pad to 64 bytes
    write_cmd = pad_to_64_bytes(write_cmd)

    # Write command (Endpoint 0x01)
    dev.write(0x01, write_cmd)
    
    # Read response (Endpoint 0x82)
    response = dev.read(0x82, 64)

    # Parse tag data from response (packet 13 format)
    if response[1] == 0x7E and response[2] == 0x55:
        # has to start with 0xE0
        if response[18] != 0xE0:
            return False
        # Example result: E0040150CABD51B9
        uid_bytes = response[11:19]  # Changed from 10:19 to get exactly 8 bytes
        return ''.join([f"{x:02X}" for x in reversed(uid_bytes)])
    return False




def read_label_data(dev):
    """Reader reads tag UID then reads tag data block directly"""
    # useless for me, but here for reference

    # params is:
    # reserved 0x00
    # mode,  0x01 = read UID only, 0x03 = read UID + blocks
    # block count, 0x01 to 0x04
    # address 4 bytes

    sleepy()
    params = [
        0x00, # Reserved
        0x01, # Mode (read UID + blocks)
        0x04, # Block count
        0x00, 0x01, 0x02, 0x03, # Address (4 bytes)
    ]

    write_cmd = [
        0x12, # Length + 3
        0x7E, 0x55, # Header
        0x0F, # Length from src to CRC inclusive
        0x00, 0x00,  # Source address
        0x01, 0x00,  # Target address   
        0x30, # Command (4.13  Direct manipulation)
        0x00, # Reserved
        
    ] + params

    # Add CRC // should equal  0x7D, 0xFB
    write_cmd = add_crc(write_cmd)

    # pad to 64 bytes
    write_cmd = pad_to_64_bytes(write_cmd)

    # Write command (Endpoint 0x01)
    dev.write(0x01, write_cmd)
    
    # Read response (Endpoint 0x82)
    response = dev.read(0x82, 64)

    return ''.join([hex(x)[2:].upper() for x in response[1:]])



def read_data_multiple_blocks(dev, uid , start_block=0x00, num_blocks=0x10):
    """ Read data from multiple blocks 
    Based on sniffed packet 53"""

    # Reading addr 00 to addr 03 of our tag E0040150CABD51B9
    # 000051: Bulk or Interrupt Transfer (DOWN), 2025-04-19 04:18:26.299431 +83.962212. (1. Device: AnyID Reader)
    #Pipe Handle: 0xffffd98b4c1ba5e0 (Endpoint Address: 0x1)
    # Send 0x40 bytes to the device
    # 15 7E 55 12 00 00 01 00 22 00 B9 51 BD CA 50 01 
    # 04 E0 00 03 1F 4C

    sleepy()
    # params is:
    # UID 8 bytes xxxxxxxxxxxxxxE0
    # Header address (1 byte)
    # Number of blocks = N (1 byte), N is 0 to 32. Each data block occupies 4 bytes. 
    # Note that max response size is 64 bytes, so can't read all blocks at once.

    # we will read
    params = [
        *list(uid_to_bytes(uid)), # UID (8 bytes)
        start_block, # Header address (1 byte)
        num_blocks, # Number of blocks 
    ]

    write_cmd = [
        0x15, # Length + 3
        0x7E, 0x55, # Header
        0x12, # Length from src to CRC inclusive
        0x00, 0x00,  # Source address
        0x01, 0x00,  # Target address   
        0x22, # Command (read data)
        0x00, # Reserved
    ] + params

        # Add CRC 
    write_cmd = add_crc(write_cmd)

    # pad to 64 bytes
    write_cmd = pad_to_64_bytes(write_cmd)

    # print(f"Sending command: {' '.join([hex(x)[2:].upper() for x in write_cmd])}")
    # Write command (Endpoint 0x01)
    dev.write(0x01, write_cmd)
    
    # Read response (Endpoint 0x82)
    response = dev.read(0x82, 64)

    # Check if response is valid
    if response[1] == 0x7E and response[2] == 0x55:
        # Example result: E0040150CABD51B9
        data_bytes = response[11:11 + num_blocks * 4]  # Read N blocks (4 bytes each)


        ascii_data = ''.join([chr(x) for x in data_bytes])
        return ascii_data

    return False


def write_data(dev, uid, string, start_block=0x00):
    """ Write data to multiple blocks 
    Based on sniffed packet 47"""

     # Writing HELLO in hex (68 65 6c 6c 6f) followed by ending string (F1F1F1) and writing 3 data blocks Addr 00 to 03
    # We got our tag UID and it is: E0040150CABD51B9

    # 000047: Bulk or Interrupt Transfer (DOWN), 2025-04-19 04:17:02.294784 +6.389560. (1. Device: AnyID Reader)
    # Pipe Handle: 0xffffd98b4c1ba5e0 (Endpoint Address: 0x1)
    # Send 0x40 bytes to the device
    #  21 7E 55 1E 00 00 01 00 23 00 B9 51 BD CA 50 01   
    #  04 E0 00 03 01 02 03 04 01 02 03 04 F1 F1 F1 F1   
    #  F8 48 00 00 00 00 00 00 00 00 00 00 00 00 00 00   
    #  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00   


    MAX_BLOCKS = 0x10 # todo: Make this dynamic

    # A bit harder since we need to calculate frame length beforehand
    # Frame length = 0x12 + 4*N where N is number of blocks

    # params is:
    # UID 8 bytes xxxxxxxxxxxxxxE0
    # Header address (1 byte)
    # Number of blocks = N (1 byte), N is 0 to 32. Each data block occupies 4 bytes.
    # Data to write [4 bytes per block] (4*N bytes) 

    # First we need to convert the string to bytes
    
    sleepy()
    string_bytes = string.encode('utf-8')

    # Make sure the string is not too long
    if len(string_bytes) > MAX_BLOCKS * 4:
        raise ValueError(f"String is too long, max length is {MAX_BLOCKS / 4} characters")
    # Pad the string to 4*N bytes
    string_bytes = string_bytes.ljust(MAX_BLOCKS * 4, b'\x00')

   
    params = [
        *list(uid_to_bytes(uid)), # UID (8 bytes)
        start_block, # Header address (1 byte)
        MAX_BLOCKS, # Number of blocks,
        *string_bytes, # Data to write (4*N bytes)
    ]

    # Calculate frame length 0x12 + 4*N
    frame_length = 0x12 + MAX_BLOCKS * 4

    write_cmd = [
        frame_length + 3, # Length + 3,
        0x7E, 0x55, # Header
        frame_length, # Length from src to CRC inclusive
        0x00, 0x00,  # Source address
        0x01, 0x00,  # Target address
        0x23, # Command (write data)
        0x00, # Reserved
    ] + params

    # Add CRC
    write_cmd = add_crc(write_cmd)
    # pad to 64 bytes
    write_cmd = pad_to_64_bytes(write_cmd)
    # print(f"Sending command: {' '.join([hex(x)[2:].upper() for x in write_cmd])}")
    # Write command (Endpoint 0x01)
    dev.write(0x01, write_cmd)

    # Read response (Endpoint 0x82)
    response = dev.read(0x82, 64)
    # Check if response is valid
    if response[1] == 0x7E and response[2] == 0x55:
        # if success, 0E 7E 55 0B 01 00 00 00 1F 23 00 00 00 E7 47
        # params byte 0x00 is success (based on sniff), 
        if response[11] == 0x00:
            print("Write successful")
            return True
        
    return False
    
    




# ========== USER INTERFACE FUNCTIONS ==========

def keep_getting_UID(dev):
    """My own implementation of active UID reading since the main one is not working"""
    while True:
        # print("No tag detected, retrying...")
        time.sleep(1)
        tag_uid = read_tag_UID(dev)
    
        if tag_uid:
            # I don't know why but this UID is always present and should be ignored
            print(f"Tag UID: {tag_uid}")
            time.sleep(2)
            return tag_uid
            
        
        
def input_string(dev):
    """Get string input from user"""
    string = input("Enter string to write to tag: ")
    while not string:
        print("String cannot be empty")
        string = input("Enter string to write to tag: ")

    uid = keep_getting_UID(dev)

    written = write_data(dev, uid, string)

    while not written:
        print("Failed to write data, retrying...")
        time.sleep(3)
        uid = keep_getting_UID(dev)
        print(f"Tag UID: {uid}")
        written = write_data(dev, uid, string)


def keep_reading_string(dev):
    """Read string from tag continuously"""
    while True:
        uid = keep_getting_UID(dev)

        if not uid:
            continue
        
        # Read data from multiple blocks
        response = read_data_multiple_blocks(dev, uid)
        if response:
            print(f"Data read: {response}")
        else:
            print("Failed to read data")
        time.sleep(5)  # Add a delay before the next read


# ========== EXAMPLE USAGE ==========



def usage1():
    # Read then write data to tag
    dev = init_device()
    if not dev:
        return

    try:
        # Read tag UID
        tag_uid = read_tag_UID(dev) 
        if not tag_uid:
            print("No tag found")
            return
            
        print(f"Tag UID: {tag_uid}")

        # Write sample data
        write_data(dev, tag_uid, "I hate you so much stupid rfid reader")
    
            
        # Read back the data
        if response := read_data_multiple_blocks(dev, tag_uid):
            print(f"Data read: {response}")
        else:
            print("Failed to read data")
   
    except usb.core.USBError as e:
        print(f"USB Error during operation: {e}")
    except Exception as e:
        print(f"Error during operation: {e}")
    finally:
        cleanup_device(dev)


# User interface to write first, then continuously read tags
def usage2():
    # Read then write data to tag
    dev = init_device()
    if not dev:
        return

    try:




        # Write sample data
        input_string(dev)

        time.sleep(5)
        
        # Continuously read tags
        keep_reading_string(dev)

    except usb.core.USBError as e:
        print(f"USB Error during operation: {e}")
    except Exception as e:
        print(f"Error during operation: {e}")
    finally:
        cleanup_device(dev)

if __name__ == "__main__":
    usage2()