/*
 * 
 * Software Serial with the ATtiny
 * 
 * This sketch reads analog values coming in from the ATtiny.
 * Be sure to read the full pinout when working with analog input:
 * http://highlowtech.org/wp-content/uploads/2011/10/ATtiny45-85.png
 * 
 * Fall 2016
 * Computational Craft //MFADT Parsons
 * 
 * CREDITS:
quitmeyer
https://github.com/quitmeyer/ATtinyBareDemos/blob/master/ATTinyAnalogInputTOSerial/ATTinyAnalogInputTOSerial.ino

Takes an input on the AtTiny85 from the VERY TRICKY analogue input pin 2 (as labeled in HLT tutorial)
and outputs these with Software serial to the arduino uno, or Duemillanove
Hookup 
ATTINY85/45 pin 3 -> Arduino Uno pin 0
ATTINY85/45 pin 4 -> Arduino Uno pin 1

 */


#include <SoftwareSerial.h>
// Definitions
#define rxPin 10 //3 for ATiny45/85
#define txPin 9 //4 for ATiny45/85

SoftwareSerial mySerial(rxPin, txPin);

//int sensorPin = 7; //uncomment if using ATtiny 45/85 - ACTUALLY PIN LABELED AS "2" on the HLT tutorial
int sensorPin = A2; //uncomment if using ATtiny 44/84
int sensorVal = -1;


// the setup routine runs once when you press reset:
void setup() {                
  pinMode(sensorPin, INPUT);
  mySerial.begin(9600);
  mySerial.println("this is in the setup");
}

// the loop routine runs over and over asensorpingain forever:
void loop() {

  sensorVal = analogRead(sensorPin); 
  mySerial.print("Input Val: ");
  mySerial.print(sensorVal);

  mySerial.println();
}

