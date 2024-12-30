/*

 Reading Sensor Values
 Comp Craft Spring 2013
 
 This sketch reads the data coming in from the sensor and prints it to the serial
 monitor. This is extremely helpful to debug or find the range of values you 
 want to use.
 
 
 */

int sensorPin = A11;    // select the input pin for the sensor
int flexinol = 9;     // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int newSensorValue;


void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(flexinol, OUTPUT);  
  pinMode(sensorPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin); 
  newSensorValue = map(sensorValue, 855, 0, 423, 255);
  //Print the value to the Serial monitor   
  Serial.println(newSensorValue);  
  if(newSensorValue>100){
   analogWrite(flexinol, 200); 
   delay(200);
  }else{
   analogWrite(flexinol, 0); 
   delay(500);
  }

}

