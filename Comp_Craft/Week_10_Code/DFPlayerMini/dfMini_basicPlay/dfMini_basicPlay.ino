/*

  DFPLAYER MINI BASIC PLAY
  Computational Craft 
  March 2022

  This does not use the DFPlayer Mini Library on DFRobot's site and instead uses
  commands developed and documented by Ype Brada:
  https://forum.banggood.com/forum-topic-59997.html
  (full sketch also here: https://github.com/lizastark/Projects/blob/master/Sonic_Quilt/dfMini_tutorial/dfMini_fullTestSketch/dfMini_fullTestSketch.ino)

  Schematic and module data sheet/info are here:
  https://www.dfrobot.com/wiki/index.php/DFPlayer_Mini_SKU:DFR0299

  Very important: Use serial 1K resistors on RX and TX
  to suppress noise
  Connect Sound module board RX to Arduino pin 10 
  Connect Sound module board TX to Arduino pin 11 

  DEBUGGING NOTE: If the player suddenly stops working, uncomment or comment out the serial.printlns
  inside of the for loops with the commands. I have no idea why some work with it, some don't,
  and some flip back and forth, but this was the solution.

  Make sure you name and organize your files as mentioned in the 
  full test sketch above (i.e. 001.mp3, etc)

*/

#include "SoftwareSerial.h"
SoftwareSerial mySerial(10, 11);
//mySerial(RX, TX)
char play[10] = { 0X7E, 0xFF, 0x06, 0X03, 00, 00, 0x01, 0xFE, 0xF7, 0XEF};
char setVolume[10] = { 0X7E, 0xFF, 0x06, 0X06, 00, 00, 0x1E, 0xFE, 0xD7, 0XEF};


void setup () {
  mySerial.begin (9600);
  delay(1000);

  // Set volume to 30
  for (int count = 0; count < 10; count++) {
    mySerial.write(setVolume[count]);

  }


  // Play file once
  for (int count = 0; count < 10; count++) {
    mySerial.write( play[count]);
    
  }
 
}

void loop () {

}
