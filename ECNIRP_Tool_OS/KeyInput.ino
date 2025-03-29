// Button pins
const char* directions[5] = {"Up", "Down", "Right", "Left", "Select"};

unsigned long lastPressTime = 0;
const int debounceDelay = 200;

int yAxis = 0;
int xAxis = 0;
int y = 109;
// Optional: variable to track current UI state
int uiState = 0;
extern String state;
extern int mode;
extern int faceDrawInterval;


void checkButtons() {
  for (int i = 0; i < 5; i++) {
    if (digitalRead(colPins[i]) == LOW) {
      if (millis() - lastPressTime > debounceDelay) {
        lastPressTime = millis();
        Serial.print("Pressed: ");
        Serial.println(directions[i]);

        // Handle direction
        if (uiState == 0) { // Home Screen
          handleDirectionHome(i);
        }

        else if (uiState == 1) { // Wifi Screen
          handleDirectionWifi(i);
        }

        else if (uiState == 3) { // Bluetooth Screen
          handleDirectionBluetooth(i);
        }

        else if (uiState == 4) { // ML01 Screen
          handleDirectionML01(i);
        }

        else if (uiState == 5){ // CC1101 Screen
          handleDirectionCC1101(i);
        }

      }
    }
  }
}

void handleDirectionML01(int dir) {
  // dir: 0=Up, 1=Down, 2=Right, 3=Left

  switch (dir) {
    case 0: // Up
      if (xAxis == 0 && yAxis > 0) {
        yAxis--;
        y = 109 + (yAxis * 20);

        tft.fillRect(17, y + 20, 141, 20, TFT_BLACK);
        tft.fillRect(17, y, 141, 20, TFT_BLACK);

        tft.drawLine(17, y, 21, y, TFT_WHITE);
        tft.drawLine(17, y + 4, 17, y, TFT_WHITE);
        tft.drawLine(17, y + 14, 17, y + 10, TFT_WHITE);
        tft.drawLine(17, y + 14, 21, y + 14, TFT_WHITE);

        tft.drawLine(153, y, 157, y, TFT_WHITE);
        tft.drawLine(157, y + 4, 157, y, TFT_WHITE);
        tft.drawLine(157, y + 14, 157, y + 10, TFT_WHITE);
        tft.drawLine(153, y + 14, 157, y + 14, TFT_WHITE);

        if (yAxis == 0 && xAxis == 0) {
          tft.drawString("Home", 23, 114);
          tft.drawString("Packet Sniffer", 17, 134);
        }
        if (yAxis == 1 && xAxis == 0) {
          tft.drawString("Packet Sniffer", 23, 134);
          tft.drawString("WiFi Jammer", 17, 154);
        }
        if (yAxis == 2 && xAxis == 0) {
          tft.drawString("WiFi Jammer", 23, 154);
          tft.drawString("Bluetooth Jammer", 17, 174);
        }
      }

      if (xAxis == 1 && yAxis > 0) {
        yAxis--;
        y = 83 + (yAxis * 20);

        tft.fillRect(175, y + 20, 112, 20, TFT_BLACK);
        tft.fillRect(175, y, 112, 20, TFT_BLACK);

        tft.drawLine(175, y, 179, y, TFT_WHITE);
        tft.drawLine(175, y + 4, 175, y, TFT_WHITE);
        tft.drawLine(175, y + 14, 175, y + 10, TFT_WHITE);
        tft.drawLine(175, y + 14, 179, y + 14, TFT_WHITE);

        tft.drawLine(282, y, 286, y, TFT_WHITE);
        tft.drawLine(286, y + 4, 286, y, TFT_WHITE);
        tft.drawLine(286, y + 14, 286, y + 10, TFT_WHITE);
        tft.drawLine(282, y + 14, 286, y + 14, TFT_WHITE);

        // Add text label drawing here if needed
        if (yAxis == 0) {
          tft.drawString("Drone Jammer", 181, 88);
          tft.drawString("Sweep Jammer", 175, 108);
        }
        if (yAxis == 1) {
          tft.drawString("Sweep Jammer", 181, 108);
          tft.drawString("Replay Attack", 175, 128);
        }
        if (yAxis == 2) {
          tft.drawString("Replay Attack", 181, 128);
          tft.drawString("Protocol Fuzzing", 175, 148);
        }
        if (yAxis == 3) {
          tft.drawString("Protocol Fuzzing", 181, 148);
          tft.drawString("Pipe Hijacking", 175, 168);
        }
      }
      break;

    case 1: // Down
      if (xAxis == 0 && yAxis < 3) {
        yAxis++;
        y = 109 + (yAxis * 20);

        tft.fillRect(17, y - 20, 141, 20, TFT_BLACK);
        tft.fillRect(17, y, 141, 20, TFT_BLACK);

        tft.drawLine(17, y, 21, y, TFT_WHITE);
        tft.drawLine(17, y + 4, 17, y, TFT_WHITE);
        tft.drawLine(17, y + 14, 17, y + 10, TFT_WHITE);
        tft.drawLine(17, y + 14, 21, y + 14, TFT_WHITE);

        tft.drawLine(153, y, 157, y, TFT_WHITE);
        tft.drawLine(157, y + 4, 157, y, TFT_WHITE);
        tft.drawLine(157, y + 14, 157, y + 10, TFT_WHITE);
        tft.drawLine(153, y + 14, 157, y + 14, TFT_WHITE);

        if (yAxis == 1 && xAxis == 0) {
          tft.drawString("Home", 17, 114);
          tft.drawString("Packet Sniffer", 23, 134);
        }
        if (yAxis == 2 && xAxis == 0) {
          tft.drawString("Packet Sniffer", 17, 134);
          tft.drawString("WiFi Jammer", 23, 154);
        }
        if (yAxis == 3 && xAxis == 0) {
          tft.drawString("WiFi Jammer", 17, 154);
          tft.drawString("Bluetooth Jammer", 23, 174);
        }
      }

      if (xAxis == 1 && yAxis < 4) {
        yAxis++;
        y = 83 + (yAxis * 20);

        tft.fillRect(175, y - 20, 112, 20, TFT_BLACK);
        tft.fillRect(175, y, 112, 20, TFT_BLACK);

        tft.drawLine(175, y, 179, y, TFT_WHITE);
        tft.drawLine(175, y + 4, 175, y, TFT_WHITE);
        tft.drawLine(175, y + 14, 175, y + 10, TFT_WHITE);
        tft.drawLine(175, y + 14, 179, y + 14, TFT_WHITE);

        tft.drawLine(282, y, 286, y, TFT_WHITE);
        tft.drawLine(286, y + 4, 286, y, TFT_WHITE);
        tft.drawLine(286, y + 14, 286, y + 10, TFT_WHITE);
        tft.drawLine(282, y + 14, 286, y + 14, TFT_WHITE);

        if (yAxis == 1) {
          tft.drawString("Drone Jammer", 175, 88);
          tft.drawString("Sweep Jammer", 181, 108);
        }
        if (yAxis == 2) {
          tft.drawString("Sweep Jammer", 175, 108);
          tft.drawString("Replay Attack", 181, 128);
        }
        if (yAxis == 3) {
          tft.drawString("Replay Attack", 175, 128);
          tft.drawString("Protocol Fuzzing", 181, 148);
        }
        if (yAxis == 4) {
          tft.drawString("Protocol Fuzzing", 175, 148);
          tft.drawString("Pipe Hijacking", 181, 168);
        }
      }
      break;

    case 2: // Right
      if (xAxis == 0) {
        int y = 109 + (yAxis * 20);
        tft.fillRect(17, y, 141, 20, TFT_BLACK);  // Clear left box

        xAxis = 1;

        y = 83;  // Right always starts at y=83
        tft.fillRect(175, y, 112, 20, TFT_BLACK); // Clear right box
        tft.drawString("Drone Jammer", 181, 88);

        // Draw selection box on right
        tft.drawLine(175, y, 179, y, 0xFFFF);
        tft.drawLine(175, y + 4, 175, y, 0xFFFF);
        tft.drawLine(175, y + 14, 175, y + 10, 0xFFFF);
        tft.drawLine(175, y + 14, 179, y + 14, 0xFFFF);

        tft.drawLine(282, y, 286, y, 0xFFFF);
        tft.drawLine(286, y + 4, 286, y, 0xFFFF);
        tft.drawLine(286, y + 14, 286, y + 10, 0xFFFF);
        tft.drawLine(282, y + 14, 286, y + 14, 0xFFFF);

        // Restore label on left
        if (yAxis == 0) tft.drawString("Home", 17, 114);
        if (yAxis == 1) tft.drawString("Packet Sniffer", 17, 134);
        if (yAxis == 2) tft.drawString("WiFi Jammer", 17, 154);
        if (yAxis == 3) tft.drawString("Bluetooth Jammer", 17, 174);

        yAxis = 0;  // Now reset for right-side navigation
      }
      break;

    case 3: // Left
      if (xAxis == 1) {
        int y = 83 + (yAxis * 20);
        tft.fillRect(175, y, 112, 20, TFT_BLACK); // Clear right box

        xAxis = 0;

        y = 109;  // Left always starts at y=109
        tft.fillRect(17, y, 141, 20, TFT_BLACK);  // Clear left box
        tft.drawString("Home", 23, 114);

        // Draw selection box on left
        tft.drawLine(17, y, 21, y, 0xFFFF);
        tft.drawLine(17, y + 4, 17, y, 0xFFFF);
        tft.drawLine(17, y + 14, 17, y + 10, 0xFFFF);
        tft.drawLine(17, y + 14, 21, y + 14, 0xFFFF);

        tft.drawLine(153, y, 157, y, 0xFFFF);
        tft.drawLine(157, y + 4, 157, y, 0xFFFF);
        tft.drawLine(157, y + 14, 157, y + 10, 0xFFFF);
        tft.drawLine(153, y + 14, 157, y + 14, 0xFFFF);

        // Restore label on right
        if (yAxis == 0) tft.drawString("Drone Jammer", 175, 88);
        if (yAxis == 1) tft.drawString("Sweep Jammer", 175, 108);
        if (yAxis == 2) tft.drawString("Replay Attack", 175, 128);
        if (yAxis == 3) tft.drawString("Protocol Fuzzing", 175, 148);
        if (yAxis == 4) tft.drawString("Pipe Hijacking", 175, 168);

        yAxis = 0;  // Reset after drawing
      }
      break;

    case 4: // Select
      if (yAxis == 0 && xAxis == 0) { // Go Back Home
        uiState = 0;
        yAxis = 0;
        xAxis = 0;
        deinitML01();
        jammer = 0;
        mode = (esp_random() % 2) ? 2 : 0;
        clearEarsArea();
        clearMainArea();
        drawHomeScreen();
      }

      else if (yAxis == 3 && xAxis == 0) { // Activate Bluetooth Jammer
        if (jammer == 0) {
          jammer = 1;
          drawEars();
          mode = 1;
          startBroadcastingML01();
        }

        else if (jammer == 1) {
          jammer = 0;
          mode = (esp_random() % 2) ? 2 : 0;
          clearEarsArea();
          stopBroadcastingML01();
        }
      }

      else if (yAxis == 2 && xAxis == 0) { // Activate Wifi Jammer
        if (jammer == 0) {
          jammer = 2;
          drawEars();
          mode = 1;
          startBroadcastingML01();
        }

        else if (jammer == 2) {
          jammer = 0;
          mode = (esp_random() % 2) ? 2 : 0;
          clearEarsArea();
          stopBroadcastingML01();
        }
      }

      else if (yAxis == 0 && xAxis == 1) { // Activate Drone Jammer
        if (jammer == 0) {
          jammer = 3;
          drawEars();
          mode = 1;
          startBroadcastingML01();
        }

        else if (jammer == 3) {
          jammer = 0;
          mode = (esp_random() % 2) ? 2 : 0;
          clearEarsArea();
          stopBroadcastingML01();
        }
      }

      else if (yAxis == 1 && xAxis == 1) { // Activate Sweep Jammer
        if (jammer == 0) {
          jammer = 4;
          drawEars();
          mode = 1;
          startBroadcastingML01();
        }

        else if (jammer == 4) {
          jammer = 0;
          mode = (esp_random() % 2) ? 2 : 0;
          clearEarsArea();
          stopBroadcastingML01();
        }
      }
      break;

  }
}


