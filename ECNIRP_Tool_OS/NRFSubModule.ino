static const unsigned char PROGMEM image_download_bits_leftArr[] = {0x20,0x60,0xe0,0x60,0x20};

String state = "Inactive";

void clearMainArea() {
  tft.fillRect(11, 77, 298, 142, 0x0);
}

void clearStateArea() {
  tft.fillRect(17, 85, 125, 5, 0x0);
}

void clearEarsArea() {
  tft.fillRect(17, 35, 31, 3, 0x0);
}

void drawEars() {
  tft.drawBitmap(17, 35, image_SmallArrowUp_bits, 5, 3, 0xFFFF);
  tft.drawBitmap(43, 35, image_SmallArrowUp_bits, 5, 3, 0xFFFF);
}

void drawNRFSubModule(void) {
    tft.drawRect(11, 199, 298, 19, 0xFFFF);

    tft.drawRect(11, 103, 153, 91, 0xFFFF);

    tft.drawRect(11, 77, 153, 21, 0xFFFF);

    tft.setTextColor(0xFFFF);
    tft.setTextSize(1);
    tft.setFreeFont(&Org_01);
    tft.drawString("ML01DP5 Module: " + state, 17, 85);

    tft.drawLine(308, 77, 302, 77, 0xFFFF);

    tft.drawLine(308, 193, 302, 193, 0xFFFF);

    tft.drawLine(302, 193, 302, 77, 0xFFFF);

    tft.drawLine(302, 81, 300, 81, 0xFFFF);

    tft.drawLine(302, 85, 300, 85, 0xFFFF);

    tft.drawLine(302, 89, 300, 89, 0xFFFF);

    tft.drawLine(302, 93, 300, 93, 0xFFFF);

    tft.drawLine(302, 97, 298, 97, 0xFFFF);

    tft.drawLine(302, 105, 300, 105, 0xFFFF);

    tft.drawLine(302, 101, 300, 101, 0xFFFF);

    tft.drawLine(302, 109, 300, 109, 0xFFFF);

    tft.drawLine(302, 113, 300, 113, 0xFFFF);

    tft.drawLine(302, 117, 298, 117, 0xFFFF);

    tft.drawLine(302, 125, 300, 125, 0xFFFF);

    tft.drawLine(302, 121, 300, 121, 0xFFFF);

    tft.drawLine(302, 129, 300, 129, 0xFFFF);

    tft.drawLine(302, 133, 300, 133, 0xFFFF);

    tft.drawLine(302, 137, 298, 137, 0xFFFF);

    tft.drawLine(302, 145, 300, 145, 0xFFFF);

    tft.drawLine(302, 141, 300, 141, 0xFFFF);

    tft.drawLine(302, 149, 300, 149, 0xFFFF);

    tft.drawLine(302, 153, 300, 153, 0xFFFF);

    tft.drawLine(302, 157, 298, 157, 0xFFFF);

    tft.drawLine(302, 165, 300, 165, 0xFFFF);

    tft.drawLine(302, 161, 300, 161, 0xFFFF);

    tft.drawLine(302, 169, 300, 169, 0xFFFF);

    tft.drawLine(302, 173, 300, 173, 0xFFFF);

    tft.drawLine(302, 177, 298, 177, 0xFFFF);

    tft.drawLine(302, 181, 300, 181, 0xFFFF);

    tft.drawLine(302, 185, 300, 185, 0xFFFF);

    tft.drawLine(302, 189, 300, 189, 0xFFFF);

    tft.drawLine(17, 109, 21, 109, 0xFFFF);

    tft.drawLine(17, 113, 17, 109, 0xFFFF);

    tft.drawLine(17, 123, 21, 123, 0xFFFF);

    tft.drawLine(17, 123, 17, 119, 0xFFFF);

    tft.drawLine(153, 109, 157, 109, 0xFFFF);

    tft.drawLine(153, 123, 157, 123, 0xFFFF);

    tft.drawLine(157, 113, 157, 109, 0xFFFF);

    tft.drawLine(157, 123, 157, 119, 0xFFFF);

    tft.drawString("Home", 23, 114);

    tft.drawString("Packet Sniffer", 17, 134);

    tft.drawString("WiFi Jammer", 17, 154);

    tft.drawString("Bluetooth Jammer", 17, 174);

    tft.drawRect(169, 77, 124, 117, 0xFFFF);

    tft.drawString("Drone Jammer", 175, 88);

    tft.drawString("Sweep Jammer", 175, 108);

    tft.drawString("Replay Attack", 175, 128);

    tft.drawString("Protocol Fuzzing", 175, 148);

    tft.drawString("Pipe Hijacking", 175, 168);

}


