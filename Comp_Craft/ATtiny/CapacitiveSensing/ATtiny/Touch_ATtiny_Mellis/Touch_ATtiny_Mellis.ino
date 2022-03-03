// Created by Dave Mellis
// See tutorial here: http://highlowtech.org/?p=1653
//
//                        attiny85
//                   reset -+---+- power
// (on while touching) pb3 -+*  +- pb2 (toggled by touch)
//       (touch input) pb4 -+   +- pb1 (fading while touching)
//                  ground -+---+- pb0 (fading always)


int fadepin1 = 0; // the led that fades on and off
int fadepin2 = 1; // the led that fades on and off while you're touching the input pin
int togglepin = 2; // the led that's toggled when you touch the input pin
int steadypin = 3; // the led that's on while you're touching the input pin

int calibration = 0;
int previous;

int randomval = 0;
int fadeval = 0, fadestep = 1;
int togglestate = LOW;

void setup()
{
  pinMode(fadepin1, OUTPUT);
  pinMode(fadepin2, OUTPUT);
  pinMode(togglepin, OUTPUT);
  pinMode(steadypin, OUTPUT);
  
  delay(100);
  for (int i = 0; i < 8; i++) {
    calibration += chargeTime(PB4);
    delay(20);
  }
  calibration = (calibration + 4) / 8;
}

void loop()
{
  int n = chargeTime(PB4);
  
  if (n > calibration) digitalWrite(steadypin, HIGH);
  else digitalWrite(steadypin, LOW);
  
  analogWrite(fadepin1, fadeval);
  if (n > calibration) analogWrite(fadepin2, fadeval);
  else analogWrite(fadepin2, 0);
  fadeval = fadeval + fadestep;
  if (fadeval == 255) fadestep = -1;
  if (fadeval == 0) fadestep = 1;
  
  if (previous <= calibration && n > calibration) {
    if (togglestate == LOW) togglestate = HIGH;
    else togglestate = LOW;
    
    digitalWrite(togglepin, togglestate);
  }
  
  previous = n;
  
  delayMicroseconds(500);
}

byte chargeTime(byte pin)
{
  byte mask = (1 << pin);
  byte i;

  DDRB &= ~mask; // input
  PORTB |= mask; // pull-up on

  for (i = 0; i < 16; i++) {
    if (PINB & mask) break;
  }

  PORTB &= ~mask; // pull-up off
  DDRB |= mask; // discharge

  return i;
}