/*  

CC1101 SCREEN FUNCTIONS

*/

void handleDirectionCC1101(int dir) {
  // dir: 0=Up, 1=Down, 2=Right, 3=Left

  switch (dir) {
    case 0: // Up
      if (xAxis == 0 && yAxis > 0) {
        yAxis--;
        y = 109 + (yAxis * 20);

        tft.fillRect(17, y + 20, 141, 20, TFT_BLACK);
        tft.fillRect(17, y, 141, 20, TFT_BLACK);

        tft.drawLine(17, y, 21, y, TFT_WHITE);
        tft.drawLine(17, y + 4, 17, y, TFT_WHITE);
        tft.drawLine(17, y + 14, 17, y + 10, TFT_WHITE);
        tft.drawLine(17, y + 14, 21, y + 14, TFT_WHITE);

        tft.drawLine(153, y, 157, y, TFT_WHITE);
        tft.drawLine(157, y + 4, 157, y, TFT_WHITE);
        tft.drawLine(157, y + 14, 157, y + 10, TFT_WHITE);
        tft.drawLine(153, y + 14, 157, y + 14, TFT_WHITE);

        if (yAxis == 0 && xAxis == 0) {
          tft.drawString("Home", 23, 114);
          tft.drawString("Packet Sniffer", 17, 134);
        }
        if (yAxis == 1 && xAxis == 0) {
          tft.drawString("Packet Sniffer", 23, 134);
          tft.drawString("Channel Jammer", 17, 154);
        }
        if (yAxis == 2 && xAxis == 0) {
          tft.drawString("Channel Jammer", 23, 154);
          tft.drawString("State Desync", 17, 174);
        }
      }

      if (xAxis == 1 && yAxis > 0) {
        yAxis--;
        y = 83 + (yAxis * 20);

        tft.fillRect(175, y + 20, 112, 20, TFT_BLACK);
        tft.fillRect(175, y, 112, 20, TFT_BLACK);

        tft.drawLine(175, y, 179, y, TFT_WHITE);
        tft.drawLine(175, y + 4, 175, y, TFT_WHITE);
        tft.drawLine(175, y + 14, 175, y + 10, TFT_WHITE);
        tft.drawLine(175, y + 14, 179, y + 14, TFT_WHITE);

        tft.drawLine(282, y, 286, y, TFT_WHITE);
        tft.drawLine(286, y + 4, 286, y, TFT_WHITE);
        tft.drawLine(286, y + 14, 286, y + 10, TFT_WHITE);
        tft.drawLine(282, y + 14, 286, y + 14, TFT_WHITE);

        // Add text label drawing here if needed
        if (yAxis == 0) {
          tft.drawString("Rolling Jammer", 181, 88);
          tft.drawString("Sweep Jammer", 175, 108);
        }
        if (yAxis == 1) {
          tft.drawString("Sweep Jammer", 181, 108);
          tft.drawString("Replay Attack", 175, 128);
        }
        if (yAxis == 2) {
          tft.drawString("Replay Attack", 181, 128);
          tft.drawString("Protocol Fuzzing", 175, 148);
        }
        if (yAxis == 3) {
          tft.drawString("Protocol Fuzzing", 181, 148);
          tft.drawString("Payload Injection", 175, 168);
        }
      }
      break;

    case 1: // Down
      if (xAxis == 0 && yAxis < 3) {
        yAxis++;
        y = 109 + (yAxis * 20);

        tft.fillRect(17, y - 20, 141, 20, TFT_BLACK);
        tft.fillRect(17, y, 141, 20, TFT_BLACK);

        tft.drawLine(17, y, 21, y, TFT_WHITE);
        tft.drawLine(17, y + 4, 17, y, TFT_WHITE);
        tft.drawLine(17, y + 14, 17, y + 10, TFT_WHITE);
        tft.drawLine(17, y + 14, 21, y + 14, TFT_WHITE);

        tft.drawLine(153, y, 157, y, TFT_WHITE);
        tft.drawLine(157, y + 4, 157, y, TFT_WHITE);
        tft.drawLine(157, y + 14, 157, y + 10, TFT_WHITE);
        tft.drawLine(153, y + 14, 157, y + 14, TFT_WHITE);

        if (yAxis == 1 && xAxis == 0) {
          tft.drawString("Home", 17, 114);
          tft.drawString("Packet Sniffer", 23, 134);
        }
        if (yAxis == 2 && xAxis == 0) {
          tft.drawString("Packet Sniffer", 17, 134);
          tft.drawString("Channel Jammer", 23, 154);
        }
        if (yAxis == 3 && xAxis == 0) {
          tft.drawString("Channel Jammer", 17, 154);
          tft.drawString("State Desync", 23, 174);
        }
      }

      if (xAxis == 1 && yAxis < 4) {
        yAxis++;
        y = 83 + (yAxis * 20);

        tft.fillRect(175, y - 20, 112, 20, TFT_BLACK);
        tft.fillRect(175, y, 112, 20, TFT_BLACK);

        tft.drawLine(175, y, 179, y, TFT_WHITE);
        tft.drawLine(175, y + 4, 175, y, TFT_WHITE);
        tft.drawLine(175, y + 14, 175, y + 10, TFT_WHITE);
        tft.drawLine(175, y + 14, 179, y + 14, TFT_WHITE);

        tft.drawLine(282, y, 286, y, TFT_WHITE);
        tft.drawLine(286, y + 4, 286, y, TFT_WHITE);
        tft.drawLine(286, y + 14, 286, y + 10, TFT_WHITE);
        tft.drawLine(282, y + 14, 286, y + 14, TFT_WHITE);

        if (yAxis == 1) {
          tft.drawString("Rolling Jammer", 175, 88);
          tft.drawString("Sweep Jammer", 181, 108);
        }
        if (yAxis == 2) {
          tft.drawString("Sweep Jammer", 175, 108);
          tft.drawString("Replay Attack", 181, 128);
        }
        if (yAxis == 3) {
          tft.drawString("Replay Attack", 175, 128);
          tft.drawString("Protocol Fuzzing", 181, 148);
        }
        if (yAxis == 4) {
          tft.drawString("Protocol Fuzzing", 175, 148);
          tft.drawString("Payload Injection", 181, 168);
        }
      }
      break;

    case 2: // Right
      if (xAxis == 0) {
        int y = 109 + (yAxis * 20);
        tft.fillRect(17, y, 141, 20, TFT_BLACK);  // Clear left box

        xAxis = 1;

        y = 83;  // Right always starts at y=83
        tft.fillRect(175, y, 112, 20, TFT_BLACK); // Clear right box
        tft.drawString("Rolling Jammer", 181, 88);

        // Draw selection box on right
        tft.drawLine(175, y, 179, y, 0xFFFF);
        tft.drawLine(175, y + 4, 175, y, 0xFFFF);
        tft.drawLine(175, y + 14, 175, y + 10, 0xFFFF);
        tft.drawLine(175, y + 14, 179, y + 14, 0xFFFF);

        tft.drawLine(282, y, 286, y, 0xFFFF);
        tft.drawLine(286, y + 4, 286, y, 0xFFFF);
        tft.drawLine(286, y + 14, 286, y + 10, 0xFFFF);
        tft.drawLine(282, y + 14, 286, y + 14, 0xFFFF);

        // Restore label on left
        if (yAxis == 0) tft.drawString("Home", 17, 114);
        if (yAxis == 1) tft.drawString("Packet Sniffer", 17, 134);
        if (yAxis == 2) tft.drawString("Channel Jammer", 17, 154);
        if (yAxis == 3) tft.drawString("State Desync", 17, 174);

        yAxis = 0;  // Now reset for right-side navigation
      }
      break;

    case 3: // Left
      if (xAxis == 1) {
        int y = 83 + (yAxis * 20);
        tft.fillRect(175, y, 112, 20, TFT_BLACK); // Clear right box

        xAxis = 0;

        y = 109;  // Left always starts at y=109
        tft.fillRect(17, y, 141, 20, TFT_BLACK);  // Clear left box
        tft.drawString("Home", 23, 114);

        // Draw selection box on left
        tft.drawLine(17, y, 21, y, 0xFFFF);
        tft.drawLine(17, y + 4, 17, y, 0xFFFF);
        tft.drawLine(17, y + 14, 17, y + 10, 0xFFFF);
        tft.drawLine(17, y + 14, 21, y + 14, 0xFFFF);

        tft.drawLine(153, y, 157, y, 0xFFFF);
        tft.drawLine(157, y + 4, 157, y, 0xFFFF);
        tft.drawLine(157, y + 14, 157, y + 10, 0xFFFF);
        tft.drawLine(153, y + 14, 157, y + 14, 0xFFFF);

        // Restore label on right
        if (yAxis == 0) tft.drawString("Rolling Jammer", 175, 88);
        if (yAxis == 1) tft.drawString("Sweep Jammer", 175, 108);
        if (yAxis == 2) tft.drawString("Replay Attack", 175, 128);
        if (yAxis == 3) tft.drawString("Protocol Fuzzing", 175, 148);
        if (yAxis == 4) tft.drawString("Payload Injection", 175, 168);

        yAxis = 0;  // Reset after drawing
      }
      break;

    case 4: // Select
      if (yAxis == 0 && xAxis == 0) {
        uiState = 0;
        yAxis = 0;
        xAxis = 0;
        clearMainArea();
        drawHomeScreen();
      }
      break;

  }
}



