/*

  DFPLAYER MINI MP3 - skip tracks
  Computational Craft
  March 2022

  Program taken from http://educ8s.tv/arduino-mp3-player/

  This sketch programs a simple mp3 player which will have 3 buttons. The first
  button will be used to Play/Pause the music currently being played, while the
  second one will be used to load the next song(the next button) and the last one
  will be used to load the previous song ( the previous button). The music files
  to be played using the DFplayer mini are pre-stored on an SD card which is
  inserted into the DF player mini.

  This does not use the DFPlayer Mini Library on DFRobot's site and instead uses
  commands developed and documented by Ype Brada:
  https://forum.banggood.com/forum-topic-59997.html
  (full sketch also here: https://github.com/lizastark/Projects/blob/master/Sonic_Quilt/dfMini_tutorial/dfMini_fullTestSketch/dfMini_fullTestSketch.ino)

  Schematic and module data sheet/info are here:
  https://www.dfrobot.com/wiki/index.php/DFPlayer_Mini_SKU:DFR0299

  Very important: Use serial 1K resistors on RX and TX
  to suppress noise
  Connect Sound module board RX to Arduino pin 8 <-- This is pin 10 on the example on the DFRobot site
  Connect Sound module board TX to Arduino pin 9 <-- This is pin 11 on the example on the DFRobot site

  DEBUGGING NOTE: If the player suddenly stops working, uncomment or comment out the serial.printlns
  inside of the for loops with the commands. I have no idea why some work with it, some don't,
  and some flip back and forth, but this was the solution.

  Make sure you name and organize your files as mentioned in the
  full test sketch above (i.e. 001.mp3, etc)

*/


#include "SoftwareSerial.h"
SoftwareSerial mySerial(10, 11);
# define Start_Byte 0x7E
# define Version_Byte 0xFF
# define Command_Length 0x06
# define End_Byte 0xEF
# define Acknowledge 0x00 //Returns info with command 0x41 [0x01: info, 0x00: no info]

# define ACTIVATED LOW

int buttonNext = 2;
int buttonPause = 3;
int buttonPrevious = 4;
boolean isPlaying = false;


void setup () {

  pinMode(buttonPause, INPUT_PULLUP);
  digitalWrite(buttonPause, HIGH);

  pinMode(buttonNext, INPUT_PULLUP);
  digitalWrite(buttonNext, HIGH);

  pinMode(buttonPrevious, INPUT_PULLUP);
  digitalWrite(buttonPrevious, HIGH);

  mySerial.begin (9600);
  delay(1000);
  playFirst();
  isPlaying = true;

}



void loop () {

  if (digitalRead(buttonPause) == ACTIVATED)
  {
    if (isPlaying)
    {
      pause();
      isPlaying = false;
    } else
    {
      isPlaying = true;
      play();
    }
  }


  if (digitalRead(buttonNext) == ACTIVATED)
  {
    if (isPlaying)
    {
      playNext();
    }
  }

  if (digitalRead(buttonPrevious) == ACTIVATED)
  {
    if (isPlaying)
    {
      playPrevious();
    }
  }
}

void playFirst()
{
  execute_CMD(0x3F, 0, 0);
  delay(500);
  setVolume(20);
  delay(500);
  execute_CMD(0x11, 0, 1);
  delay(500);
}

void pause()
{
  execute_CMD(0x0E, 0, 0);
  delay(500);
}

void play()
{
  execute_CMD(0x0D, 0, 1);
  delay(500);
}

void playNext()
{
  execute_CMD(0x01, 0, 1);
  delay(500);
}

void playPrevious()
{
  execute_CMD(0x02, 0, 1);
  delay(500);
}

void setVolume(int volume)
{
  execute_CMD(0x06, 0, volume); // Set the volume (0x00~0x30)
  delay(2000);
}

void execute_CMD(byte CMD, byte Par1, byte Par2)
// Excecute the command and parameters
{
  // Calculate the checksum (2 bytes)
  word checksum = -(Version_Byte + Command_Length + CMD + Acknowledge + Par1 + Par2);
  // Build the command line
  byte Command_line[10] = { Start_Byte, Version_Byte, Command_Length, CMD, Acknowledge,
                            Par1, Par2, highByte(checksum), lowByte(checksum), End_Byte
                          };
  //Send the command line to the module
  for (byte k = 0; k < 10; k++)
  {
    mySerial.write( Command_line[k]);
  }
}
