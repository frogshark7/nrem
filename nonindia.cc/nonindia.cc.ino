#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 4, 5, 6, 7); //LCD Setup
int sensorValue0 = 0; //Input Var
float glucon; //Glucose Concentration
int voltage;  //Photodiode Voltage

void setup() {
  lcd.begin(16, 1);
  Serial.begin(9600);
  pinMode(13, OUTPUT); //Infra LED Pin
}

void loop() {
  digitalWrite(13, HIGH);
  sensorValue0 = analogRead(A0);
  voltage = sensorValue0 * 5 / 1023; //Volt convert
  glucon = 16.522 * voltage - 35.294; //Glucose Value
  printcalc();
  lcdout();
}

void printcalc() {
  printf("%f", glucon);
  delay(100);
}

void lcdout() {
  if (glucon > 140) {
    lcd.display();
    lcd.setCursor(5, 0);
    lcd.print("HIGH");
  } else if (glucon < 60) {
    lcd.display();
    lcd.setCursor(6, 0);
    lcd.print("LOW");
  } else {
    lcd.display();
    lcd.setCursor(5, 0);
    lcd.print("GOOD");
  }
}