/* 

HOME SCREEN FUNCTIONS

*/

void highlightWifi() {
  tft.setTextSize(2);
  tft.setTextColor(0x7DF);
  tft.drawString("WiFi", 12, 134);
  tft.drawString("Attacks", 12, 147);
  tft.drawBitmap(11, 115, image_wifi_75_bits, 19, 16, 0x7DF);
  tft.fillEllipse(122, 154, 2, 2, 0x7DF);
  tft.drawLine(8, 75, 8, 159, 0x7DF);
  tft.drawLine(8, 160, 128, 160, 0x7DF);
  tft.drawLine(8, 74, 165, 74, 0x7DF);
  tft.drawLine(166, 74, 166, 121, 0x7DF);
  tft.drawLine(166, 122, 128, 160, 0x7DF);
  tft.drawLine(166, 121, 128, 159, 0x7DF);
  tft.setTextSize(1);
  tft.drawString("ESP32-WROOM", 99, 78);
}

void normalWifi() {
  tft.setTextSize(2);
  tft.setTextColor(0xFFFF);
  tft.drawString("WiFi", 15, 131);
  tft.drawString("Attacks", 15, 144);
  tft.fillEllipse(123, 151, 2, 2, 0xFFFF);
  tft.drawBitmap(14, 112, image_wifi_75_bits, 19, 16, 0xFFFF);
  tft.drawLine(11, 77, 11, 157, 0xFFFF);
  tft.drawLine(12, 157, 128, 157, 0xFFFF);
  tft.drawLine(12, 77, 163, 77, 0xFFFF);
  tft.drawLine(163, 77, 163, 121, 0xFFFF);
  tft.drawLine(163, 122, 128, 157, 0xFFFF);
  tft.drawLine(163, 123, 129, 157, 0xFFFF);
  tft.setTextSize(1);
  tft.drawString("ESP32-WROOM", 96, 81);
}

