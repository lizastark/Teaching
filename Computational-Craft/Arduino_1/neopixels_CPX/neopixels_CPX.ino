/*

 Neopixels with Circuit Playground Express
 Comp Craft Spring 2025
 
 This sketch uses the CPX library to turn on a single LED and multiple LEDs using a for loop.
 
 */

#include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin(); //Required
  CircuitPlayground.clearPixels();
  CircuitPlayground.strip.setBrightness(200); //255 is the max
}

void loop() {

  //one neopixel
  CircuitPlayground.strip.setPixelColor(6, 0, 0, 255);

  //multiple neopixels - first 4
  for (int i = 0; i < 4; ++i) {
    CircuitPlayground.strip.setPixelColor(i, 255, 0, 0);
  }

  //You always have to show!
  CircuitPlayground.strip.show();
}