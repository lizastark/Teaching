int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 9;     // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int newSensorValue;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);  
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);    
  // turn the ledPin on
  newSensorValue = map(sensorValue, 0,1023,0, 255);
  analogWrite(ledPin, newSensorValue);

Serial.print(newSensorValue);  
      
}
