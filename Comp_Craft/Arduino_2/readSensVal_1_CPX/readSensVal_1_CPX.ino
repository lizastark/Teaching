/*

 Reading Sensor Values with Circuit Playground Express
 Comp Craft Spring 2025
 
 This sketch reads the data coming in from the sensor, prints it to the serial
 monitor, and displays it on the board neopixels. This is extremely helpful to debug or 
 find the range of values you want to use.
 
 */

#include <Adafruit_CircuitPlayground.h>

int sensorPin = A2;  // select the input pin for the sensor
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {

  pinMode(sensorPin, INPUT);
  CircuitPlayground.begin(); //Required
  CircuitPlayground.clearPixels();
  CircuitPlayground.strip.setBrightness(200); //255 is the max
  Serial.begin(9600);

}

void loop() {
  
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  int brightness = map(sensorValue, 0, 1023, 0, 255);
  for(int i=0; i<10; i++) { // For each pixel in strip...
    CircuitPlayground.strip.setPixelColor(i, brightness, 0, 0);         //  Set pixel's color (in RAM)
  }

  CircuitPlayground.strip.show();
  Serial.println(sensorValue);
}
