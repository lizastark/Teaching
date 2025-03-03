/*
   TOUCH SENSORS ON CPX
   Liza Stark
   Updated Feb 2025

   This sketch activates the touch sensor capabilities of the Circuit Playground Express.

*/

#include <Adafruit_CircuitPlayground.h>

int touchSensor = A4; 
int touchVal; //stores value of capacitve sensor

void setup() {
  CircuitPlayground.begin();
  Serial.begin(9600);
}

void loop() {
  touchVal = CircuitPlayground.readCap(touchSensor, 10); // this sets each touch input and assigns a pin
  Serial.println(touchVal);
}