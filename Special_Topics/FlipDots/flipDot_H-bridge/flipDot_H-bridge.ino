/*  
  H-bridge sketch for flip dots
  Uses the L9110H chip. More information:
      Tutorial: https://itp.nyu.edu/physcomp/labs/motors-and-transistors/dc-motor-control-using-an-h-bridge/
      Tutorial: https://itp.nyu.edu/physcomp/lessons/dc-motors-the-basics/#Direction  
      Example: https://www.kobakant.at/DIY/?p=8059
*/


const int fd1pin = 9;  // H-bridge leg 1 (pin 6, 1A)
const int fd2pin = 10;  // H-bridge leg 2 (pin 7, 2A)

void setup() {
  
  pinMode(fd1pin, OUTPUT);
  pinMode(fd2pin, OUTPUT);
}  

void loop() {
  digitalWrite(fd1pin, LOW);
  digitalWrite(fd2pin, HIGH);
  delay(1000);
  digitalWrite(fd1pin, HIGH);
  digitalWrite(fd2pin, LOW);
  delay(1000);
}