/* 

CC1101 SCREEN DRAW

*/

void drawCC1101SubModule(void) {
    tft.drawRect(11, 199, 298, 19, 0xFFFF);

    tft.drawRect(11, 77, 153, 21, 0xFFFF);

    tft.drawRect(11, 103, 153, 91, 0xFFFF);

    tft.setTextColor(0xFFFF);
    tft.setTextSize(1);
    tft.setFreeFont(&Org_01);
    tft.drawString("CC1101 Module: " + state, 17, 85);

    tft.drawLine(308, 193, 302, 193, 0xFFFF);

    tft.drawLine(308, 77, 302, 77, 0xFFFF);

    tft.drawLine(302, 193, 302, 77, 0xFFFF);

    tft.drawLine(302, 85, 300, 85, 0xFFFF);

    tft.drawLine(302, 81, 300, 81, 0xFFFF);

    tft.drawLine(302, 89, 300, 89, 0xFFFF);

    tft.drawLine(153, 123, 157, 123, 0xFFFF);

    tft.drawLine(302, 93, 300, 93, 0xFFFF);

    tft.drawLine(302, 97, 298, 97, 0xFFFF);

    tft.drawLine(302, 105, 300, 105, 0xFFFF);

    tft.drawLine(302, 101, 300, 101, 0xFFFF);

    tft.drawLine(302, 109, 300, 109, 0xFFFF);

    tft.drawLine(302, 113, 300, 113, 0xFFFF);

    tft.drawLine(302, 117, 298, 117, 0xFFFF);

    tft.drawLine(302, 125, 300, 125, 0xFFFF);

    tft.drawLine(302, 121, 300, 121, 0xFFFF);

    tft.drawLine(302, 129, 300, 129, 0xFFFF);

    tft.drawLine(302, 133, 300, 133, 0xFFFF);

    tft.drawLine(302, 137, 298, 137, 0xFFFF);

    tft.drawLine(302, 145, 300, 145, 0xFFFF);

    tft.drawLine(302, 141, 300, 141, 0xFFFF);

    tft.drawLine(302, 149, 300, 149, 0xFFFF);

    tft.drawLine(302, 153, 300, 153, 0xFFFF);

    tft.drawLine(302, 157, 298, 157, 0xFFFF);

    tft.drawLine(302, 165, 300, 165, 0xFFFF);

    tft.drawLine(302, 161, 300, 161, 0xFFFF);

    tft.drawLine(302, 169, 300, 169, 0xFFFF);

    tft.drawLine(302, 173, 300, 173, 0xFFFF);

    tft.drawLine(302, 177, 298, 177, 0xFFFF);

    tft.drawLine(302, 181, 300, 181, 0xFFFF);

    tft.drawLine(302, 185, 300, 185, 0xFFFF);

    tft.drawLine(302, 189, 300, 189, 0xFFFF);

    tft.drawLine(17, 109, 21, 109, 0xFFFF);

    tft.drawLine(17, 123, 21, 123, 0xFFFF);

    tft.drawLine(17, 113, 17, 109, 0xFFFF);

    tft.drawLine(17, 123, 17, 119, 0xFFFF);

    tft.drawLine(153, 109, 157, 109, 0xFFFF);

    tft.drawLine(153, 123, 157, 123, 0xFFFF);

    tft.drawLine(157, 113, 157, 109, 0xFFFF);

    tft.drawLine(157, 123, 157, 119, 0xFFFF);

    tft.drawString("Packet Sniffer", 17, 134);

    tft.drawString("Home", 23, 114);

    tft.drawString("Channel Jammer", 17, 154);

    tft.drawString("State Desync", 17, 174);

    tft.drawRect(169, 77, 124, 117, 0xFFFF);

    tft.drawString("Rolling Jammer", 175, 88);

    tft.drawString("Sweep Jammer", 175, 108);

    tft.drawString("Replay Attack", 175, 128);

    tft.drawString("Protocol Fuzzing", 175, 148);

    tft.drawString("Payload Injection", 175, 168);

}


