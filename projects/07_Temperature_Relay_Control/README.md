# 07 Temperature Relay Control

Use a DHT22 temperature and humidity sensor to switch an ESP32 relay module. The default configuration runs a cooling load: it turns the relay on at `28.5 C` and off at `27.5 C`. The 1 C gap is hysteresis, which prevents rapid relay switching near the target temperature.

## Parts

- ESP32 development board
- DHT22 sensor or DHT22 breakout module
- Opto-isolated, 3.3 V-compatible relay module
- Suitable relay power supply
- USB data cable and jumper wires

## Libraries

Install these from **Tools > Manage Libraries** in Arduino IDE:

- **DHT sensor library by Adafruit**
- **Adafruit Unified Sensor by Adafruit**

## Wiring

| ESP32 | DHT22 | Relay module |
| --- | --- | --- |
| 3V3 | VCC | - |
| GND | GND | GND |
| GPIO 4 | DATA | - |
| GPIO 26 | - | IN |
| Relay supply positive | - | VCC or JD-VCC, as specified by the module |

If using a bare DHT22 rather than a breakout module, add a 4.7k-10k ohm pull-up resistor between its VCC and DATA pins.

## Configure

Edit these values near the top of `07_Temperature_Relay_Control.ino`:

| Setting | Default | Purpose |
| --- | --- | --- |
| `setPointC` | `28.0` | Target temperature |
| `hysteresisC` | `1.0` | Temperature range between switching on and off |
| `coolingMode` | `true` | `true` for a fan/cooling load; `false` for a heating load |
| `relayActiveLow` | `true` | Set `false` for an active-high relay module |

Open Serial Monitor at `115200` baud to see temperature, humidity, and relay state. If the DHT22 does not return a valid reading, the sketch forces the relay OFF.

## Electrical Safety

Test first with a low-voltage load such as a small DC fan. Do not drive a relay coil directly from an ESP32 GPIO. Mains-powered heaters, air conditioners, and other high-energy loads require correctly rated relays/contactors, enclosures, fuses, thermal cutoffs, wiring, isolation, and qualified electrical work. This project is not a safety controller and must not be the only protection against overheating or freezing.
