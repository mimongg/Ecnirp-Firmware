# 🔧 Ecnirp Firmware

**Ecnirp** is a modular, lightweight firmware for the **ESP32**, designed for wireless experimentation, RF signal analysis, and active attacks. It unifies multiple radios—**NRF24L01+**, **CC1101**, **Wi-Fi**, and **Bluetooth**—into a single, UI-driven system with **SD card support**, perfect for hands-on testing and RF tool development.

---

## ✨ Features

### 📡 **NRF24L01+ (Ebyte ML01DP5)**
- HID desynchronization
- Constant carrier jamming
- Channel activity analyzer
- Autonomous attack engine

### 📶 **CC1101 Sub-GHz Transceiver**
- Sub-GHz signal experimentation *(future modules)*

### 🌐 **ESP32 Wi-Fi & Bluetooth**
- Wi-Fi deauthentication attacks
- Bluetooth spoofing & scanning

### 🗂️ **SD Card File Browser (via TFT UI)**
- Browse logs and files directly on the non-touch display

---

## 🛠️ Built for Tinkerers & Script Authors

This firmware is made to be **hacked on**.

Whether you're:
- Adding new attack modules
- Enhancing RF workflows
- Scripting autonomous logic

...your contributions are **welcome and appreciated**.

If you build on this project or integrate it into your own tools, a credit to the original author — **Prince Rainier Mercado** — would be awesome. 🙌

---

## 📌 Pin Connections

### 📺 TFT Display
| **TFT Pin** | **ESP32 Pin** |
|------------|----------------|
| MISO       | 19             |
| LED        | 5V             |
| SCK        | 18             |
| MOSI       | 23             |
| DC         | 2              |
| RESET      | 4              |
| CS         | 15             |
| GND        | GND            |
| VCC        | 3.3V           |

### 📡 NRF24 Module
| **NRF24 Pin** | **ESP32 Pin** |
|---------------|----------------|
| CE            | 16             |
| CSN           | 17             |
| SCK           | 18             |
| MISO          | 19             |
| MOSI          | 23             |

### 🎮 Switch Inputs
- Row Pin = 25  
- Up = 26  
- Down = 27  
- Right = 32  
- Left = 33  
- Select = 5  

---

## ⚠️ Note

> Replace the default `User_Setup.h` file in your **TFT_eSPI** library with the modified version included in this repository’s main folder.

---

## 📸 Project Pictures

![0c6d4848-dfa2-4c58-96a2-3af7f936a3a7](https://github.com/user-attachments/assets/3a61de6e-8edd-4bfe-baf5-634b4e4bb959)


![80c9bfeb-7831-46ca-8a3d-187b0ea4a2c6](https://github.com/user-attachments/assets/e390f3cc-684b-4490-ae91-004ed61a795b)


![cb78ede4-6dba-4abe-b444-61fef1e054c6](https://github.com/user-attachments/assets/f3f23c9c-b627-43d4-aabe-6254d6b19f39)



