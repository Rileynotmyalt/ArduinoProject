/**
 * This is Riley Carter's Computer Science Principals Arduino Project
 * This program displays a character on a lcd display and the player
 * can navigate through a course using buttons
*/

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte empty[8] = {
  B00000,
};

byte underscore[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111
};

byte upRamp[8] = {
  B00000,
  B00000,
  B00001,
  B00011,
  B00111,
  B01111,
  B11111,
  B11111
};


String mapString[2] = {
  "                ",
  "_<XX>____   ____"
};

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  lcd.createChar(0, empty);
  lcd.createChar(1, upRamp);
  lcd.createChar(2, underscore);
  
  lcd.write(byte(0));
  // for each in mapString read and write onto screen
}

void loop() {
  
}