/*  

WIFI SCREEN DRAW

*/

void drawWifiSubModule(void) {
    tft.drawRect(11, 199, 298, 19, 0xFFFF);

    tft.drawRect(11, 77, 153, 21, 0xFFFF);

    tft.drawRect(11, 103, 153, 91, 0xFFFF);

    tft.setTextColor(0xFFFF);
    tft.setTextSize(1);
    tft.setFreeFont(&Org_01);
    tft.drawString("Promiscuous Mode: " + state, 17, 85);

    tft.drawLine(308, 193, 302, 193, 0xFFFF);

    tft.drawLine(308, 77, 302, 77, 0xFFFF);

    tft.drawLine(302, 193, 302, 77, 0xFFFF);

    tft.drawLine(302, 85, 300, 85, 0xFFFF);

    tft.drawLine(302, 81, 300, 81, 0xFFFF);

    tft.drawLine(302, 89, 300, 89, 0xFFFF);

    tft.drawLine(153, 123, 157, 123, 0xFFFF);

    tft.drawLine(302, 93, 300, 93, 0xFFFF);

    tft.drawLine(302, 97, 298, 97, 0xFFFF);

    tft.drawLine(302, 105, 300, 105, 0xFFFF);

    tft.drawLine(302, 101, 300, 101, 0xFFFF);

    tft.drawLine(302, 109, 300, 109, 0xFFFF);

    tft.drawLine(302, 113, 300, 113, 0xFFFF);

    tft.drawLine(302, 117, 298, 117, 0xFFFF);

    tft.drawLine(302, 125, 300, 125, 0xFFFF);

    tft.drawLine(302, 121, 300, 121, 0xFFFF);

    tft.drawLine(302, 129, 300, 129, 0xFFFF);

    tft.drawLine(302, 133, 300, 133, 0xFFFF);

    tft.drawLine(302, 137, 298, 137, 0xFFFF);

    tft.drawLine(302, 145, 300, 145, 0xFFFF);

    tft.drawLine(302, 141, 300, 141, 0xFFFF);

    tft.drawLine(302, 149, 300, 149, 0xFFFF);

    tft.drawLine(302, 153, 300, 153, 0xFFFF);

    tft.drawLine(302, 157, 298, 157, 0xFFFF);

    tft.drawLine(302, 165, 300, 165, 0xFFFF);

    tft.drawLine(302, 161, 300, 161, 0xFFFF);

    tft.drawLine(302, 169, 300, 169, 0xFFFF);

    tft.drawLine(302, 173, 300, 173, 0xFFFF);

    tft.drawLine(302, 177, 298, 177, 0xFFFF);

    tft.drawLine(302, 181, 300, 181, 0xFFFF);

    tft.drawLine(302, 185, 300, 185, 0xFFFF);

    tft.drawLine(302, 189, 300, 189, 0xFFFF);

    tft.drawLine(17, 109, 21, 109, 0xFFFF);

    tft.drawLine(17, 123, 21, 123, 0xFFFF);

    tft.drawLine(17, 113, 17, 109, 0xFFFF);

    tft.drawLine(17, 123, 17, 119, 0xFFFF);

    tft.drawLine(153, 109, 157, 109, 0xFFFF);

    tft.drawLine(153, 123, 157, 123, 0xFFFF);

    tft.drawLine(157, 113, 157, 109, 0xFFFF);

    tft.drawLine(157, 123, 157, 119, 0xFFFF);

    tft.drawString("WiFi Scanner", 17, 134);

    tft.drawString("Home", 23, 114);

    tft.drawString("Deauth Selected", 17, 154);

    tft.drawString("Deauth Flood", 17, 174);

    tft.drawRect(169, 77, 124, 117, 0xFFFF);

    tft.drawString("PMKID Attack", 175, 88);

    tft.drawString("Handshake Sniffing", 175, 108);

    tft.drawString("Rogue Portal", 175, 128);

    tft.drawString("BSSID Flood", 175, 148);

    tft.drawString("BSSID Clone", 175, 168);

}


