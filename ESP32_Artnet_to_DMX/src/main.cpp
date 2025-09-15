#include <Arduino.h>
#include <ArtnetnodeWifi.h>
#include <easydmx.h>

// works for now, needs to be more efficent because lag is just too much

ArtnetnodeWifi artnet;
WiFiUDP udp;

const char *ssid = "Your_WiFi_SSID";
const char *pwd = "Your_WiFi_PWD";

const int startingUniverse = 0;
const int chan_count = 512;

const int freq = 5000;
const int res = 8;

IPAddress local_ip(192, 168, 4, 2); // ip addr of ESP in network(if network allows ip setting)
IPAddress gateway(192, 168, 4, 1);  // ip of router
IPAddress subnet(255, 255, 255, 0); // subnet

const int tx_pin = 16;
const int rx_pin = 17; // not used, can be used if code is altered and device should be used for DMX-> Artnet

uint8_t dmx_data[512] = {0};
EasyDMX dmx;

void onDmxFrame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t *data);
void initWiFi();

void setup()
{
  Serial.begin(115200);
  Serial.println("Start");

  initWiFi();

  artnet.setShortName("ESP32_DMX_Converter");
  artnet.setLongName("ESP Artnet Device");
  artnet.setStartingUniverse(startingUniverse);
  artnet.setArtDmxCallback(onDmxFrame);
  artnet.begin();

  dmx.begin(DMXMode::Transmit, DMXPin::NoRx, DMXPin::Serial2Tx);
}

void loop()
{
  artnet.read();
}

void onDmxFrame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t *data)
{
  if (universe == startingUniverse)
  {

    // Serial.print("DMX: Univ: ");
    // Serial.print(universe, DEC);
    // Serial.print(", Seq: ");
    // Serial.print(sequence, DEC);
    // Serial.print(", Data (");
    // Serial.print(length, DEC);
    // Serial.print("): ");

    if (length > chan_count)
    {
      length = chan_count;
    }

    // send out the buffer
    // give every universe its own place in one long array
    for (int i = 0; i < length; i++)
    {
      // do stuff for all chanels

      // print hex data to Serial console(makes the program slower)
      // Serial.print(data[i], HEX);
      // Serial.print(" ");
      if (dmx_data[i] != data[i])
      {
        dmx.setChannel(i + 1, data[i]);
      }
      dmx_data[i] = data[i];
    }
    // Serial.println()
    // do fancy stuff for single chanels
  }
}

void initWiFi()
{
  WiFi.mode(WIFI_STA);                    // wifi in station mode
  WiFi.config(local_ip, gateway, subnet); // config with ip addr
  WiFi.setSleep(false);                   // WiFi doesn't disconnect automatically as power saving measure
  WiFi.begin(ssid, pwd);
  Serial.println("Connecting to Wifi");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    // Serial.print(".");
  }
  Serial.println("Connected");
  Serial.print("IP ");
  Serial.println(WiFi.localIP());
  Serial.print("Brodcast IP ");
  Serial.println(WiFi.broadcastIP());
}