#include <Key.h>
#include <Keypad.h>


const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'A','B','C','D'},
  {'E','F','G', 'H'},
  {'I','J','K', 'L'},
  {'M','N','O', 'P'}                      
};
byte rowPins[ROWS] = {6,7,8,9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {2, 3, 4, 5}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  Serial.println('a');
}

void loop(){
  char key = keypad.getKey();
  Serial.println('a');
  if (key != NO_KEY){
    Serial.println(key);
  }
}
