/*

 Fading with millis()
 Neopixels with Circuit Playground Express
 Comp Craft Spring 2025
 
 This sketch uses millis() instead of delay() to fade a neopixel. We check
if a certain interval of time (30 ms) has passed before updating the 
brightness. This way we don't need to stop the program using delay() and 
can run other code in the background.
 
 */

#include <Adafruit_CircuitPlayground.h>

int brightness = 0;
int fadeAmount = 5;
unsigned long previousMillis = 0;
const long interval = 30;

void setup() {
  CircuitPlayground.begin();  //Required
  CircuitPlayground.clearPixels();
  CircuitPlayground.setBrightness(200);  //255 is the max
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    brightness += fadeAmount;
    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }

    //Uncomment different options below to try them out. 
    //Play with fade amount and interval variables as well as color!

    //Fading one neopixel
    CircuitPlayground.setPixelColor(0, brightness, 0, 0);

    // //Fading more than one neopixel
    // for (int i = 0; i < 10; ++i) {
    //   CircuitPlayground.setPixelColor(i, brightness, 0, 0);
    // }

    // // Fade one neopixel that is an RGB color
    // int r = map(brightness, 0, 255, 0, 255);  // Max Red
    // int g = map(brightness, 0, 255, 0, 20);   // Lower Green
    // int b = map(brightness, 0, 255, 0, 147);  // Medium Blue
    // CircuitPlayground.setPixelColor(0, r, g, b);
  }
}
