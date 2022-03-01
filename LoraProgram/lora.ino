#include <MKRWAN.h>

LoRaModem modem;

String appEui = "";
String appKey = "";
String devAddr;
String nwkSKey;
String appSKey;


void setup() {

    Serial.begin(115200);
    while (!Serial);
    Serial.println("Welcome to MKR WAN 1300/1310 first configuration sketch");
    
    if (!modem.begin(EU868)) {
        Serial.println("Failed to start module");
    }

    Serial.print("Your module version is: ");
    Serial.println(modem.version());

    if (modem.version() != ARDUINO_FW_VERSION) {
        Serial.println("Please make sure that the latest modem firmware is installed.");
        Serial.println("To update the firmware upload the 'MKRWANFWUpdate_standalone.ino' sketch.");
    }

    int connect;
    connect = modem.joinOTAA(appEui, appKey);

    if(!connect) {
        Serial.println("Connection Failed");
    }

    delay(5000);

    int err;
    modem.setPort(3);
    modem.beginPacket();
    modem.print("HeLoRA world!");
    err = modem.endPacket(true);
    if (err > 0) {
        Serial.println("Message sent correctly!");
    } else {
        Serial.println("Error sending message :(");
    }
}

void loop() {
    while (modem.available()) {
    Serial.write(modem.read());
  }
  modem.poll();
}