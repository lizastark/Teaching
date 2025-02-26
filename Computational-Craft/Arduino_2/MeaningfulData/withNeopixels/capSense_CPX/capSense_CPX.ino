/*

 Capacitive Sensing with Circuit Playground Express
 Comp Craft Spring 2025
 
 This sketch reads touch data coming in on pin 9 (i.e. A2). If the value is above 600 (i.e. if it is being touched) the neopixel 
 turns red. If it is below or not being touched, the LED turns blue. 
 
 */

#include <Adafruit_CircuitPlayground.h>

void setup() {

  CircuitPlayground.begin(); //Required
  CircuitPlayground.clearPixels();
  CircuitPlayground.strip.setBrightness(200); //255 is the max
  Serial.begin(9600);

}

void loop() {
  int capValue = CircuitPlayground.readCap(9);
  if(capValue > 600){
    CircuitPlayground.strip.setPixelColor(0, 255, 0, 0); 
  } else {
    CircuitPlayground.strip.setPixelColor(0, 0, 0, 255); 
  }

  CircuitPlayground.strip.show();

  Serial.print(" A2: ");
  Serial.println(capValue);

  delay(10);
}