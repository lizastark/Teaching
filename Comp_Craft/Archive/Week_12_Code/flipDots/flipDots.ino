/*
  Flip Dots
  Liza Stark
  Fall 2018

  Uses two MOSFETs to flip a magnetic hematite bead
  back and forth.

  
*/


int flipdot1 = 2;
int flipdot2 = 4;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(flipdot1, OUTPUT);
  pinMode(flipdot2, OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  
  // flip forward
  digitalWrite(flipdot1, HIGH);
  delay(100); // don't increase this value - could over heat
  Serial.println("Forward");
  digitalWrite(flipdot1, LOW);
  digitalWrite(flipdot2, LOW);
  delay(2000);
  
  //flip backward
  digitalWrite(flipdot2, HIGH);
  delay(100); // don't increase this value - could over heat
  Serial.println("Backward");
  digitalWrite(flipdot1, LOW);
   digitalWrite(flipdot2, LOW);
  delay(2000);
  
  
}
