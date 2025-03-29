#include <Arduino.h>
#include <TFT_eSPI.h>
#include <string>
#include "esp_bt.h"
#include "esp_wifi.h"

TFT_eSPI tft = TFT_eSPI();
const int rowPin = 25;
const int colPins[5] = {26, 27, 32, 33, 5}; // Left, Right, Up, Down
int jammer = 0;
extern int uiState;

void setup() {
  Serial.begin(115200);
  // Disable all process
  esp_bt_controller_deinit();
  esp_bt_controller_disable();
  esp_wifi_stop();
  esp_wifi_deinit();
  disableNRF24();
  
  // Initialize display
  tft.init();
  tft.setRotation(3); // Set rotation to 1 as requested
  
  // Draw the UI
  drawLoading();
  delay(5000);
  
  // Set up keypad pins
  pinMode(rowPin, OUTPUT);
  digitalWrite(rowPin, LOW); // Set row LOW

  for (int i = 0; i < 5; i++) {
    pinMode(colPins[i], INPUT_PULLUP); // Columns as input
  }

  drawInitial();
  drawRandomFace();
  printHeaderMessage();
}

void loop() {
  // Handle user input and UI updates as needed
  checkButtons();
  drawRandomFace();
  printHeaderMessage();

  //ML01 Attacks
  if (uiState == 4 && jammer == 0) drawNRFChannelAnalyzer();
  else if (uiState == 4 && jammer == 1) hopChannelBluetooth();
  else if (uiState == 4 && jammer == 2) hopChannelWifi();
  else if (uiState == 4 && jammer == 3) hopChannelDrone();
  else if (uiState == 4 && jammer == 4) hopChannelAll();


}