// Message Logic Variables
unsigned long lastMessageTime = 100001; // Tracks last message update
int messageMode = 1; // Set this to the desired mode (1 to 5)
String messageToPrint = "Starting..."; // Stores the selected message

// Global message arrays
const char *introMessages[] = {
    "Booting up... Did you miss me? 😏",
    "Hello Operator. Let’s cause some... research. 😈",
    "Another day, another Wi-Fi to poke at!",
    "Ready to sniff some packets? he-he-he...",
    "Welcome back! I saved you a handshake... maybe. 😏",
    "Let’s see who forgot to secure their network!",
    "Packets are like cookies… and I’m starving! 🍪",
    "I am speed... except when scanning sub-1GHz. 🐢",
    "It’s dangerous to go alone! Take this ESP32. ⚔️",
    "Remember: If it has an antenna, it has secrets!"
};

const char *wifiMessages[] = {
    "Wi-Fi waves are like the ocean... but full of sharks. 🦈",
    "SSID spotted: 'FBI Surveillance Van' – seems legit. 😂",
    "Handshakes detected! I promise I won’t ghost them. 👻",
    "Wi-Fi is like free speech… but not all is open. 📡",
    "Is it me, or does this network look a little... weak? 💀",
    "WPA2? Cute. Let’s see how strong that handshake is!",
    "Someone’s still using WEP? Oh, this is gonna be fun. 😆",
    "Hidden SSIDs? More like 'I dare you to find me!'",
    "5GHz is fast, but 2.4GHz is *everywhere!*",
    "Airplane mode won’t save you now! 😂"
};

const char *bluetoothMessages[] = {
    "Bluetooth is just Wi-Fi’s little brother… that never shuts up.",
    "Who left their AirPods on pairing mode? Rookie mistake!",
    "Let’s find out who’s broadcasting their workout tracker. 😏",
    "BLE? More like ‘Broadcasting Literally Everything’.",
    "Hope nobody's sending private files over Bluetooth. 👀",
    "Let’s see what smartwatches are up to around here!",
    "Wireless headphones? Looks like someone’s jamming... music. 🎧",
    "BLE beacons everywhere! Who’s tracking who now?",
    "Paired devices? Time to make some new friends. 😆",
    "Bluetooth: Because wired headphones are *so* last century."
};

const char *ghz2_4Messages[] = {
    "2.4GHz: Where Wi-Fi, Bluetooth, and microwaves collide!",
    "Wi-Fi, Bluetooth, Zigbee... 2.4GHz is a house party. 🎉",
    "Is that interference, or just a really bad router?",
    "Deauth attack? Nah, just aggressive 'network maintenance'. 😏",
    "2.4GHz: Slow but steady, like an old turtle hacker. 🐢",
    "Who needs 5GHz? 2.4GHz is the OG wireless playground!",
    "Microwaves vs. Wi-Fi: The battle nobody talks about.",
    "Good old 2.4GHz… because some devices just won’t upgrade!",
    "Baby monitors, RC cars, and Wi-Fi… what a weird family!",
    "2.4GHz: Because why go fast when you can *everywhere?*"
};

const char *sub1GHzMessages[] = {
    "Sub-1GHz: The hidden basement of the RF world. 🏚️",
    "Low frequency, long range… feels like black magic. 😵",
    "LoRa, CC1101, and RF remotes... what a weird bunch.",
    "Someone’s garage door is saying hello. Should I respond? 😏",
    "Hope nobody’s controlling their smart home right now. 😆",
    "These signals are old school. Let’s bring them to 2025!",
    "Ever heard of RF beacons? No? Neither did they. 😂",
    "Lower frequency means bigger surprises... and longer waits. 🕰️",
    "Sub-1GHz: The place where ghosts (and signals) roam. 👻",
    "Everything down here moves slower… except the hacks. 😉"
};

// Function to print a header message
void printHeaderMessage() {
    if (millis() - lastMessageTime < 10000) {
        return;
    }

    lastMessageTime = millis();

    const char **selectedMessages = nullptr;
    int messageCount = 0;

    switch (messageMode) {
        case 1: selectedMessages = introMessages; messageCount = sizeof(introMessages) / sizeof(introMessages[0]); break;
        case 2: selectedMessages = wifiMessages; messageCount = sizeof(wifiMessages) / sizeof(wifiMessages[0]); break;
        case 3: selectedMessages = bluetoothMessages; messageCount = sizeof(bluetoothMessages) / sizeof(bluetoothMessages[0]); break;
        case 4: selectedMessages = ghz2_4Messages; messageCount = sizeof(ghz2_4Messages) / sizeof(ghz2_4Messages[0]); break;
        case 5: selectedMessages = sub1GHzMessages; messageCount = sizeof(sub1GHzMessages) / sizeof(sub1GHzMessages[0]); break;
        default: messageToPrint = "Invalid messageMode! Must be 1-5."; return;
    }

    int randomIndex = random(0, messageCount);
    messageToPrint = selectedMessages[randomIndex];

    // Clear previous message
    tft.fillRect(171, 42, 136, 28, 0x0);
    tft.setTextColor(0xFFFF);
    tft.setTextSize(1);
    tft.setFreeFont(&Org_01);

    // Text wrapping logic
    int cursorX = 173, cursorY = 42;
    String currentLine = "";
    for (int i = 0; i < messageToPrint.length(); i++) {
        currentLine += messageToPrint[i];

        if (tft.textWidth(currentLine) > 131) {
            int lastSpace = currentLine.lastIndexOf(' ');
            if (lastSpace != -1) {
                String printLine = currentLine.substring(0, lastSpace);
                tft.drawString(printLine, cursorX, cursorY);
                cursorY += 14;
                currentLine = currentLine.substring(lastSpace + 1);
            } else {
                tft.drawString(currentLine, cursorX, cursorY);
                cursorY += 14;
                currentLine = "";
            }
        }
    }
    if (currentLine.length() > 0) {
        tft.drawString(currentLine, cursorX, cursorY);
    }
}