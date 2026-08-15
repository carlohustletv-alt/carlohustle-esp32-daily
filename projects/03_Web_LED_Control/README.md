# 03 Web LED Control

Control an ESP32-connected LED from a browser on the same Wi-Fi network.

## Parts And Wiring

- ESP32 development board
- USB data cable
- LED
- 220-330 ohm resistor
- Breadboard and jumper wires

Wire GPIO 2 to the resistor, resistor to the LED's long leg (anode), and LED's short leg (cathode) to GND. Some ESP32 boards already have an LED on GPIO 2, so the external LED is optional.

## Use

1. Set `ssid` and `password` in `03_Web_LED_Control.ino`.
2. Upload the sketch.
3. Open Serial Monitor at `115200` baud.
4. Copy the displayed `http://` address into a browser connected to the same Wi-Fi network.

Do not upload real Wi-Fi credentials to a public GitHub repository. Keep your local credentials uncommitted.
