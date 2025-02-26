/*
  p5 Serial Test
  Spring 2024 Comp Craft
  Test sketch for communicating with p5.js

  This sketch reads the analog data coming in from the sensor and prints it to the serial
  monitor. Values in serial.println() will be sent to p5.serialconnect and received 
  by p5.js as incoming data.
  See this collection: https://editor.p5js.org/lizastark/collections/QzbIVMAMn
  Remember to change your port!

*/

int sensorPin = A4;    // select the input pin for the sensor
int sensorValue;  // variable to store the value coming from the sensor


void setup() {
  pinMode(15, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);

  //Print the value to the Serial monitor
  Serial.println(sensorValue);

  
}

