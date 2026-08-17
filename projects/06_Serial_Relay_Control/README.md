# 06 Serial Relay Control

Switch a relay module from Arduino IDE Serial Monitor. The relay starts in the OFF state on every boot.

## Parts And Wiring

- ESP32 development board
- Opto-isolated relay module with a 3.3 V-compatible input
- Suitable relay power supply
- Jumper wires
- USB data cable

Connect the ESP32 as follows:

| ESP32 | Relay module |
| --- | --- |
| GPIO 26 | IN |
| GND | GND |
| Relay power supply positive | VCC or JD-VCC, as specified by the module |

Many relay modules use a 5 V supply and an active-low input. This sketch is set for active-low operation with `relayActiveLow = true`. If your module turns on when the sketch says OFF, set it to `false`.

## Use

1. Upload `06_Serial_Relay_Control.ino`.
2. Open Serial Monitor at `115200` baud.
3. Set the line ending to **Newline**.
4. Send one of these commands:

| Command | Result |
| --- | --- |
| `ON` | Turn relay on |
| `OFF` | Turn relay off |
| `STATUS` | Print current relay state |
| `HELP` | Print commands |

## Electrical Safety

Do not connect a bare relay coil directly to an ESP32 GPIO pin. Use a correctly rated relay module or driver circuit. This project is intended for isolated, low-voltage demonstrations. Mains electricity, high-current batteries, vehicle wiring, and permanently installed loads require properly rated enclosures, fuses, wiring, isolation, and qualified electrical work. Do not control safety-critical equipment with this example.
