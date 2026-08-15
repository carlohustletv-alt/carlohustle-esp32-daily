# 04 Wi-Fi Survey Monitor

Repeatedly display nearby Wi-Fi networks' publicly broadcast metadata in Serial Monitor: network name, signal strength, channel, advertised security type, and BSSID.

## Parts

- ESP32 development board
- USB data cable

## Use

1. Upload `04_WiFi_Survey_Monitor.ino`.
2. Open Serial Monitor at `115200` baud.
3. The ESP32 runs a new survey every 30 seconds. Press **Reset** to run one immediately.

## What This Project Does Not Do

This project does not join networks, copy or impersonate Wi-Fi access points, collect passwords, decrypt traffic, capture packets, or access network data. Use it only where you are authorized to survey wireless broadcasts.
