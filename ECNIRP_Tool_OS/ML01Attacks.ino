#include "RF24.h"

static SPIClass sp(VSPI);

// Pin Configuration
#define RF24_CE_PIN 16
#define RF24_CSN_PIN 17
#define TFT_SCK 18
#define TFT_MISO 19
#define TFT_MOSI 23

RF24 radio(RF24_CE_PIN, RF24_CSN_PIN, 16000000);

byte channel = 45;  // Start channel
extern String state;

void initML01() {
  sp.begin(TFT_SCK, TFT_MISO, TFT_MOSI, RF24_CSN_PIN);
  delayMicroseconds(100);
  if (!radio.begin(&sp)) {
    Serial.println("NRF24 initialization failed!");
    state = "Inactive";
  }
  radio.stopListening();
  radio.setAutoAck(false);
  radio.setRetries(0, 0);
  radio.setPayloadSize(esp_random() % 12 + 21);
  radio.setAddressWidth(esp_random() % 2 + 3); // Random 3–4 bytes
  radio.setPALevel(RF24_PA_MAX, true);
  radio.setDataRate(RF24_2MBPS);
  radio.setCRCLength(RF24_CRC_DISABLED);
  radio.setChannel(channel);
  uint64_t pipeAddr = ((uint64_t)esp_random() << 32) | esp_random();
  radio.openWritingPipe(pipeAddr);
  radio.printPrettyDetails();
  Serial.println("NRF24 Initialized");
  state = "Active";
  clearStateArea();
  tft.drawString("ML01DP5 Module: " + state, 17, 85);
}

void deinitML01() {
  radio.stopListening();
  radio.stopConstCarrier();

  radio.setAutoAck(false);

  for (uint8_t i = 0; i < 6; i++) {
    radio.closeReadingPipe(i);
  }

  radio.setCRCLength(RF24_CRC_DISABLED);
  radio.setRetries(0, 0);
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_1MBPS);
  radio.setChannel(0);

  // Set a dummy address to fully close pipe behavior
  radio.openReadingPipe(1, (uint64_t)0xE7E7E7E7E7);
  radio.flush_rx();
  radio.flush_tx();

  disableNRF24();

  state = "Inactive";
  Serial.println("NRF24 fully deinitialized.");
}


void startBroadcastingML01() {
  radio.startConstCarrier(RF24_PA_MAX, channel);
}

void stopBroadcastingML01() {
  radio.stopConstCarrier();
  initML01();
}

void hopChannelBluetooth() {
  reinitAfterAnalyzer();
  for (int ch = 0; ch <= 85; ch += esp_random() % 1 + 2){ // Or channel += 2 for simpler syntax
    radio.setChannel(ch);
  }
}

void hopChannelWifi() {
  reinitAfterAnalyzer();
  for (int ch = 0; ch <= 13; ch += esp_random() % 1 + 2){ // Or channel += 2 for simpler syntax
    radio.setChannel(ch);
  }
}

void hopChannelDrone() {
  reinitAfterAnalyzer();
  for (int ch = 80; ch <= 125; ch += esp_random() % 1 + 2){ // Or channel += 2 for simpler syntax
    radio.setChannel(ch);
  }
}

void hopChannelAll() {
  reinitAfterAnalyzer();
  for (int ch = 0; ch <= 125; ch += esp_random() % 1 + 2){ // Or channel += 2 for simpler syntax
    radio.setChannel(ch);
  }
}

void drawNRFChannelAnalyzer() {
  const uint8_t totalChannels = 126;
  const uint8_t barCount = 42;
  const uint8_t barWidth = 7;
  const uint8_t barMaxHeight = 13;
  const uint8_t barBaseY = 203;
  const uint8_t smoothingSteps = 1;

  static uint8_t currentHeights[barCount] = {0};
  uint8_t targetHeights[barCount] = {0};

  // Prepare radio
  radio.stopListening();
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_1MBPS);
  radio.setChannel(0);
  radio.openReadingPipe(1, 0xF0F0F0F0E1LL);
  radio.startListening();

  // Scan activity
  for (uint8_t ch = 0; ch < totalChannels; ch++) {
    radio.setChannel(ch);
    delayMicroseconds(350);
    if (radio.testRPD()) {
      targetHeights[ch / 3]++;
    }
  }

  radio.stopListening();

  // Map activity to heights
  for (uint8_t i = 0; i < barCount; i++) {
    targetHeights[i] = map(targetHeights[i], 0, 3, 1, barMaxHeight);
    if (targetHeights[i] > barMaxHeight) targetHeights[i] = barMaxHeight;
  }

  // Smooth animation
  for (uint8_t step = 0; step < smoothingSteps; step++) {
    for (uint8_t i = 0; i < barCount; i++) {
      if (currentHeights[i] < targetHeights[i]) currentHeights[i]++;
      else if (currentHeights[i] > targetHeights[i]) currentHeights[i]--;

      uint16_t x = 13 + (i * barWidth);
      tft.fillRect(x, barBaseY, barWidth - 1, barMaxHeight, TFT_BLACK);

      uint8_t h = currentHeights[i];
      uint16_t y = barBaseY + (barMaxHeight - h);

      // Hard switch: Cyan for low, Red for high
      uint16_t barColor = (h < barMaxHeight / 2)
                          ? TFT_CYAN
                          : TFT_RED;

      if (h > 1) {
        tft.fillRect(x, y + 1, barWidth - 1, h - 1, barColor);
      }

      tft.drawFastHLine(x, y, barWidth - 1, barColor); // tip matches bar
    }

    delay(10);
  }
}

void disableNRF24() {
  radio.powerDown();
  digitalWrite(RF24_CE_PIN, LOW);   // disable TX/RX
  digitalWrite(RF24_CSN_PIN, HIGH); // release SPI
}

void reinitAfterAnalyzer() {
  radio.stopListening();
  radio.setAutoAck(false);
  radio.setRetries(0, 0);
  radio.setPayloadSize(esp_random() % 12 + 21);
  radio.setAddressWidth(esp_random() % 2 + 3); // Random 3–4 bytes
  radio.setPALevel(RF24_PA_MAX, true);
  radio.setDataRate(RF24_2MBPS);
  radio.setCRCLength(RF24_CRC_DISABLED);
  radio.setChannel(channel);
  uint64_t pipeAddr = ((uint64_t)esp_random() << 32) | esp_random();
  radio.openWritingPipe(pipeAddr);
  radio.startConstCarrier(RF24_PA_MAX, channel);
}
