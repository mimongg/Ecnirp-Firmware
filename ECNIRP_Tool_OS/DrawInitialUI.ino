#include "Org_01.h"

static const unsigned char PROGMEM image_network_3_bars_bits[] = {0x00,0x0e,0x00,0x0a,0x00,0x0a,0x00,0x0a,0x00,0xea,0x00,0xea,0x00,0xea,0x00,0xea,0x0e,0xea,0x0e,0xea,0x0e,0xea,0x0e,0xea,0xee,0xea,0xee,0xea,0xee,0xee,0x00,0x00};

static const unsigned char PROGMEM image_SmallArrowUp_bits[] = {0x20,0x70,0xf8};

static const unsigned char PROGMEM image_SmallArrowDown_bits[] = {0xf8,0x70,0x20};

static const unsigned char PROGMEM image_ButtonRightSmall_bits[] = {0x80,0xc0,0xe0,0xc0,0x80};

static const unsigned char PROGMEM image_ButtonLeftSmall_bits[] = {0x20,0x60,0xe0,0x60,0x20};

static const unsigned char PROGMEM image_ButtonCenter_bits[] = {0x38,0x44,0xba,0xba,0xba,0x44,0x38};

static const unsigned char PROGMEM image_wifi_75_bits[] = {0x01,0xf0,0x00,0x06,0x0c,0x00,0x18,0x03,0x00,0x21,0xf0,0x80,0x47,0xfc,0x40,0x8f,0x1e,0x20,0x5c,0xe7,0x40,0x3b,0xfb,0x80,0x17,0x1d,0x00,0x0e,0xee,0x00,0x05,0xf4,0x00,0x03,0xb8,0x00,0x01,0x50,0x00,0x00,0xe0,0x00,0x00,0x40,0x00,0x00,0x00,0x00};

static const unsigned char PROGMEM image_download_bits[] = {0x01,0x00,0x02,0x80,0x02,0x40,0x22,0x20,0x12,0x20,0x4a,0x48,0x26,0x90,0x33,0x30,0x26,0x90,0x4a,0x48,0x12,0x20,0x22,0x20,0x02,0x40,0x02,0x80,0x01,0x00,0x00,0x00};

static const unsigned char PROGMEM image_cards_hearts_bits[] = {0x00,0x00,0x00,0x00,0x38,0x38,0x7c,0x7c,0xfe,0xfe,0xff,0xfe,0xff,0xfe,0xff,0xfe,0x7f,0xfc,0x3f,0xf8,0x1f,0xf0,0x0f,0xe0,0x07,0xc0,0x03,0x80,0x01,0x00,0x00,0x00};

static const unsigned char PROGMEM image_download_1_bits[] = {0x00,0x00,0xff,0xff,0x80,0x01,0xbf,0xfd,0xa0,0x05,0xa0,0x05,0xa0,0x05,0xa0,0x05,0xa0,0x05,0xbf,0xfd,0x80,0x01,0xff,0xff,0x03,0xc0,0x03,0xc0,0x0f,0xf0,0x00,0x00};

