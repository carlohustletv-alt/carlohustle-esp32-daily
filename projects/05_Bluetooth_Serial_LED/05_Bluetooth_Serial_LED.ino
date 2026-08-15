// CarloHustle TV - ESP32 Daily Project 05
// BluetoothSerial is included with the ESP32 board package on original ESP32 boards.

#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled. Select an original ESP32 board with Bluetooth Classic support.
#endif

#ifndef LED_BUILTIN
#define LED_BUILTIN 2
#endif

BluetoothSerial SerialBT;
bool ledOn = false;

void reportState() {
  SerialBT.printf("LED is %s\n", ledOn ? "ON" : "OFF");
  Serial.printf("LED is %s\n", ledOn ? "ON" : "OFF");
}

void setLed(bool isOn) {
  ledOn = isOn;
  digitalWrite(LED_BUILTIN, ledOn ? HIGH : LOW);
  reportState();
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  SerialBT.begin("CarloHustle-ESP32");
  Serial.println("Bluetooth ready. Pair with CarloHustle-ESP32.");
  setLed(false);
}

void loop() {
  while (SerialBT.available()) {
    const char command = SerialBT.read();

    if (command == '1') {
      setLed(true);
    } else if (command == '0') {
      setLed(false);
    } else if (command == 'S' || command == 's') {
      reportState();
    }
  }
}