void clearWifiArea() {
  // Highlight Clear
  tft.fillRect(12, 130, 76, 27, TFT_BLACK);
  tft.fillRect(96, 78, 68, 5, TFT_BLACK);
  tft.drawBitmap(11, 115, image_wifi_75_bits, 19, 16, 0x0);
  tft.fillEllipse(122, 154, 2, 2, 0x0);
  tft.drawLine(8, 75, 8, 159, 0x0);
  tft.drawLine(8, 160, 128, 160, 0x0);
  tft.drawLine(8, 74, 165, 74, 0x0);
  tft.drawLine(166, 74, 166, 121, 0x0);
  tft.drawLine(166, 122, 128, 160, 0x0);
  tft.drawLine(166, 121, 128, 159, 0x0);

  // Normal Clear
  tft.fillRect(15, 130, 76, 24, TFT_BLACK);
  tft.fillRect(96, 81, 65, 5, TFT_BLACK);
  tft.fillEllipse(123, 151, 2, 2, 0x0);
  tft.drawBitmap(14, 112, image_wifi_75_bits, 19, 16, 0x0);
  tft.drawLine(11, 77, 11, 157, 0x0);
  tft.drawLine(12, 157, 128, 157, 0x0);
  tft.drawLine(12, 77, 163, 77, 0x0);
  tft.drawLine(163, 77, 163, 121, 0x0);
  tft.drawLine(163, 122, 128, 157, 0x0);
  tft.drawLine(163, 123, 129, 157, 0x0);
}

void highlightBluetooth() {
  tft.setTextSize(2);
  tft.setTextColor(0x7DF);
  tft.drawString("Bluetooth", 12, 207);
  tft.drawString("Open", 12, 192);
  tft.drawBitmap(10, 173, image_download_bits, 14, 16, 0x7DF);
  tft.drawBitmap(11, 173, image_download_bits, 14, 16, 0x7DF);
  tft.fillEllipse(121, 214, 2, 2, 0x7DF);
  tft.drawLine(8, 160, 127, 160, 0x7DF);
  tft.drawLine(127, 220, 127, 161, 0x7DF);
  tft.drawLine(8, 220, 126, 220, 0x7DF);
  tft.drawLine(8, 219, 8, 161, 0x7DF);
  tft.setTextSize(1);
  tft.drawString("ESP32-WROOM", 60, 164);
}

void normalBluetooth() {
  tft.setTextSize(2);
  tft.setTextColor(0xFFFF);
  tft.drawLine(12, 163, 124, 163, 0xFFFF);
  tft.drawLine(11, 217, 11, 163, 0xFFFF);
  tft.drawLine(124, 217, 124, 163, 0xFFFF);
  tft.drawLine(12, 217, 124, 217, 0xFFFF);
  tft.drawString("Open", 15, 189);
  tft.drawString("Bluetooth", 15, 204);
  tft.fillEllipse(118, 211, 2, 2, 0xFFFF);
  tft.drawBitmap(13, 170, image_download_bits, 14, 16, 0xFFFF);
  tft.drawBitmap(14, 170, image_download_bits, 14, 16, 0xFFFF);
  tft.setTextSize(1);
  tft.drawString("ESP32-WROOM", 57, 167);
}

void clearBluetoothArea() {
  // Highlight Clear
  tft.fillRect(12, 189, 90, 28, TFT_BLACK);
  tft.fillRect(57, 164, 68, 5, TFT_BLACK);
  tft.drawBitmap(10, 173, image_download_bits, 14, 16, 0x0);
  tft.drawBitmap(11, 173, image_download_bits, 14, 16, 0x0);
  tft.fillEllipse(121, 214, 2, 2, 0x0);
  tft.drawLine(8, 160, 127, 160, 0x0);
  tft.drawLine(127, 220, 127, 161, 0x0);
  tft.drawLine(8, 220, 126, 220, 0x0);
  tft.drawLine(8, 219, 8, 161, 0x0);
  
  // Normal Clear
  tft.fillRect(15, 189, 90, 25, TFT_BLACK);
  tft.fillRect(57, 167, 65, 5, TFT_BLACK);
  tft.drawLine(12, 163, 124, 163, 0x0);
  tft.drawLine(11, 217, 11, 163, 0x0);
  tft.drawLine(124, 217, 124, 163, 0x0);
  tft.drawLine(12, 217, 124, 217, 0x0);
  tft.fillEllipse(118, 211, 2, 2, 0x0);
  tft.drawBitmap(13, 170, image_download_bits, 14, 16, 0x0);
  tft.drawBitmap(14, 170, image_download_bits, 14, 16, 0x0);
}

void highlightArchives() {
  tft.setTextSize(2);
  tft.setTextColor(0x7DF);
  tft.drawBitmap(170, 92, image_download_1_bits, 16, 16, 0x7DF);
  tft.drawString("Archives", 170, 111);
  tft.fillEllipse(305, 118, 2, 2, 0x7DF);
  tft.drawLine(166, 124, 166, 74, 0x7DF);
  tft.drawLine(167, 124, 311, 124, 0x7DF);
  tft.drawLine(166, 74, 311, 74, 0x7DF);
  tft.drawLine(311, 123, 311, 75, 0x7DF);
  tft.setTextSize(1);
  tft.drawString("File Browser", 251, 78);
}

void normalArchives() {
  tft.setTextSize(2);
  tft.setTextColor(0xFFFF);
  tft.drawBitmap(173, 89, image_download_1_bits, 16, 16, 0xFFFF);
  tft.drawString("Archives", 173, 108);
  tft.fillEllipse(302, 115, 2, 2, 0xFFFF);
  tft.drawLine(169, 121, 169, 77, 0xFFFF);
  tft.drawLine(169, 121, 307, 121, 0xFFFF);
  tft.drawLine(169, 77, 307, 77, 0xFFFF);
  tft.drawLine(308, 121, 308, 77, 0xFFFF);
  tft.setTextSize(1);
  tft.drawString("File Browser", 248, 81);
}

