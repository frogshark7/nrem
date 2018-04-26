#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

float glucon;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);

}

void loop() {

  if (glucon > 10) {
    lcd.display();
    lcd.print("HIGH");
  } else if (glucon < 3.9) {
    lcd.display();
    lcd.print("LOW");
  } else {
    lcd.display();
    lcd.print("GOOD");
  }

}
