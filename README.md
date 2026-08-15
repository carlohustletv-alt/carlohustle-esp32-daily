# CarloHustle ESP32 Daily

ESP32 Arduino projects made for the CarloHustle TV channel. Each project is small enough for a daily video, uses clear wiring, and is ready to open in Arduino IDE.

## Projects

| Project | What it demonstrates | Parts needed |
| --- | --- | --- |
| [01 Blink](projects/01_Blink) | Flash the ESP32 onboard LED | ESP32 development board, USB cable |
| [02 Wi-Fi Scanner](projects/02_WiFi_Scanner) | Find nearby Wi-Fi networks and signal strengths | ESP32 development board, USB cable |
| [03 Web LED Control](projects/03_Web_LED_Control) | Control an LED from a phone or computer browser | ESP32 development board, USB cable, LED, 220-330 ohm resistor |

## Project Ideas For The Channel

- Wi-Fi weather station with an OLED display
- Bluetooth phone-controlled robot car
- RFID door lock
- Motion-sensor security alarm
- Smart relay for lights or appliances
- Soil-moisture plant monitor
- Ultrasonic parking sensor
- ESP32-CAM security camera
- LED music visualizer
- GPS tracker

## Arduino IDE Setup

1. Install Arduino IDE 2.x from [arduino.cc](https://www.arduino.cc/en/software).
2. Open **File > Preferences**.
3. Add this URL to **Additional Boards Manager URLs**:

   ```text
   https://espressif.github.io/arduino-esp32/package_esp32_index.json
   ```

4. Open **Tools > Board > Boards Manager**, search for `esp32`, and install **esp32 by Espressif Systems**.
5. Connect the board with a data-capable USB cable.
6. Under **Tools**, select your board. For most generic boards, choose **ESP32 Dev Module**.
7. Select the correct **Port**, open a project `.ino` file, and click **Upload**.

These starter projects only use libraries included with the Espressif ESP32 board package. No Library Manager downloads are needed.

## Serial Monitor

Use **Tools > Serial Monitor** with the baud rate specified in each sketch. Most boards show a boot message when the **EN** or **Reset** button is pressed.

## Safety

Power projects from USB or a suitable regulated supply. Do not connect ESP32 GPIO pins directly to mains voltage, car electrical wiring, motors, or relays without correctly rated driver and protection circuits.

## License

MIT License. Use, adapt, and share these projects with credit to CarloHustle TV.