void clearArchivesArea() {
  // Highlight Clear
  tft.fillRect(167, 111, 76, 13, TFT_BLACK);
  tft.fillRect(251, 75, 61, 5, TFT_BLACK);
  tft.drawBitmap(170, 92, image_download_1_bits, 16, 16, 0x0);
  tft.fillEllipse(305, 118, 2, 2, 0x0);
  tft.drawLine(166, 124, 166, 74, 0x0);
  tft.drawLine(167, 124, 311, 124, 0x0);
  tft.drawLine(166, 74, 311, 74, 0x0);
  tft.drawLine(311, 123, 311, 75, 0x0);

  // Normal Clear
  tft.fillRect(172, 106, 78, 15, TFT_BLACK);
  tft.fillRect(248, 80, 60, 7, TFT_BLACK);
  tft.drawBitmap(173, 89, image_download_1_bits, 16, 16, 0x0);
  tft.fillEllipse(302, 115, 2, 2, 0x0);
  tft.drawLine(169, 121, 169, 77, 0x0);
  tft.drawLine(169, 121, 307, 121, 0x0);
  tft.drawLine(169, 77, 307, 77, 0x0);
  tft.drawLine(308, 121, 308, 77, 0x0);
}

void highlightML01() {
  tft.setTextSize(2);
  tft.setTextColor(0x7DF);
  tft.drawString("2.4GHz", 131, 207);
  tft.drawString("All", 131, 194);
  tft.drawBitmap(131, 175, image_network_3_bars_bits, 15, 16, 0x7DF);
  tft.fillEllipse(217, 214, 2, 2, 0x7DF);
  tft.drawLine(128, 220, 222, 220, 0x7DF);
  tft.drawLine(127, 220, 127, 163, 0x7DF);
  tft.drawLine(223, 220, 223, 124, 0x7DF);
  tft.drawLine(166, 124, 222, 124, 0x7DF);
  tft.drawLine(166, 125, 128, 163, 0x7DF);
  tft.drawLine(165, 125, 128, 162, 0x7DF);
  tft.setTextSize(1);
  tft.drawString("ML01DP5", 183, 128);
}

void normalML01() {
  tft.setTextSize(2);
  tft.setTextColor(0xFFFF);
  tft.drawString("All", 134, 191);
  tft.drawString("2.4GHz", 134, 204);
  tft.drawBitmap(134, 172, image_network_3_bars_bits, 15, 16, 0xFFFF);
  tft.fillEllipse(214, 211, 2, 2, 0xFFFF);
  tft.drawLine(130, 217, 220, 217, 0xFFFF);
  tft.drawLine(130, 217, 130, 162, 0xFFFF);
  tft.drawLine(220, 217, 220, 127, 0xFFFF);
  tft.drawLine(164, 127, 219, 127, 0xFFFF);
  tft.drawLine(164, 128, 130, 162, 0xFFFF);
  tft.drawLine(164, 127, 130, 161, 0xFFFF);
  tft.setTextSize(1);
  tft.drawString("ML01DP5", 180, 131);
}

void clearML01Area() {
  // Higlight Clear
  tft.fillRect(131, 191, 62, 26, TFT_BLACK);
  tft.fillRect(180, 128, 41, 5, TFT_BLACK);
  tft.drawBitmap(131, 175, image_network_3_bars_bits, 15, 16, 0x0);
  tft.fillEllipse(217, 214, 2, 2, 0x0);
  tft.drawLine(128, 220, 222, 220, 0x0);
  tft.drawLine(127, 220, 127, 163, 0x0);
  tft.drawLine(223, 220, 223, 124, 0x0);
  tft.drawLine(166, 124, 222, 124, 0x0);
  tft.drawLine(166, 125, 128, 163, 0x0);
  tft.drawLine(165, 125, 128, 162, 0x0);

  // Normal Clear
  tft.fillRect(134, 191, 62, 23, TFT_BLACK);
  tft.fillRect(180, 131, 38, 5, TFT_BLACK);
  tft.drawBitmap(134, 172, image_network_3_bars_bits, 15, 16, 0x0);
  tft.fillEllipse(214, 211, 2, 2, 0x0);
  tft.drawLine(130, 217, 220, 217, 0x0);
  tft.drawLine(130, 217, 130, 162, 0x0);
  tft.drawLine(220, 217, 220, 127, 0x0);
  tft.drawLine(164, 127, 219, 127, 0x0);
  tft.drawLine(164, 128, 130, 162, 0x0);
  tft.drawLine(164, 127, 130, 161, 0x0);
}

void highlightCC11() {
  tft.setTextSize(2);
  tft.setTextColor(0x7DF);
  tft.drawString("1.0GHz", 227, 207);
  tft.drawString("Sub", 227, 194);
  tft.drawBitmap(227, 175, image_download_3_bits, 15, 16, 0x7DF);
  tft.fillEllipse(305, 214, 2, 2, 0x7DF);
  tft.drawLine(223, 220, 310, 220, 0x7DF);
  tft.drawLine(223, 220, 223, 124, 0x7DF);
  tft.drawLine(311, 220, 311, 124, 0x7DF);
  tft.drawLine(224, 124, 311, 124, 0x7DF);
  tft.setTextSize(1);
  tft.drawString("CC1101", 285, 128);
}

void normalCC11() {
  tft.setTextSize(2);
  tft.setTextColor(0xFFFF);
  tft.drawString("1.0GHz", 230, 204);
  tft.drawString("Sub", 230, 191);
  tft.drawBitmap(230, 172, image_download_3_bits, 15, 16, 0xFFFF);
  tft.fillEllipse(302, 211, 2, 2, 0xFFFF);
  tft.drawLine(226, 217, 307, 217, 0xFFFF);
  tft.drawLine(226, 217, 226, 128, 0xFFFF);
  tft.drawLine(308, 217, 308, 128, 0xFFFF);
  tft.drawLine(226, 127, 308, 127, 0xFFFF);
  tft.setTextSize(1);
  tft.drawString("CC1101", 282, 131);
}

void clearCC11Area() {
  // Highlight Clear
  tft.fillRect(227, 191, 54, 26, TFT_BLACK);
  tft.fillRect(282, 128, 27, 5, TFT_BLACK);
  tft.drawBitmap(227, 175, image_download_3_bits, 15, 16, 0x0);
  tft.fillEllipse(305, 214, 2, 2, 0x0);
  tft.drawLine(223, 220, 310, 220, 0x0);
  tft.drawLine(223, 220, 223, 124, 0x0);
  tft.drawLine(311, 220, 311, 124, 0x0);
  tft.drawLine(224, 124, 311, 124, 0x0);

  // Normal Clear
  tft.fillRect(230, 191, 54, 23, TFT_BLACK);
  tft.fillRect(282, 131, 24, 5, TFT_BLACK);
  tft.drawBitmap(230, 172, image_download_3_bits, 15, 16, 0x0);
  tft.fillEllipse(302, 211, 2, 2, 0x0);
  tft.drawLine(226, 217, 307, 217, 0x0);
  tft.drawLine(226, 217, 226, 128, 0x0);
  tft.drawLine(308, 217, 308, 128, 0x0);
  tft.drawLine(226, 127, 308, 127, 0x0);
}

