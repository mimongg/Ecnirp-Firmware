Ecnirp Firmware
Ecnirp is a modular firmware for ESP32 focused on wireless experimentation, RF signal analysis, and active attacks. It brings together multiple radios (NRF24L01+, CC1101, Wi-Fi, Bluetooth) under one UI-driven system with SD card support — designed for hands-on testing and tool development.


-----------------------------------------------------------------------------------------------------------------------------------------------------------------
✨ Features
NRF24L01+ (Ebyte ML01DP5)

HID desynchronization

Constant carrier jamming

Channel activity analyzer

Autonomous attack engine

CC1101 Sub-GHz Transceiver

Sub-GHz signal work (future modules)

ESP32 Wi-Fi & Bluetooth

Wi-Fi deauth attacks

Bluetooth spoofing & scanning

SD Card File Browser (via TFT UI)

View logs and files directly on display (non-touch)


-----------------------------------------------------------------------------------------------------------------------------------------------------------------
🛠️ Built for Tinkerers & Script Authors
This firmware was made to be hacked on. Whether you're adding new attacks, enhancing RF workflows, or scripting logic, contributions are welcome and appreciated.

If you build on this project or use it in your own tools, a credit to the original author — Prince Rainier Mercado — would be awesome. 🙌


-----------------------------------------------------------------------------------------------------------------------------------------------------------------
Pin Connections

--- TFT Display ---
TFT         | ESP
            |
MISO        | 19
LED         | 5v
SCK         | 18
MOSI        | 23
DC          | 2
RESET       | 4
CS          | 15
GND         | GND
VCC         | 3.3v

--- NRF24 Module ---
NRF24       | ESP
            |
CE          | 16
CSN         | 17
SCK         | 18
MISO        | 19
MOSI        | 23

--- Switch ---
Row Pin = 25
Up = 26
Down = 27
Right = 32
Left = 33
select = 5


-----------------------------------------------------------------------------------------------------------------------------------------------------------------
[NOTE: Replace the default User_Setup.h in you TFT_eSPI library with the modified verion included in the main folder]


-----------------------------------------------------------------------------------------------------------------------------------------------------------------
Project Pictures:
![0c6d4848-dfa2-4c58-96a2-3af7f936a3a7](https://github.com/user-attachments/assets/b4085fda-e23d-4b76-a734-778568584a4d)

![80c9bfeb-7831-46ca-8a3d-187b0ea4a2c6](https://github.com/user-attachments/assets/2cad885f-5dfd-4107-a1ba-b7412b636d9e)

