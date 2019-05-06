/*5.2.19
 Created and Designed by Zane Rickert and Tyson Watson
  This program is going to be a 16% keyboard that
  can send basic inputs to the computer.
  Took some of the code from https://www.pjrc.com/teensy/td_libs_Keypad.html

  MMMIIIIMCGGKKOOPLHDAEEIIIMMMKKDDDHHLPKKKKKGMEIACCDAAAAEEEEEEEEEEEEEEIIIIMIAAAAAAAEEEMMMMMIMMMMEEMEMEMMEEEMMEEMMMPPPLLP
 */


#include "Key.h"
#include <Keypad.h>
#include <Keyboard.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'M','N',VK_LBUTTON,' '},
  {'I','J','K', 'L'},
  {'E','F','G', 'H'},
  {'A','B','C', 'D'}                      
};
byte rowPins[ROWS] = {6,7,8,9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {2, 3, 4, 5}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  Keyboard.write('a');
}

void loop(){
  char key = keypad.getKey();

  if (key != NO_KEY){
    Keyboard.write(key);
  }
}
