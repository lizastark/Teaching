/*
  Arrays

  Demonstrates the use of  an array to hold pin numbers
  in order to iterate over the pins in a sequence.
  Lights multiple LEDs in sequence, then in reverse.

  Unlike the For Loop tutorial, where the pins have to be
  contiguous, here the pins can be in any random order.

  The circuit:
   LEDs from pins 2 through 7 to ground

  created 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Array
*/

int timer = 100;           // The higher the number, the slower the timing.
int ledPins[] = {
  2,7,4
};       // an array of pin numbers to which LEDs are attached


void setup() {
  // the array elements are numbered from 0 to (pinCount - 1).
  // use a for loop to initialize each pin as an output:
  pinMode(ledPins[0], OUTPUT);
  pinMode(ledPins[1], OUTPUT);
  pinMode(ledPins[2], OUTPUT);

}

void loop() {
  //turn on pin 2
  digitalWrite(ledPins[0], HIGH);
  //turn on pin 7
  digitalWrite(ledPins[1], HIGH);
  //turn on pin 4
  digitalWrite(ledPins[0], HIGH);

  //delay a bit
  delay(timer);
  
  // turn the pin off:
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], LOW);
  digitalWrite(ledPins[2], LOW);
  delay(timer);

}