/*  

BLUETOOTH SCREEN DRAW

*/

void drawBluetoothSubModule(void) {
    tft.drawRect(11, 199, 298, 19, 0xFFFF);

    tft.drawRect(11, 103, 153, 91, 0xFFFF);

    tft.drawRect(11, 77, 153, 21, 0xFFFF);

    tft.setTextColor(0xFFFF);
    tft.setTextSize(1);
    tft.setFreeFont(&Org_01);
    tft.drawString("Bluetooth Mode: " + state, 17, 85);

    tft.drawLine(308, 77, 302, 77, 0xFFFF);

    tft.drawLine(308, 193, 302, 193, 0xFFFF);

    tft.drawLine(302, 193, 302, 77, 0xFFFF);

    tft.drawLine(302, 81, 300, 81, 0xFFFF);

    tft.drawLine(302, 85, 300, 85, 0xFFFF);

    tft.drawLine(302, 89, 300, 89, 0xFFFF);

    tft.drawLine(302, 93, 300, 93, 0xFFFF);

    tft.drawLine(153, 123, 157, 123, 0xFFFF);

    tft.drawLine(302, 97, 298, 97, 0xFFFF);

    tft.drawLine(302, 105, 300, 105, 0xFFFF);

    tft.drawLine(302, 101, 300, 101, 0xFFFF);

    tft.drawLine(302, 109, 300, 109, 0xFFFF);

    tft.drawLine(302, 113, 300, 113, 0xFFFF);

    tft.drawLine(302, 117, 298, 117, 0xFFFF);

    tft.drawLine(302, 125, 300, 125, 0xFFFF);

    tft.drawLine(302, 121, 300, 121, 0xFFFF);

    tft.drawLine(302, 129, 300, 129, 0xFFFF);

    tft.drawLine(302, 133, 300, 133, 0xFFFF);

    tft.drawLine(302, 137, 298, 137, 0xFFFF);

    tft.drawLine(302, 145, 300, 145, 0xFFFF);

    tft.drawLine(302, 141, 300, 141, 0xFFFF);

    tft.drawLine(302, 149, 300, 149, 0xFFFF);

    tft.drawLine(302, 153, 300, 153, 0xFFFF);

    tft.drawLine(302, 157, 298, 157, 0xFFFF);

    tft.drawLine(302, 165, 300, 165, 0xFFFF);

    tft.drawLine(302, 161, 300, 161, 0xFFFF);

    tft.drawLine(302, 169, 300, 169, 0xFFFF);

    tft.drawLine(302, 173, 300, 173, 0xFFFF);

    tft.drawLine(302, 177, 298, 177, 0xFFFF);

    tft.drawLine(302, 181, 300, 181, 0xFFFF);

    tft.drawLine(302, 185, 300, 185, 0xFFFF);

    tft.drawLine(302, 189, 300, 189, 0xFFFF);

    tft.drawLine(17, 109, 21, 109, 0xFFFF);

    tft.drawLine(17, 113, 17, 109, 0xFFFF);

    tft.drawLine(17, 123, 21, 123, 0xFFFF);

    tft.drawLine(17, 123, 17, 119, 0xFFFF);

    tft.drawLine(153, 109, 157, 109, 0xFFFF);

    tft.drawLine(153, 123, 157, 123, 0xFFFF);

    tft.drawLine(157, 113, 157, 109, 0xFFFF);

    tft.drawLine(157, 123, 157, 119, 0xFFFF);

    tft.drawString("Home", 23, 114);

    tft.drawString("Bluetooth Scanner", 17, 134);

    tft.drawString("Beacon Spamming", 17, 154);

    tft.drawString("Device Impersonation", 17, 174);

    tft.drawRect(169, 77, 124, 117, 0xFFFF);

    tft.drawString("Denial Of Service", 175, 88);

    tft.drawString("Popup Trigger", 175, 108);

    tft.drawString("Profile Poisoning", 175, 128);

    tft.drawString("HID Injection", 175, 148);

    tft.drawString("Firmware Bomb", 175, 168);

}