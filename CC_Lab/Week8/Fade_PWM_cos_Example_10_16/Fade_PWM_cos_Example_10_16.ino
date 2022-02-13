/*
Posted by Liza Stark as CC Lab Example Fall 2012

PWM Fade without delay(), given as example in class 10/16

There are a few ways to handle PWM without a delay. Keeping track of your time 
through millis() is a pretty common solution, but I found this one to be much more
elegant.

From Christian Liljedahl
http://arduino.cc/forum/index.php/topic,12004.msg91555.html#msg91555
Reply #6 to the post

This is a simple example I use: 
Basicly the idea is: 
- Use millis() to get the "time"
- Use a sin/cos function to determine the fade-level of the diode.
Benefit of using sinus is, that you get a much more smooth and pretty fade. 
Linear fade is dull. :-)

*/


int value, value2 ;
int ledpin = 10;                           // light connected to digital pin 10
int ledpin2 = 11;                           // light connected to digital pin 11
long time=0;

int periode = 2000;
int displace = 500;

void setup() 
{ 
  // nothing for setup 
} 

void loop() 
{ 
  time = millis();
  value = 128+127*cos(2*PI/periode*time);
  value2 = 128+127*cos(2*PI/periode*(displace-time));
  analogWrite(ledpin, value);           // sets the value (range from 0 to 255) 
  analogWrite(ledpin2, value2);           // sets the value (range from 0 to 255) 
}