void handleDirectionHome(int dir) {

  switch (dir) {
    case 0: // Up
      if (yAxis == 1 && xAxis == 0) {
          clearBluetoothArea();
          clearWifiArea();
          highlightWifi();
          normalBluetooth();
          yAxis--;
      }

      else if (yAxis == 1 && xAxis == 1) {
        clearML01Area();
        clearWifiArea();
        normalML01();
        highlightWifi();
        xAxis--;
        yAxis--;
      }

      else if (yAxis == 1 && xAxis == 2) {
        clearCC11Area();
        clearArchivesArea();
        normalCC11();
        highlightArchives();
        yAxis--;
        xAxis--;
      }
      break;
    
    case 1: // Down
      if (yAxis == 0 && xAxis == 0) {
        clearBluetoothArea();
        clearWifiArea();
        normalWifi();
        highlightBluetooth();
        yAxis++;
      }

      else if (yAxis == 0 && xAxis == 1) {
        clearArchivesArea();
        clearCC11Area();
        normalArchives();
        highlightCC11();
        yAxis++;
        xAxis++;
      }
      break;
    
    case 2: // Right
      if (yAxis == 0 && xAxis == 0) {
        clearWifiArea();
        clearArchivesArea();
        normalWifi();
        highlightArchives();
        xAxis++;
      }

      else if (yAxis == 1 and xAxis == 0) {
        clearBluetoothArea();
        clearML01Area();
        normalBluetooth();
        highlightML01();
        xAxis++;
      }

      else if (yAxis == 1 && xAxis == 1) {
        clearML01Area();
        clearCC11Area();
        normalML01();
        highlightCC11();
        xAxis++;
      }
      break;

    case 3: // Left
      if (yAxis == 0 && xAxis == 1) {
        clearArchivesArea();
        clearWifiArea();
        highlightWifi();
        normalArchives();
        xAxis--;
      }

      else if (yAxis == 1 && xAxis == 1) {
        clearML01Area();
        clearBluetoothArea();
        normalML01();
        highlightBluetooth();
        xAxis--;
      }

      else if (yAxis == 1 && xAxis == 2) {
        clearCC11Area();
        clearML01Area();
        normalCC11();
        highlightML01();
        xAxis--;
      }
      break;

    case 4: // Select
      if (yAxis == 0 && xAxis == 0) { // Wifi Screen
        uiState = 1;
        yAxis = 0;
        xAxis = 0;
        clearWifiArea();
        clearMainArea();
        drawWifiSubModule();
      }

      else if (yAxis == 1 && xAxis == 0) { // Bluetooth Screen
        uiState = 3;
        yAxis = 0;
        xAxis = 0;
        clearBluetoothArea();
        clearMainArea();
        drawBluetoothSubModule();
      }

      else if (yAxis == 1 && xAxis == 1) { // NRF Screen
        uiState = 4;
        yAxis = 0;
        xAxis = 0;
        if (state == "Inactive") {
            initML01();
        }
        clearML01Area();
        clearMainArea();
        drawNRFSubModule();
      }

      else if (yAxis == 1 && xAxis == 2) { // CC11 Screen
        uiState = 5;
        yAxis = 0;
        xAxis = 0;
        clearMainArea();
        clearCC11Area();
        drawCC1101SubModule();
      }
      break;
  }
}


/*  

WIFI SCREEN FUNCTIONS

*/

