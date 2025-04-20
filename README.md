# Python R321 RFID Read/Write with ISO15693

Simple Python implementation for the "IC94-R321 RFID NFC Card Reader Writer For ISO15693 protocol tags" reader with ISO15693 support.
My friends bought this dumb RFID reader from aliexpress](https://ar.aliexpress.com/item/1005002645753203.html?gatewayAdapt=glo2ara), and needed a way to read and write ISO15693 tags. The documentation was a mess and the provided app was mostly in chinese and way too complicated. As they needed to interface with the reader without relying on the app, I decided to reverse engineer it by sniffing the USB traffic and writing a simple Python script to handle the communication.

Huge thanks to [charlysan](https://github.com/charlysan/pyrfidhid/wiki/Reverse-Engineering-A-USB-HID-RFID-Reader-Writer) for his writeup on reverse engineering USB HID devices.

**INTENDED FOR POWER USERS**: This is by no means a complete implementation of the protocol, but it should be enough to get started with basic read/write operations. I built this because I needed it, and will likely never touch it again. Use it as a starting point for your own implementation. Feel free to fork the repo.

The code is based on the USB HID protocol and uses the `pyusb` library for communication.

## Repo Structure

- `find_hid_devices.py`: Lists all connected HID devices and dumps detailed info about the RFID reader
- `main.py`: Main implementation of the RFID reader protocol
- `dumb.txt`: Sniffed packets from the USB traffic. Naming remained oops.

I have provided the official app and documentation in the `docs` folder for reference. I've tried converting the PDF to .md files for LLMs to understand but they couldn't really help AT ALL as there was too much magic happening. For example, first byte sent to the reader is the length of the command, which is not documented anywhere. _Project took me around 20 hours of work time ahhsahashahahahshuhsf._

## Message from the seller

> Dear Mme/ Sir,
> Please find the following Tutorial and the Download link for SDK and demo.
>
> Here is the video demonstration:
> ISO15693
> https://mp.weixin.qq.com/s/lHhwXJUtvwSA0dElfQDtyg

> ISO14443A
> https://mp.weixin.qq.com/s/Y2PuIyQXaPldDtRGBhB8sA

> Download link for SDK and demo:
> https://www.jianguoyun.com/p/DbDGGlQQ8MaABhit7_gFIAA (Password : thinkshine)

## Installation

1. Create and activate a virtual environment:

```bash
uv venv
source .venv/bin/activate  # On Unix/macOS
.venv\Scripts\activate     # On Windows
```

2. Install dependencies:

```bash
uv pip install usb.core
```

## Basic Usage

```python
# Initialize device
dev = init_device()

# Read a tag UID
tag_uid = read_tag_UID(dev)
print(f"Tag UID: {tag_uid}")

# Write data to tag
write_data(dev, tag_uid, "Test message")

# Read data from tag
data = read_data_multiple_blocks(dev, tag_uid)
print(f"Data read: {data}")
```

**More usage examples can be found in the `main.py` file.**

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
Do what you want with it, no credit needed. Just don't blame me if it breaks your reader.
