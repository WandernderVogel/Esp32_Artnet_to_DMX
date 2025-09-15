# Esp32_Artnet_to_DMX
Artnet to DMX converter based on the ESP32 in combination with an rs485 module for outputting one universe

---

# Usage
Please enter your Wifi Credentials and define the max universes as either 1 or 2 that can be send out
The rs485 modle should be connected as followed(can also be viewn in image):
RO rs485-1 -> not connected
DE rs485-1 -> 3.3V(ESP32)
RE rs485-1 -> 3.3V(ESP32)
DI rs485-1 -> D17/TX2(ESP32)

VCC rs485-1 -> 3.3V(ESP32)
A rs485-1 -> Pin 1(dmx connector 1)
B rs485-1 -> Pin 2(dmx connector 1)
GND rs485-1 -> GND(ESP32)

GND(ESP32) -> GND(dmx connector 1)

RO rs485-2 -> not connected
DE rs485-2 -> 3.3V(ESP32)
RE rs485-2 -> 3.3V(ESP32)
DI rs485-2 -> D19(ESP32)

VCC rs485-2 -> 3.3V(ESP32)
A rs485-2 -> Pin 1(dmx connector 2)
B rs485-2 -> Pin 2(dmx connector 2)
GND rs485-2 -> GND(ESP32)

GND(ESP32) -> GND(dmx connector 2)

<img width="675" height="788" alt="image" src="https://github.com/user-attachments/assets/fee33d33-9264-421f-8fb0-0002d6981fb8" />

---
# Future Features

- [ ] Ethernet Addition
- [ ] Config Page on first startup for easy starting
- [ ] PCB Design for downloading
- [ ] enclosure design for 3d printing

---

Art-Net™ Designed by and Copyright Artistic Licence Engineering Ltd

This code is published under [CC BY-SA](https://creativecommons.org/licenses/by-sa/4.0/)
