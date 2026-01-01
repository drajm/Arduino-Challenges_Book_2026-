#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int a = 0;

void setup() {
  lcd.begin(16, 2);   // ✅ Correct size for your LCD
  Serial.begin(9600);
  pinMode(A5, INPUT_PULLUP);
}

int readButtons(int pin) {
  int b = 0;
  int c = analogRead(pin);

  // Debug: show raw analog value
  Serial.print("Analog Read = ");
  Serial.println(c);

  if (c > 1000) {
    b = 0; // no button
  } else if (c > 70 && c < 82) {
    b = 1;
  } else if (c > 52 && c < 64) {
    b = 2;
  } else if (c > 33 && c < 45) {
    b = 3;
  } else if (c > 15 && c < 25) {
    b = 4;
  } else if (c >= 0 && c < 10) {
    b = 5;
  }

  Serial.print("Detected Button = ");
  Serial.println(b);

  return b;
}

void loop() {
  a = readButtons(A5);

  lcd.clear();
  lcd.setCursor(0, 0);   // ✅ First row
  if (a == 0) {
    lcd.print("Press a button");
  } else {
    lcd.print("Pressed button ");
    lcd.print(a);
  }

  delay(500);
}
