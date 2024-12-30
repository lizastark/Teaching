/*

 Millis() Timer Example Code
 
 Creativity and Computation Lab
 Fall 2012
 
 Turns an LED on and off in an interval of 2 seconds
 
 This sketch uses two additional variables currentTime and loopTime.
 In the setup() function both variables are initially set to the 
 same value. In the main loop() function, currentTime is updated 
 everytime through the loop. Only when at least one second has passed
 and the currentTime variable is greater than loopTime + 1000 
 (1000 milliseconds = 1 second) does it then toggle the ledPin value 
 and also reset loopTime to the same value as currentTime.
 
 Adapted from code located here:
 http://www.hobbytronics.co.uk/arduino-tutorial3-timing
 
 */


int ledPin = 13;
unsigned long currentTime;
unsigned long loopTime;

void setup(){
  pinMode(ledPin, OUTPUT);
  currentTime = millis(); //Both currentTime and loopTime start off as the same
  loopTime = currentTime; //Current time is updated in the main loop, then 
  Serial.begin(9600);     //Then compared to loopTime

}

void loop(){

  currentTime = millis();
  if(currentTime >= (loopTime + 1000)){
    digitalWrite(ledPin, !digitalRead(ledPin)); //toggles light on and off
    loopTime = currentTime; //Updates loop time
    Serial.print("The currentTime is ");
    Serial.println(currentTime);
  } 

}




