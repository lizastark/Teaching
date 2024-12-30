/*
   
Reading Sensor Values Level 2: map, constrain
Circuit Playground Express
Comp Craft Spring 2025
 
This sketch reads a textile sensor and fades an LED based on the sensor value. It uses the 
map() and constrain() functions to reduce noise. The sensor is attached to A2 through a 10k voltage divider.


*/

#include <Adafruit_CircuitPlayground.h>

// variables to store pins + values of sensor and LED
int sensorPin = A2;
int sensorValue = 0;
int newSensorValue;


void setup() {
  // configure pins
  pinMode(sensorPin, INPUT);

  CircuitPlayground.begin();  //Required
  CircuitPlayground.clearPixels();
  CircuitPlayground.strip.setBrightness(200);  //255 is the max

  // initialize serial communication with computer:
  Serial.begin(9600);

}

void loop() {
  // read raw data to compare
  sensorValue = analogRead(sensorPin);
  Serial.print("Raw = ");
  Serial.print(sensorValue);
  Serial.print("\t\t");

  //map the range from your average values to the range of an LED output
  newSensorValue = map(sensorValue, 20, 800, 0, 255);

  //constrain the input range to LED output values
  newSensorValue = constrain(newSensorValue, 0, 255);

  Serial.print("New = ");
  Serial.println(newSensorValue);

  // Use a conditional to turn off LED if new min value doesn't turn the LED all the way off
  if (newSensorValue > 30) {
    for (int i = 0; i < 4; i++) {                                      // For each pixel in strip...
      CircuitPlayground.strip.setPixelColor(i, newSensorValue, 0, 0);  //  Set pixel's color
    }
  } else if (newSensorValue <= 29) {
    for (int i = 0; i < 4; i++) {                         // For each pixel in strip...
      CircuitPlayground.strip.setPixelColor(i, 0, 0, 0);  //  Set pixel's color (in RAM)
    }
  }
  //show the neopixels
  CircuitPlayground.strip.show();

  delay(1);
}
