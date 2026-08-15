# 01 Blink

The first ESP32 upload: flash the board's onboard LED.

## Parts

- ESP32 development board
- USB data cable

## Upload

Open `01_Blink.ino` in Arduino IDE, select **ESP32 Dev Module** (or your exact board), then upload.

Most ESP32 development boards use GPIO 2 for the onboard LED. If yours does not blink, change `LED_BUILTIN` to the pin shown in your board documentation.
