# Esp32_Artnet_to_DMX
Artnet to DMX converter based on the ESP32 in combination with an rs485 module for outputting one universe

---

# Usage
Please enter your Wifi Credentials and define the max universes as either 1 or 2 that can be send out
The rs485 modle should be connected as followed(can also be viewn in image):
RO -> not connected
DE -> 3.3V(ESP32)
RE -> 3.3V(ESP32)
DI -> D17(ESP32)

VCC -> 3.3V(ESP32)
A -> Pin 1(dmx connector)
B -> Pin 2(dmx connector)
GND -> GND(ESP32)

GND(ESP32) -> GND(dmx connector)

<img width="671" height="808" alt="image" src="https://github.com/user-attachments/assets/1dc9a10a-da11-4915-a7fe-1cf43311ff34" />
