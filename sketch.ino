/**
 * This is Riley Carter's Computer Science Principals Arduino Project
 * This program displays a character on a lcd display and the player
 * can navigate through a course using buttons
*/

#include <LiquidCrystal.h>

// make my classes

class PinIn {
  public:
    int pin = 0;

    PinIn(int pinnum) {pin = pinnum;}

    void init() {
      pinMode(pin, INPUT);
    }

    int readIn() {
      return digitalRead(pin);
    }
};


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


String mapString[2] = {
  "           X       X             ",
  "     X                   X      X"
};

// init objects
PinIn upButton(10);
PinIn downButton(9);

void setup() {
  // init serial monitor
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  lcd.setCursor(0,0);
  lcd.print(mapString[0]);
  lcd.setCursor(0, 1);
  lcd.print(mapString[1]);
  // init player (cursor)
  lcd.blink();
}

int playerPos = 0;
int playerRow = 1;

void loop() {
  if (playerPos < mapString[0].length()) {
    playerPos++;
    if (mapString[playerRow].charAt(playerPos) == 'X') {
      lcd.clear();
      lcd.print("You Died!");
      gameOver();
      return;
    }
    lcd.setCursor(playerPos, playerRow);
    lcd.scrollDisplayLeft();
    
    
  } else { // if player passes the level
    lcd.clear();
    lcd.print("You Won!");

    gameOver();
    
  }

  // check for button press
  // might need a short while loop to give user input time
  if (upButton.readIn() == HIGH) {  // Up button
    playerRow = 0;
  }
  if (downButton.readIn() == HIGH) { // Down button
    playerRow = 1;
  }

  delay(1000);
}

void gameOver() {
  delay(3000);

  lcd.setCursor(0,0);
  lcd.print("[up] Again");
  lcd.setCursor(0,1);
  lcd.print("[down] Quit");

  // wait for input
  while (true) {

    // quit
    if (downButton.readIn() == HIGH) {
      lcd.clear();
      lcd.print("You Quit");
      lcd.setCursor(0,1);
      lcd.print("Hit Reset 2 Play");
      for (;;);
    }

    // play
    if (upButton.readIn() == HIGH) {
      lcd.clear();
      lcd.home();
      lcd.print(mapString[0]);
      lcd.setCursor(0,1);
      lcd.print(mapString[1]);
      playerPos=0;
      playerRow=1;
      break;
    }
  }
}