import usb.core
import usb.util
import sys

# Look for our specific RFID reader
RFID_VENDOR_ID = 0x0505   # AnyID HID
RFID_PRODUCT_ID = 0x5050  # RFID Reader
    

def find_all_hid_devices():
    """Find and print information about all HID devices connected to the system"""
    print("\n=== Scanning for HID Devices ===")
    
    # Find all USB devices
    devices = usb.core.find(find_all=True)
    hid_devices = []
    
    for device in devices:
        # Check each configuration/interface to see if it's HID
        try:
            for cfg in device:
                for intf in cfg:
                    if intf.bInterfaceClass == 3:  # HID Class = 3
                        hid_devices.append(device)
                        print(f"\nFound HID Device:")
                        print(f"  VID: {device.idVendor:04x}")
                        print(f"  PID: {device.idProduct:04x}")
                        print(f"  Manufacturer: {usb.util.get_string(device, device.iManufacturer) if device.iManufacturer else 'Unknown'}")
                        print(f"  Product: {usb.util.get_string(device, device.iProduct) if device.iProduct else 'Unknown'}")
                        break
                if device in hid_devices:
                    break
        except:
            # Skip devices that can't be accessed
            continue
            
    return hid_devices

def dump_device_info(device):
    """Print detailed information about a specific USB device"""
    print(f"\n=== Detailed Device Info ===")
    print(f"Device ID: {device.idVendor:04x}:{device.idProduct:04x}")
    try:
        print(f"Manufacturer: {usb.util.get_string(device, device.iManufacturer)}")
        print(f"Product: {usb.util.get_string(device, device.iProduct)}")
        print(f"Serial Number: {usb.util.get_string(device, device.iSerialNumber)}")
    except:
        print("Could not read string descriptors")
    
    print(f"\nDevice Details:")
    print(f"  Device Class: {device.bDeviceClass}")
    print(f"  USB Version: {device.bcdUSB >> 8}.{device.bcdUSB & 0xff}")
    print(f"  Max Packet Size: {device.bMaxPacketSize0}")
    print(f"  Configurations: {device.bNumConfigurations}")
    
    # Print configuration details
    for cfg in device:
        print(f"\nConfiguration {cfg.bConfigurationValue}:")
        print(f"  Max Power: {cfg.bMaxPower * 2}mA")
        
        for intf in cfg:
            print(f"\n  Interface {intf.bInterfaceNumber}:")
            print(f"    Class: {intf.bInterfaceClass} {'(HID)' if intf.bInterfaceClass == 3 else ''}")
            print(f"    Subclass: {intf.bInterfaceSubClass}")
            print(f"    Protocol: {intf.bInterfaceProtocol}")
            
            for ep in intf:
                print(f"    Endpoint {ep.bEndpointAddress:02x}:")
                print(f"      Type: {'IN' if usb.util.endpoint_direction(ep.bEndpointAddress) else 'OUT'}")
                print(f"      Max Packet Size: {ep.wMaxPacketSize}")
                print(f"      Interval: {ep.bInterval}ms")

def main():
    print("=== HID Device Scanner ===")
    hid_devices = find_all_hid_devices()
    
    if not hid_devices:
        print("\nNo HID devices found!")
        return
    
    print("\n=== Searching for RFID Reader ===")
        

    rfid_reader = usb.core.find(idVendor=RFID_VENDOR_ID, idProduct=RFID_PRODUCT_ID)
    
    if rfid_reader:
        print(f"\nFound RFID Reader (VID={RFID_VENDOR_ID:04x}, PID={RFID_PRODUCT_ID:04x})")
        dump_device_info(rfid_reader)
    else:
        print(f"\nRFID Reader not found! (Looking for VID={RFID_VENDOR_ID:04x}, PID={RFID_PRODUCT_ID:04x})")

if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\nExiting...")
    except Exception as e:
        print(f"\nError: {e}")