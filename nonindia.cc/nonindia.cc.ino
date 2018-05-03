#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 4, 5, 6, 7);
int sensorPin0 = A0; // select the input pin for ldr
int sensorValue0 = 0; // variable to store the value coming from the sensor
float glucon;
int voltage;


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 1);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);

  sensorValue0 = analogRead(sensorPin0); // read the value from the sensor
  voltage = sensorValue0 * 5 / 1023;
  glucon = 16.522 * voltage - 35.294;
  printcalc();

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

void printcalc() {
  printf("%f", glucon);
  delay(100);
}

