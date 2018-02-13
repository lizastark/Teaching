/*
 * Boolean Example
 * Controlling a switch
 * 
 * Phys Comp 1 
 * MFADT Spring 2018
 * 
 * http://www.instructables.com/topics/How-to-use-a-boolean-in-Arduino/
 * 
 * Good boolean tutorial:
 * https://www.youtube.com/watch?v=HzSiJn62TCY
 * 
 */

boolean mySet = false;
const int LED = 13;
const int BUTTON = 2;
boolean myButton;


void setup() {
  
pinMode(LED, OUTPUT);
pinMode(BUTTON, INPUT);

}

void loop() {

//read the signal coming in from the BUTTON pin  
myButton = digitalRead(BUTTON); 

//determine whether or not to turn on the LED
if (myButton == true) { //i.e. if BUTTON is HIGH
  mySet = true; //set boolean to true or HIGH
}
 else {
   mySet = false; //if it's not HIGH, set boolean to LOW
 }

 digitalWrite(LED, mySet); //write the value to the LED pin
}
