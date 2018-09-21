//A arudino sketch that uses Blynk to control a wifi-enabled LED neopixel stirp
//THe strip is powered and web enabled by a Node MCU ESP8266 dev board.
//Blynk libraries must be manually installed.


#include <Adafruit_NeoPixel.h>
#include <SPI.h>
#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>

#define PIN D2 //data pin on the NodeMCU board
#define NUMPIXELS 30 //number of pixels in LED strip
#define BLYNK_PRINT Serial
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
Serial.begin(9600);
Blynk.begin("your auth code here", "your network SSID ", "your network password");
pixels.begin();
}
BLYNK_WRITE(V2) //virtual pin - a Blynk convention to manage writing to the Node data pin
{

int R = param[0].asInt();
int G = param[1].asInt();
int B = param[2].asInt();
Serial.println(R);
Serial.println(G);
Serial.println(B);
for(int i=0;i<NUMPIXELS;i++){

pixels.setPixelColor(i, pixels.Color(R,G,B));

pixels.show();
}
}

void loop()
{
Blynk.run();
}

