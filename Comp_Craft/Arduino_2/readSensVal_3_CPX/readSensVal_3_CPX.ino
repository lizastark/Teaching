/*
   
Reading Sensor Values Level 3: map, constrain, smoothing, conditional
Circuit Playground Express
Comp Craft Spring 2025
 
This sketch reads a textile sensor and fades an LED based on the sensor value. It uses the 
map() and constrain() functions as well as smoothing to reduce noise. It also adds a final 
conditional to ensure jumpy values don't impact output.The sensor is attached to A2 
through a 10k voltage divider.


*/

#include <Adafruit_CircuitPlayground.h>

// variables to store pins + values of sensor and LED
int sensorPin = A2;
int sensorValue = 0;
int newSensorValue;

// define the number of samples to keep track of. The higher the number, the
// more the readings will be smoothed, but the slower the output will respond to
// the input. Using a constant rather than a normal variable lets us use this
// value to determine the size of the readings array.
const int numReadings = 10;

int readings[numReadings];  // the readings from the analog input
int readIndex = 0;          // the index of the current reading
int total = 0;              // the running total
int average = 0;            // the average


void setup() {
  // configure pins
  pinMode(sensorPin, INPUT);

  CircuitPlayground.begin();  //Required
  CircuitPlayground.clearPixels();
  CircuitPlayground.strip.setBrightness(200);  //255 is the max

  // initialize serial communication with computer:
  Serial.begin(9600);

  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() {
  // read raw data to compare
  sensorValue = analogRead(sensorPin);
  Serial.print("Raw = ");
  Serial.print(sensorValue);
  Serial.print("\t\t");

  // start smoothing
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(sensorPin);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits
  Serial.print("Average = ");
  Serial.print(average);
  Serial.print("\t\t");

  //map the range from your average values to the range of an LED output
  newSensorValue = map(average, 20, 800, 0, 255);

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
