// CarloHustle TV - ESP32 Daily Project 07
// DHT22 thermostat relay controller with hysteresis and a sensor-failure safe state.

#include <Adafruit_Sensor.h>
#include <DHT.h>

const int dhtPin = 4;
const int relayPin = 26;
const int dhtType = DHT22;
const bool relayActiveLow = true;
const bool coolingMode = true;
const float setPointC = 28.0;
const float hysteresisC = 1.0;
const unsigned long readingIntervalMs = 2500;

DHT dht(dhtPin, dhtType);
bool relayOn = false;
unsigned long lastReadingAt = 0;

void setRelay(bool shouldBeOn) {
  relayOn = shouldBeOn;
  const bool pinLevel = relayActiveLow ? !relayOn : relayOn;
  digitalWrite(relayPin, pinLevel ? HIGH : LOW);
}

void controlTemperature(float temperatureC) {
  const float lowerThreshold = setPointC - hysteresisC / 2.0;
  const float upperThreshold = setPointC + hysteresisC / 2.0;

  if (coolingMode) {
    if (temperatureC >= upperThreshold) {
      setRelay(true);
    } else if (temperatureC <= lowerThreshold) {
      setRelay(false);
    }
  } else {
    if (temperatureC <= lowerThreshold) {
      setRelay(true);
    } else if (temperatureC >= upperThreshold) {
      setRelay(false);
    }
  }
}

void readAndControl() {
  const float humidity = dht.readHumidity();
  const float temperatureC = dht.readTemperature();

  if (isnan(humidity) || isnan(temperatureC)) {
    setRelay(false);
    Serial.println("DHT22 read failed. Relay forced OFF.");
    return;
  }

  controlTemperature(temperatureC);
  Serial.printf(
    "Temperature: %.1f C | Humidity: %.1f %% | Set point: %.1f C | Relay: %s\n",
    temperatureC,
    humidity,
    setPointC,
    relayOn ? "ON" : "OFF"
  );
}

void setup() {
  Serial.begin(115200);

  // Set the safe relay level before enabling the output.
  setRelay(false);
  pinMode(relayPin, OUTPUT);
  setRelay(false);

  dht.begin();
  Serial.printf(
    "Temperature relay controller started in %s mode.\n",
    coolingMode ? "cooling" : "heating"
  );
}

void loop() {
  const unsigned long now = millis();
  if (now - lastReadingAt >= readingIntervalMs) {
    lastReadingAt = now;
    readAndControl();
  }
}
