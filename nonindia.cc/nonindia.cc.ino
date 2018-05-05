int sensorValue0 = 0; // variable to store the value coming from the sensor
float glucon;
int voltage;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  digitalWrite(5, HIGH);

  sensorValue0 = analogRead(A0); // read the value from the sensor
  voltage = sensorValue0 * 5 / 1023;
  glucon = 16.522 * voltage - 35.294;
  printcalc();
  led_out();
}

void printcalc() {
  Serial.println(glucon);
  delay(100);
}

void led_out() {
  if (glucon > 140) {
    digitalWrite(2, HIGH);
  } else if (glucon > 60 && glucon < 140) {
    digitalWrite(3, HIGH);
  } else if (glucon < 60) {
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
}
