/*5.2.19
 Created and Designed by Zane Rickert and Tyson Watson
  This program is going to be a 16% keyboard that
  can send basic inputs to the computer.
  Took some of the code from https://www.pjrc.com/teensy/td_libs_Keypad.html123123456789
                7741  2587  147369
  1 
 */
#include "Key.h"
#include <Keypad.h>
#include <Keyboard.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'7','4', '1',' '},
  {'8','5', '2', 216}, //Left arrow
  {'9','6', '3', 215}, //Right Arrow
  {178,176, 218, 217} // Backspace, Enter, Up and Down arrow                     
};
byte rowPins[ROWS] = {6,7,8,9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {2, 3, 4, 5}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  char key = keypad.getKey();
  if (key != NO_KEY)
  {
    Keyboard.write(key);
  }
  
}

