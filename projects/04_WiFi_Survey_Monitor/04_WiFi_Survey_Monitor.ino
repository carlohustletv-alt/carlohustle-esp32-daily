// CarloHustle TV - ESP32 Daily Project 04
// Read-only survey of nearby Wi-Fi broadcasts. It never connects to a network.

#include <WiFi.h>

const unsigned long surveyIntervalMs = 30000;

const char *authModeName(wifi_auth_mode_t authMode) {
  switch (authMode) {
    case WIFI_AUTH_OPEN:
      return "Open";
    case WIFI_AUTH_WEP:
      return "WEP";
    case WIFI_AUTH_WPA_PSK:
      return "WPA";
    case WIFI_AUTH_WPA2_PSK:
      return "WPA2";
    case WIFI_AUTH_WPA_WPA2_PSK:
      return "WPA/WPA2";
    case WIFI_AUTH_WPA3_PSK:
      return "WPA3";
    case WIFI_AUTH_WPA2_WPA3_PSK:
      return "WPA2/WPA3";
    default:
      return "Other";
  }
}

void printSurvey() {
  Serial.println("\n--- Wi-Fi survey ---");
  const int networkCount = WiFi.scanNetworks(false, false);

  if (networkCount == 0) {
    Serial.println("No Wi-Fi broadcasts found.");
  } else {
    Serial.printf("%d broadcast network(s) found\n", networkCount);

    for (int i = 0; i < networkCount; ++i) {
      Serial.printf(
        "%d | SSID: %s | RSSI: %d dBm | Channel: %d | Security: %s | BSSID: %s\n",
        i + 1,
        WiFi.SSID(i).c_str(),
        WiFi.RSSI(i),
        WiFi.channel(i),
        authModeName(WiFi.encryptionType(i)),
        WiFi.BSSIDstr(i).c_str()
      );
    }
  }

  WiFi.scanDelete();
  Serial.printf("Next survey in %lu seconds.\n", surveyIntervalMs / 1000);
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  Serial.println("ESP32 read-only Wi-Fi survey monitor started.");
}

void loop() {
  printSurvey();
  delay(surveyIntervalMs);
}