void handleDirectionWifi(int dir) {
  // dir: 0=Up, 1=Down, 2=Right, 3=Left

  switch (dir) {
    case 0: // Up
      if (xAxis == 0 && yAxis > 0) {
        yAxis--;
        y = 109 + (yAxis * 20);

        tft.fillRect(17, y + 20, 141, 20, TFT_BLACK);
        tft.fillRect(17, y, 141, 20, TFT_BLACK);

        tft.drawLine(17, y, 21, y, TFT_WHITE);
        tft.drawLine(17, y + 4, 17, y, TFT_WHITE);
        tft.drawLine(17, y + 14, 17, y + 10, TFT_WHITE);
        tft.drawLine(17, y + 14, 21, y + 14, TFT_WHITE);

        tft.drawLine(153, y, 157, y, TFT_WHITE);
        tft.drawLine(157, y + 4, 157, y, TFT_WHITE);
        tft.drawLine(157, y + 14, 157, y + 10, TFT_WHITE);
        tft.drawLine(153, y + 14, 157, y + 14, TFT_WHITE);

        if (yAxis == 0 && xAxis == 0) {
          tft.drawString("Home", 23, 114);
          tft.drawString("WiFi Scanner", 17, 134);
        }
        if (yAxis == 1 && xAxis == 0) {
          tft.drawString("WiFi Scanner", 23, 134);
          tft.drawString("Deauth Selected", 17, 154);
        }
        if (yAxis == 2 && xAxis == 0) {
          tft.drawString("Deauth Selected", 23, 154);
          tft.drawString("Deauth Flood", 17, 174);
        }
      }

      if (xAxis == 1 && yAxis > 0) {
        yAxis--;
        y = 83 + (yAxis * 20);

        tft.fillRect(175, y + 20, 112, 20, TFT_BLACK);
        tft.fillRect(175, y, 112, 20, TFT_BLACK);

        tft.drawLine(175, y, 179, y, TFT_WHITE);
        tft.drawLine(175, y + 4, 175, y, TFT_WHITE);
        tft.drawLine(175, y + 14, 175, y + 10, TFT_WHITE);
        tft.drawLine(175, y + 14, 179, y + 14, TFT_WHITE);

        tft.drawLine(282, y, 286, y, TFT_WHITE);
        tft.drawLine(286, y + 4, 286, y, TFT_WHITE);
        tft.drawLine(286, y + 14, 286, y + 10, TFT_WHITE);
        tft.drawLine(282, y + 14, 286, y + 14, TFT_WHITE);

        // Add text label drawing here if needed
        if (yAxis == 0) {
          tft.drawString("PMKID Attack", 181, 88);
          tft.drawString("Handshake Sniffing", 175, 108);
        }
        if (yAxis == 1) {
          tft.drawString("Handshake Sniffing", 181, 108);
          tft.drawString("Rogue Portal", 175, 128);
        }
        if (yAxis == 2) {
          tft.drawString("Rogue Portal", 181, 128);
          tft.drawString("BSSID Flood", 175, 148);
        }
        if (yAxis == 3) {
          tft.drawString("BSSID Flood", 181, 148);
          tft.drawString("BSSID Clone", 175, 168);
        }
      }
      break;

    case 1: // Down
      if (xAxis == 0 && yAxis < 3) {
        yAxis++;
        y = 109 + (yAxis * 20);

        tft.fillRect(17, y - 20, 141, 20, TFT_BLACK);
        tft.fillRect(17, y, 141, 20, TFT_BLACK);

        tft.drawLine(17, y, 21, y, TFT_WHITE);
        tft.drawLine(17, y + 4, 17, y, TFT_WHITE);
        tft.drawLine(17, y + 14, 17, y + 10, TFT_WHITE);
        tft.drawLine(17, y + 14, 21, y + 14, TFT_WHITE);

        tft.drawLine(153, y, 157, y, TFT_WHITE);
        tft.drawLine(157, y + 4, 157, y, TFT_WHITE);
        tft.drawLine(157, y + 14, 157, y + 10, TFT_WHITE);
        tft.drawLine(153, y + 14, 157, y + 14, TFT_WHITE);

        if (yAxis == 1 && xAxis == 0) {
          tft.drawString("Home", 17, 114);
          tft.drawString("WiFi Scanner", 23, 134);
        }
        if (yAxis == 2 && xAxis == 0) {
          tft.drawString("WiFi Scanner", 17, 134);
          tft.drawString("Deauth Selected", 23, 154);
        }
        if (yAxis == 3 && xAxis == 0) {
          tft.drawString("Deauth Selected", 17, 154);
          tft.drawString("Deauth Flood", 23, 174);
        }
      }

      if (xAxis == 1 && yAxis < 4) {
        yAxis++;
        y = 83 + (yAxis * 20);

        tft.fillRect(175, y - 20, 112, 20, TFT_BLACK);
        tft.fillRect(175, y, 112, 20, TFT_BLACK);

        tft.drawLine(175, y, 179, y, TFT_WHITE);
        tft.drawLine(175, y + 4, 175, y, TFT_WHITE);
        tft.drawLine(175, y + 14, 175, y + 10, TFT_WHITE);
        tft.drawLine(175, y + 14, 179, y + 14, TFT_WHITE);

        tft.drawLine(282, y, 286, y, TFT_WHITE);
        tft.drawLine(286, y + 4, 286, y, TFT_WHITE);
        tft.drawLine(286, y + 14, 286, y + 10, TFT_WHITE);
        tft.drawLine(282, y + 14, 286, y + 14, TFT_WHITE);

        if (yAxis == 1) {
          tft.drawString("PMKID Attack", 175, 88);
          tft.drawString("Handshake Sniffing", 181, 108);
        }
        if (yAxis == 2) {
          tft.drawString("Handshake Sniffing", 175, 108);
          tft.drawString("Rogue Portal", 181, 128);
        }
        if (yAxis == 3) {
          tft.drawString("Rogue Portal", 175, 128);
          tft.drawString("BSSID Flood", 181, 148);
        }
        if (yAxis == 4) {
          tft.drawString("BSSID Flood", 175, 148);
          tft.drawString("BSSID Clone", 181, 168);
        }
      }
      break;

    case 2: // Right
      if (xAxis == 0) {
        int y = 109 + (yAxis * 20);
        tft.fillRect(17, y, 141, 20, TFT_BLACK);  // Clear left box

        xAxis = 1;

        y = 83;  // Right always starts at y=83
        tft.fillRect(175, y, 112, 20, TFT_BLACK); // Clear right box
        tft.drawString("PMKID Attack", 181, 88);

        // Draw selection box on right
        tft.drawLine(175, y, 179, y, 0xFFFF);
        tft.drawLine(175, y + 4, 175, y, 0xFFFF);
        tft.drawLine(175, y + 14, 175, y + 10, 0xFFFF);
        tft.drawLine(175, y + 14, 179, y + 14, 0xFFFF);

        tft.drawLine(282, y, 286, y, 0xFFFF);
        tft.drawLine(286, y + 4, 286, y, 0xFFFF);
        tft.drawLine(286, y + 14, 286, y + 10, 0xFFFF);
        tft.drawLine(282, y + 14, 286, y + 14, 0xFFFF);

        // Restore label on left
        if (yAxis == 0) tft.drawString("Home", 17, 114);
        if (yAxis == 1) tft.drawString("WiFi Scanner", 17, 134);
        if (yAxis == 2) tft.drawString("Deauth Selected", 17, 154);
        if (yAxis == 3) tft.drawString("Deauth Flood", 17, 174);

        yAxis = 0;  // Now reset for right-side navigation
      }
      break;

    case 3: // Left
      if (xAxis == 1) {
        int y = 83 + (yAxis * 20);
        tft.fillRect(175, y, 112, 20, TFT_BLACK); // Clear right box

        xAxis = 0;

        y = 109;  // Left always starts at y=109
        tft.fillRect(17, y, 141, 20, TFT_BLACK);  // Clear left box
        tft.drawString("Home", 23, 114);

        // Draw selection box on left
        tft.drawLine(17, y, 21, y, 0xFFFF);
        tft.drawLine(17, y + 4, 17, y, 0xFFFF);
        tft.drawLine(17, y + 14, 17, y + 10, 0xFFFF);
        tft.drawLine(17, y + 14, 21, y + 14, 0xFFFF);

        tft.drawLine(153, y, 157, y, 0xFFFF);
        tft.drawLine(157, y + 4, 157, y, 0xFFFF);
        tft.drawLine(157, y + 14, 157, y + 10, 0xFFFF);
        tft.drawLine(153, y + 14, 157, y + 14, 0xFFFF);

        // Restore label on right
        if (yAxis == 0) tft.drawString("PMKID Attack", 175, 88);
        if (yAxis == 1) tft.drawString("Handshake Sniffing", 175, 108);
        if (yAxis == 2) tft.drawString("Rogue Portal", 175, 128);
        if (yAxis == 3) tft.drawString("BSSID Flood", 175, 148);
        if (yAxis == 4) tft.drawString("BSSID Clone", 175, 168);

        yAxis = 0;  // Reset after drawing
      }
      break;

    case 4: // Select
      if (yAxis == 0 && xAxis == 0) {
        uiState = 0;
        yAxis = 0;
        xAxis = 0;
        clearMainArea();
        drawHomeScreen();
      }
      break;

  }
}

/*  

BLUETOOTH SCREEN FUNCTIONS

*/

