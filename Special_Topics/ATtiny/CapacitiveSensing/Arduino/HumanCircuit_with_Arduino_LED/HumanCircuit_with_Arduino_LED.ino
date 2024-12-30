/*
 Human Circuit
 Computational Craft
 Liza Stark with guidance of amazing Joe Savaadra

 HOW:
 Place a 1-2 Megaohm resistor between GRD and your
 analog input pin (A0 shown). We will call this POLE 1.
 Attach POLE 2 to POWER/5V.

 (SEE SCHEMATIC)

 WHY:
 When you touch 5V to POLE 1 it will instantly pull
 POLE 1 high and activate the sensor. GRD is so weak when
 it is attached to such a high resistor, it will pull high.
 Even though our skin is super resistive, this will allow our body to act as a conductor (with no danger :).


 */

int sensorPin = A0;    // select the input pin for the sensor
int ledPin = 9;     // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor


void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600); //Comment this out if you want to try this with ATtiny
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  
  //Print the value to the Serial monitor
  Serial.println(sensorValue); //Comment this out if you want to try this with ATtiny
  
  if (sensorValue > 100) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

}

