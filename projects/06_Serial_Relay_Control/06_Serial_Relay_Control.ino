// CarloHustle TV - ESP32 Daily Project 06
// Control a relay module from Arduino IDE Serial Monitor.

const int relayPin = 26;
const bool relayActiveLow = true;
bool relayOn = false;

void writeRelay() {
  const bool pinLevel = relayActiveLow ? !relayOn : relayOn;
  digitalWrite(relayPin, pinLevel ? HIGH : LOW);
}

void printStatus() {
  Serial.printf("Relay is %s\n", relayOn ? "ON" : "OFF");
}

void printHelp() {
  Serial.println("Commands: ON, OFF, STATUS, HELP");
}

void setup() {
  Serial.begin(115200);

  // Keep the relay off as soon as the GPIO becomes an output.
  relayOn = false;
  writeRelay();
  pinMode(relayPin, OUTPUT);
  writeRelay();

  Serial.println("ESP32 relay control ready.");
  printHelp();
  printStatus();
}

void loop() {
  if (!Serial.available()) {
    return;
  }

  String command = Serial.readStringUntil('\n');
  command.trim();
  command.toUpperCase();

  if (command == "ON") {
    relayOn = true;
    writeRelay();
    printStatus();
  } else if (command == "OFF") {
    relayOn = false;
    writeRelay();
    printStatus();
  } else if (command == "STATUS") {
    printStatus();
  } else if (command == "HELP") {
    printHelp();
  } else if (command.length() > 0) {
    Serial.println("Unknown command. Type HELP.");
  }
}
