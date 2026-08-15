# 05 Bluetooth Serial LED

Control an ESP32 LED from a phone using a Bluetooth terminal app. This project uses Bluetooth Classic, which is supported by the original ESP32 but not ESP32-C3, ESP32-C6, ESP32-S2, or ESP32-S3 boards.

## Parts And Wiring

- Original ESP32 development board
- USB data cable
- Optional LED, 220-330 ohm resistor, breadboard, and jumper wires

The onboard LED is used when it is wired to GPIO 2. For an external LED, wire GPIO 2 to the resistor, the resistor to the LED long leg (anode), and the LED short leg (cathode) to GND.

## Use

1. Upload `05_Bluetooth_Serial_LED.ino` to an original ESP32 board.
2. Install a Bluetooth terminal app on your phone.
3. Pair with `CarloHustle-ESP32`.
4. Connect in the terminal app and send one of these commands:

| Command | Result |
| --- | --- |
| `1` | Turn the LED on |
| `0` | Turn the LED off |
| `S` | Show the current LED state |

The sketch also prints the state to Arduino IDE Serial Monitor at `115200` baud.

## Note

The example does not require a pairing PIN. Use it in a trusted environment only. Add Bluetooth authentication before controlling a relay, lock, motor, or any other device with a safety impact.
