/*
   READING SENSOR VALUES W/CALIBERATION + SMOOTHING
   Liza Stark
   Updated Feb 2022

   This sketch reads a textile sensor and fades an LED based on the sensor value. It incorporates smoothing
   and calibration examples by Mellis and Igoe.

   The sensor is attached to A0 through a 10k voltage divider. 
   The LED is on pin 9.

*/


// Define the number of samples to keep track of.  The higher the number,
// the more the readings will be smoothed, but the slower the output will
// respond to the input.  Using a constant rather than a normal variable lets
// use this value to determine the size of the readings array.

const int numReadings = 10;     // average number of readings
int readings[numReadings];      // the readings from the sensor
int readIndex = 0;              // the index of the current reading on the sensor
int total = 0;                  // the running total for the sensor
int average = 0;                // the average for the sensor
int sensor = A0;                // sensor pin

// Calibration variables
int sensorValue = 0;
int sensorMin = 1023;           //this is supposed to be higher
int sensorMax = 0;              //this is supposed to be lower

int LEDpin = 9;

void setup() {

  // initialize serial communication with computer:
  Serial.begin(9600);
  pinMode(LEDpin, OUTPUT);

  /*
       This is the calibration part of the sketch. Once you upload it,
       open your serial monitor and follow the instuctions. You
       can aomment this out once you have your sensor calibrated
  */

  // turn on LED to signal the start of the calibration period:
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  // initialize all the readings on the sensor to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }

  Serial.println("Calibration beginning");
  Serial.println("Take deep breaths until the LED goes off");

  // calibrate during the first five seconds
  while (millis() < 5000) {
    sensorValue = analogRead(sensor);

    // record the maximum sensor value
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }

    // record the minimum sensor value
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }

    // print values for debugging
    Serial.print("Max = ");
    Serial.print(sensorMax);
    Serial.print("\t");
    Serial.print("Min = ");
    Serial.println(sensorMin);

  }

  // signal the end of the calibration period
  digitalWrite(13, LOW);
  Serial.println("Calibration ending");

  //End comment

}

void loop() {
  // READ VALUES COMING IN FROM THE SENSOR - Take average of 10 readings
  // subtract the last reading:
  total = total - readings[readIndex];

  // read from the sensor:
  readings[readIndex] = analogRead(sensor);

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

  // print the original average for debugging
  Serial.print("Average = ");
  Serial.print(average);
  Serial.println("\t");

  // map the average value to the min and max we recorded above
  average = map(average, sensorMin, sensorMax, 0, 255); //change back to 255

  // constrain the values within a certain range
  average = constrain(average, 0, 255);

  // print the new average for debugging
  Serial.print("New Average = ");
  Serial.println(average);

  // conditional to turn off LED if new min value
  // doesn't turn the LED all the way off
  if(average > 31){
    analogWrite(LEDpin, average);
  } else if(average < 30){
    analogWrite(LEDpin, 0);
  }

  delay(1);        // delay in between reads for stability

}