void handleDirectionBluetooth(int dir) {
  // dir: 0=Up, 1=Down, 2=Right, 3=Left

  switch (dir) {
    case 0: // Up
      if (xAxis == 0 && yAxis > 0) {
        yAxis--;
        y = 109 + (yAxis * 20);

        tft.fillRect(17, y + 20, 141, 20, TFT_BLACK);
        tft.fillRect(17, y, 141, 20, TFT_BLACK);

        tft.drawLine(17, y, 21, y, TFT_WHITE);
        tft.drawLine(17, y + 4, 17, y, TFT_WHITE);
        tft.drawLine(17, y + 14, 17, y + 10, TFT_WHITE);
        tft.drawLine(17, y + 14, 21, y + 14, TFT_WHITE);

        tft.drawLine(153, y, 157, y, TFT_WHITE);
        tft.drawLine(157, y + 4, 157, y, TFT_WHITE);
        tft.drawLine(157, y + 14, 157, y + 10, TFT_WHITE);
        tft.drawLine(153, y + 14, 157, y + 14, TFT_WHITE);

        if (yAxis == 0 && xAxis == 0) {
          tft.drawString("Home", 23, 114);
          tft.drawString("Bluetooth Scanner", 17, 134);
        }
        if (yAxis == 1 && xAxis == 0) {
          tft.drawString("Bluetooth Scanner", 23, 134);
          tft.drawString("Beacon Spamming", 17, 154);
        }
        if (yAxis == 2 && xAxis == 0) {
          tft.drawString("Beacon Spamming", 23, 154);
          tft.drawString("Device Impersonation", 17, 174);
        }
      }

      if (xAxis == 1 && yAxis > 0) {
        yAxis--;
        y = 83 + (yAxis * 20);

        tft.fillRect(175, y + 20, 112, 20, TFT_BLACK);
        tft.fillRect(175, y, 112, 20, TFT_BLACK);

        tft.drawLine(175, y, 179, y, TFT_WHITE);
        tft.drawLine(175, y + 4, 175, y, TFT_WHITE);
        tft.drawLine(175, y + 14, 175, y + 10, TFT_WHITE);
        tft.drawLine(175, y + 14, 179, y + 14, TFT_WHITE);

        tft.drawLine(282, y, 286, y, TFT_WHITE);
        tft.drawLine(286, y + 4, 286, y, TFT_WHITE);
        tft.drawLine(286, y + 14, 286, y + 10, TFT_WHITE);
        tft.drawLine(282, y + 14, 286, y + 14, TFT_WHITE);

        // Add text label drawing here if needed
        if (yAxis == 0) {
          tft.drawString("Denial Of Service", 181, 88);
          tft.drawString("Popup Trigger", 175, 108);
        }
        if (yAxis == 1) {
          tft.drawString("Popup Trigger", 181, 108);
          tft.drawString("Profile Poisoning", 175, 128);
        }
        if (yAxis == 2) {
          tft.drawString("Profile Poisoning", 181, 128);
          tft.drawString("HID Injection", 175, 148);
        }
        if (yAxis == 3) {
          tft.drawString("HID Injection", 181, 148);
          tft.drawString("Firmware Bomb", 175, 168);
        }
      }
      break;

    case 1: // Down
      if (xAxis == 0 && yAxis < 3) {
        yAxis++;
        y = 109 + (yAxis * 20);

        tft.fillRect(17, y - 20, 141, 20, TFT_BLACK);
        tft.fillRect(17, y, 141, 20, TFT_BLACK);

        tft.drawLine(17, y, 21, y, TFT_WHITE);
        tft.drawLine(17, y + 4, 17, y, TFT_WHITE);
        tft.drawLine(17, y + 14, 17, y + 10, TFT_WHITE);
        tft.drawLine(17, y + 14, 21, y + 14, TFT_WHITE);

        tft.drawLine(153, y, 157, y, TFT_WHITE);
        tft.drawLine(157, y + 4, 157, y, TFT_WHITE);
        tft.drawLine(157, y + 14, 157, y + 10, TFT_WHITE);
        tft.drawLine(153, y + 14, 157, y + 14, TFT_WHITE);

        if (yAxis == 1 && xAxis == 0) {
          tft.drawString("Home", 17, 114);
          tft.drawString("Bluetooth Scanner", 23, 134);
        }
        if (yAxis == 2 && xAxis == 0) {
          tft.drawString("Bluetoot Scanner", 17, 134);
          tft.drawString("Beacon Spamming", 23, 154);
        }
        if (yAxis == 3 && xAxis == 0) {
          tft.drawString("Beacon Spamming", 17, 154);
          tft.drawString("Device Impersonation", 23, 174);
        }
      }

      if (xAxis == 1 && yAxis < 4) {
        yAxis++;
        y = 83 + (yAxis * 20);

        tft.fillRect(175, y - 20, 112, 20, TFT_BLACK);
        tft.fillRect(175, y, 112, 20, TFT_BLACK);

        tft.drawLine(175, y, 179, y, TFT_WHITE);
        tft.drawLine(175, y + 4, 175, y, TFT_WHITE);
        tft.drawLine(175, y + 14, 175, y + 10, TFT_WHITE);
        tft.drawLine(175, y + 14, 179, y + 14, TFT_WHITE);

        tft.drawLine(282, y, 286, y, TFT_WHITE);
        tft.drawLine(286, y + 4, 286, y, TFT_WHITE);
        tft.drawLine(286, y + 14, 286, y + 10, TFT_WHITE);
        tft.drawLine(282, y + 14, 286, y + 14, TFT_WHITE);

        if (yAxis == 1) {
          tft.drawString("Denial Of Service", 175, 88);
          tft.drawString("Popup Trigger", 181, 108);
        }
        if (yAxis == 2) {
          tft.drawString("Popup Trigger", 175, 108);
          tft.drawString("Profile Poisoning", 181, 128);
        }
        if (yAxis == 3) {
          tft.drawString("Profile Poisoning", 175, 128);
          tft.drawString("HID Injection", 181, 148);
        }
        if (yAxis == 4) {
          tft.drawString("HID Injection", 175, 148);
          tft.drawString("Firmware Bomb", 181, 168);
        }
      }
      break;

    case 2: // Right
      if (xAxis == 0) {
        int y = 109 + (yAxis * 20);
        tft.fillRect(17, y, 141, 20, TFT_BLACK);  // Clear left box

        xAxis = 1;

        y = 83;  // Right always starts at y=83
        tft.fillRect(175, y, 112, 20, TFT_BLACK); // Clear right box
        tft.drawString("Denial Of Service", 181, 88);

        // Draw selection box on right
        tft.drawLine(175, y, 179, y, 0xFFFF);
        tft.drawLine(175, y + 4, 175, y, 0xFFFF);
        tft.drawLine(175, y + 14, 175, y + 10, 0xFFFF);
        tft.drawLine(175, y + 14, 179, y + 14, 0xFFFF);

        tft.drawLine(282, y, 286, y, 0xFFFF);
        tft.drawLine(286, y + 4, 286, y, 0xFFFF);
        tft.drawLine(286, y + 14, 286, y + 10, 0xFFFF);
        tft.drawLine(282, y + 14, 286, y + 14, 0xFFFF);

        // Restore label on left
        if (yAxis == 0) tft.drawString("Home", 17, 114);
        if (yAxis == 1) tft.drawString("Bluetooth Scanner", 17, 134);
        if (yAxis == 2) tft.drawString("Beacon Spamming", 17, 154);
        if (yAxis == 3) tft.drawString("Device Impersonation", 17, 174);

        yAxis = 0;  // Now reset for right-side navigation
      }
      break;

    case 3: // Left
      if (xAxis == 1) {
        int y = 83 + (yAxis * 20);
        tft.fillRect(175, y, 112, 20, TFT_BLACK); // Clear right box

        xAxis = 0;

        y = 109;  // Left always starts at y=109
        tft.fillRect(17, y, 141, 20, TFT_BLACK);  // Clear left box
        tft.drawString("Home", 23, 114);

        // Draw selection box on left
        tft.drawLine(17, y, 21, y, 0xFFFF);
        tft.drawLine(17, y + 4, 17, y, 0xFFFF);
        tft.drawLine(17, y + 14, 17, y + 10, 0xFFFF);
        tft.drawLine(17, y + 14, 21, y + 14, 0xFFFF);

        tft.drawLine(153, y, 157, y, 0xFFFF);
        tft.drawLine(157, y + 4, 157, y, 0xFFFF);
        tft.drawLine(157, y + 14, 157, y + 10, 0xFFFF);
        tft.drawLine(153, y + 14, 157, y + 14, 0xFFFF);

        // Restore label on right
        if (yAxis == 0) tft.drawString("Denial Of Service", 175, 88);
        if (yAxis == 1) tft.drawString("Popup Trigger", 175, 108);
        if (yAxis == 2) tft.drawString("Profile Poisoning", 175, 128);
        if (yAxis == 3) tft.drawString("HID Injection", 175, 148);
        if (yAxis == 4) tft.drawString("Firware Bomb", 175, 168);

        yAxis = 0;  // Reset after drawing
      }
      break;

    case 4: // Select
      if (yAxis == 0 && xAxis == 0) {
        uiState = 0;
        yAxis = 0;
        xAxis = 0;
        clearMainArea();
        drawHomeScreen();
      }
      break;

  }
}