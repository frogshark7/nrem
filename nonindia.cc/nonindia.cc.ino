#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

float glucon = 15;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 1);
}

void loop() {

  if (glucon > 10) {
    lcd.display();
    lcd.setCursor(4, 0);
    lcd.print("HIGH");
  } else if (glucon < 3.9) {
    lcd.display();
    lcd.setCursor(3, 0);
    lcd.print("LOW");
  } else {
    lcd.display();
    lcd.setCursor(5, 0);
    lcd.print("GOOD");
  }
}

