// CarloHustle TV - ESP32 Daily Project 01
// Built-in ESP32 Arduino core only.

#ifndef LED_BUILTIN
#define LED_BUILTIN 2
#endif

const unsigned long blinkIntervalMs = 500;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(blinkIntervalMs);
  digitalWrite(LED_BUILTIN, LOW);
  delay(blinkIntervalMs);
}
