/*

HUMAN CIRCUIT CODE 
Spring 2025
How it works
+ Must touch both electrodes
+ Human body acts as connector 
    Uses high resistance switching (like the Makey Makey)
    Since the resistor value is higher than the resistance of the human body (~100K Ohms),  your skin can act as a connector

 */

int touchPin = A1;    // select the input pin for the sensor
int LEDpin = 2;     // A5 on CPX
int touchValue = 0;  // variable to store the value coming from the sensor
int threshold = 400;


void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(LEDpin, OUTPUT);  
  pinMode(touchPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // read the value from the touch pad:
  touchValue = analogRead(touchPin); 
  
  //Print the value to the Serial monitor   
  Serial.println(touchValue);  

  // If being touched, turn on LED
  if(touchValue > threshold){
   digitalWrite(LEDpin, HIGH); 
  }else{
   digitalWrite(LEDpin, LOW); 
  }

}

