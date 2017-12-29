#include <CapacitiveSensor.h>

/*
 * Capacitive Sensing with the ATtiny: Software Serial
 *
 * This sketch uses the Software Serial library to read
 * values from the capacitive sensor. Takes in values, smoothes
 * them, then prints HIGHER or LOWER based if above or 
 * below a certain value.
 * 
 * Connect the RX and TX pins of the ATtiny to the Arduino 
 * like so:
 *          ATtiny       Arduino
 *          Pin 3 <----> Pin 0 
 *          Pin 4 <----> Pin 1 
 *          
 * Now we can read the ATtiny's incoming data using the Serial monitor 
 * from Arduino. 
 *
 * Computational Craft //MFADT Parsons
 * Fall 2016
 *
 * CREDITS:
 * blorgggg’s Instructable:
 * Easy ATTiny Serial Communication with Tiny AVR Pro
 * http://www.instructables.com/id/Easy-ATTiny-Serial-Communication-with-Tiny-AVR-Pro/
 *
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger
 * resistor values yield larger sensor values.Receive pin is the sensor
 * pin - try different amounts of foil/metal on this pin.
 */

#include <SoftwareSerial.h>
// Definitions
#define rxPin 3
#define txPin 4

SoftwareSerial mySerial(rxPin, txPin);

CapacitiveSensor   cs_1_0 = CapacitiveSensor(1, 0);
// 10M resistor between pins 3 & 4, pin 4 is sensor pin,
// add a wire and or foil if desired

//For smoothing
const int numReadings = 10;
int total1;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

void setup()
{
  cs_1_0.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  //pinMode(ledPin, OUTPUT);
  //pinMode(ledPin2, OUTPUT);


  for (int thisReading = 0; thisReading < numReadings; thisReading++)
    readings[thisReading] = 0;

  mySerial.begin(9600);
}

void loop()
{

  total1 =  cs_1_0.capacitiveSensor(30);

  delay(10);                             // arbitrary delay to limit data to serial port

  smooth();

  mySerial.print("Input Val: ");
  mySerial.println(average);

  if (average >= 70) { //change this based on the value you want
    mySerial.println("Higher");
  } else {
    mySerial.println("Lower");
  }

}



void smooth() {
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = total1;
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings)
    // ...wrap around to the beginning:
    readIndex = 0;

  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits
}