static const unsigned char PROGMEM image_download_3_bits[] = {0x07,0xc0,0x18,0x30,0x27,0xc8,0x48,0x24,0x93,0x92,0xa4,0x4a,0xa9,0x2a,0xa3,0x8a,0x06,0xc0,0x03,0x80,0x01,0x00,0x03,0x80,0x02,0x80,0x06,0xc0,0x04,0x40,0x00,0x00};

 
void drawInitial(void) {
    tft.fillRect(0, 0, 320, 240, 0x0);

    tft.drawLine(20, 33, 13, 33, 0xFFFF);

    tft.drawLine(20, 5, 12, 5, 0xFFFF);

    tft.drawLine(307, 33, 300, 33, 0xFFFF);

    tft.drawLine(307, 5, 300, 5, 0xFFFF);

    tft.drawLine(307, 6, 307, 32, 0xFFFF);

    tft.drawLine(12, 6, 12, 33, 0xFFFF);

    tft.fillRect(15, 8, 290, 23, 0xFFFF);

    tft.drawLine(11, 19, 5, 19, 0xFFFF);

    tft.drawLine(135, 229, 5, 229, 0xFFFF);

    tft.drawLine(5, 20, 5, 228, 0xFFFF);

    tft.drawLine(314, 19, 307, 19, 0xFFFF);

    tft.drawLine(314, 229, 184, 229, 0xFFFF);

    tft.setTextColor(0x0);
    tft.setTextSize(2);
    tft.setFreeFont(&Org_01);
    tft.drawString("ECNIRP TOOL", 95, 15);

    tft.drawRect(135, 223, 50, 13, 0xFFFF);

    tft.drawLine(314, 20, 314, 228, 0xFFFF);

    tft.setTextColor(0xFFFF);
    tft.setTextSize(1);
    tft.drawString("100%", 152, 227);

    tft.drawLine(12, 217, 124, 217, 0xFFFF);

    tft.drawLine(11, 217, 11, 163, 0xFFFF);

    tft.drawLine(124, 217, 124, 163, 0xFFFF);

    tft.drawLine(12, 163, 124, 163, 0xFFFF);

    tft.drawLine(164, 127, 130, 161, 0xFFFF);

    tft.drawLine(130, 217, 220, 217, 0xFFFF);

    tft.drawLine(164, 127, 219, 127, 0xFFFF);

    tft.drawLine(220, 217, 220, 127, 0xFFFF);

    tft.drawLine(130, 217, 130, 162, 0xFFFF);

    tft.drawLine(226, 217, 226, 128, 0xFFFF);

    tft.drawLine(226, 217, 307, 217, 0xFFFF);

    tft.drawLine(308, 217, 308, 128, 0xFFFF);

    tft.drawLine(226, 127, 308, 127, 0xFFFF);

    tft.drawLine(169, 121, 307, 121, 0xFFFF);

    tft.drawLine(308, 121, 308, 77, 0xFFFF);

    tft.drawLine(169, 121, 169, 77, 0xFFFF);

    tft.drawLine(169, 77, 307, 77, 0xFFFF);

    tft.drawLine(169, 71, 307, 71, 0xFFFF);

    tft.drawLine(169, 38, 307, 38, 0xFFFF);

    tft.drawLine(169, 71, 169, 38, 0xFFFF);

    tft.drawLine(308, 71, 308, 38, 0xFFFF);

    tft.setTextSize(2);
    tft.drawString("Archives", 173, 108);
    
    tft.drawString("Bluetooth", 15, 204);

    tft.drawString("Open", 15, 189);

    tft.drawString("2.4GHz", 134, 204);

    tft.drawString("1.0GHz", 231, 204);

    tft.drawString("Sub", 230, 191);

    tft.setTextSize(1);
    tft.drawString("ML01DP5", 180, 131);

    tft.drawString("CC1101", 282, 131);

    tft.fillEllipse(302, 211, 2, 2, 0xFFFF);

    tft.fillEllipse(214, 211, 2, 2, 0xFFFF);

    tft.fillEllipse(118, 211, 2, 2, 0xFFFF);

    tft.fillEllipse(302, 115, 2, 2, 0xFFFF);

    tft.setTextSize(1);
    tft.drawString("ESP32-WROOM", 57, 167);

    tft.drawString("File Browser", 248, 81);

    tft.drawBitmap(134, 172, image_network_3_bars_bits, 15, 16, 0xFFFF);

    tft.drawLine(11, 71, 53, 71, 0xFFFF);

    tft.drawLine(11, 71, 11, 38, 0xFFFF);

    tft.drawLine(53, 71, 53, 38, 0xFFFF);

    tft.drawLine(59, 38, 163, 38, 0xFFFF);

    tft.drawLine(59, 71, 59, 38, 0xFFFF);

    tft.drawLine(163, 71, 163, 38, 0xFFFF);

    tft.drawLine(11, 38, 53, 38, 0xFFFF);

    tft.drawLine(59, 71, 163, 71, 0xFFFF);

    tft.drawString("EXP: 100/235", 63, 63);

    tft.drawString("ACC: Prince", 63, 42);

    tft.drawString("LVL: 21", 63, 52);

    tft.drawBitmap(11, 223, image_SmallArrowUp_bits, 5, 3, 0xFFFF);

    tft.drawString("Up", 18, 222);

    tft.drawBitmap(33, 223, image_SmallArrowDown_bits, 5, 3, 0xFFFF);

    tft.drawString("Down", 40, 222);

    tft.drawBitmap(97, 222, image_ButtonRightSmall_bits, 3, 5, 0xFFFF);

    tft.drawString("Right", 102, 222);

    tft.drawBitmap(66, 222, image_ButtonLeftSmall_bits, 3, 5, 0xFFFF);

    tft.drawString("Left", 72, 222);

    tft.drawString("Select", 199, 222);

    tft.drawString("X", 232, 222);

    tft.drawString("Back", 239, 222);

    tft.drawBitmap(190, 221, image_ButtonCenter_bits, 7, 7, 0xFFFF);

    tft.setTextSize(2);
    tft.drawString("All", 134, 191);

    tft.drawBitmap(13, 170, image_download_bits, 14, 16, 0xFFFF);

    tft.drawBitmap(14, 170, image_download_bits, 14, 16, 0xFFFF);

    tft.drawBitmap(145, 53, image_cards_hearts_bits, 15, 16, 0xFFFF);

    tft.drawBitmap(173, 89, image_download_1_bits, 16, 16, 0xFFFF);

    tft.drawBitmap(230, 172, image_download_3_bits, 15, 16, 0xFFFF);
    tft.drawLine(164, 128, 130, 162, 0xFFFF);

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


/* 

HOME SCREEN DRAW CALL FUNCTION

*/

void drawHomeScreen(void) {
    tft.drawLine(8, 75, 8, 159, 0x7DF);

    tft.drawLine(8, 74, 165, 74, 0x7DF);

    tft.drawLine(166, 74, 166, 121, 0x7DF);

    tft.drawLine(8, 160, 128, 160, 0x7DF);

    tft.drawLine(166, 121, 128, 159, 0x7DF);

    tft.drawLine(12, 217, 124, 217, 0xFFFF);

    tft.drawLine(11, 217, 11, 163, 0xFFFF);

    tft.drawLine(124, 217, 124, 163, 0xFFFF);

    tft.drawLine(12, 163, 124, 163, 0xFFFF);

    tft.drawLine(164, 127, 130, 161, 0xFFFF);

    tft.drawLine(130, 217, 220, 217, 0xFFFF);

    tft.drawLine(164, 127, 219, 127, 0xFFFF);

    tft.drawLine(220, 217, 220, 127, 0xFFFF);

    tft.drawLine(130, 217, 130, 162, 0xFFFF);

    tft.drawLine(226, 217, 226, 128, 0xFFFF);

    tft.drawLine(226, 217, 307, 217, 0xFFFF);

    tft.drawLine(308, 217, 308, 128, 0xFFFF);

    tft.drawLine(226, 127, 308, 127, 0xFFFF);

    tft.drawLine(169, 121, 307, 121, 0xFFFF);

    tft.drawLine(308, 121, 308, 77, 0xFFFF);

    tft.drawLine(169, 121, 169, 77, 0xFFFF);

    tft.drawLine(169, 77, 307, 77, 0xFFFF);

    tft.setTextColor(0xFFFF);
    tft.setTextSize(2);
    tft.setFreeFont(&Org_01);
    tft.drawString("Archives", 173, 108);

    tft.drawString("Bluetooth", 15, 204);

    tft.drawString("Open", 15, 189);

    tft.drawString("2.4GHz", 134, 204);

    tft.drawString("1.0GHz", 231, 204);

    tft.drawString("Sub", 230, 191);

    tft.setTextSize(1);
    tft.drawString("ML01DP5", 180, 131);

    tft.drawString("CC1101", 282, 131);

    tft.fillEllipse(302, 211, 2, 2, 0xFFFF);

    tft.fillEllipse(214, 211, 2, 2, 0xFFFF);

    tft.fillEllipse(118, 211, 2, 2, 0xFFFF);

    tft.fillEllipse(302, 115, 2, 2, 0xFFFF);

    tft.setTextColor(0x7DF);
    tft.setTextSize(2);
    tft.drawString("WiFi", 12, 134);

    tft.drawString("Attacks", 12, 147);

    tft.setTextColor(0xFFFF);
    tft.setTextSize(1);
    tft.drawString("ESP32-WROOM", 57, 167);

    tft.drawString("File Browser", 248, 81);

    tft.setTextColor(0x7DF);
    tft.drawString("ESP32-WROOM", 99, 78);

    tft.setTextColor(0xFFFF);
    tft.setTextSize(2);
    tft.drawString("All", 134, 191);

    tft.fillEllipse(122, 154, 2, 2, 0x7DF);

    tft.drawLine(166, 122, 128, 160, 0x7DF);

    tft.drawLine(164, 128, 130, 162, 0xFFFF);
    tft.drawBitmap(11, 115, image_wifi_75_bits, 19, 16, 0x7DF);
    tft.drawBitmap(13, 170, image_download_bits, 14, 16, 0xFFFF);

    tft.drawBitmap(14, 170, image_download_bits, 14, 16, 0xFFFF);

    tft.drawBitmap(145, 53, image_cards_hearts_bits, 15, 16, 0xFFFF);

    tft.drawBitmap(173, 89, image_download_1_bits, 16, 16, 0xFFFF);

    tft.drawBitmap(230, 172, image_download_3_bits, 15, 16, 0xFFFF);

}
