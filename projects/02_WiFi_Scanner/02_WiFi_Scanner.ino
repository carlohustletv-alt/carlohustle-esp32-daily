// CarloHustle TV - ESP32 Daily Project 02
// Uses WiFi.h included with the Espressif ESP32 board package.

#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  delay(1000);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  Serial.println("\nScanning for Wi-Fi networks...");
  const int networkCount = WiFi.scanNetworks();

  if (networkCount == 0) {
    Serial.println("No networks found.");
  } else {
    Serial.printf("%d network(s) found:\n", networkCount);
    for (int i = 0; i < networkCount; ++i) {
      const char *security = WiFi.encryptionType(i) == WIFI_AUTH_OPEN ? "open" : "secured";
      Serial.printf("%d. %s | %d dBm | %s\n", i + 1, WiFi.SSID(i).c_str(), WiFi.RSSI(i), security);
    }
  }

  WiFi.scanDelete();
}

void loop() {
  delay(1000);
}
