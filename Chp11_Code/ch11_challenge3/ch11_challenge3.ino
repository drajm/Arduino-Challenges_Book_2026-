#include <Keypad.h>
#include <LiquidCrystal.h>   // ✅ needed for LCD

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const byte ROWS = 4;
const byte COLS = 3;

char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

// ⚠️ Don't use 0 and 1 → reserved for Serial
byte rowPins[ROWS] = {10,9,8,7};  
byte colPins[COLS] = {6,1,0};  // pick free pins that don’t overlap LCD

Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Ready...");
}

void loop() {
  char key = kpd.getKey();

  if (key) {
    lcd.print(key);

    if (key == '*') {
      lcd.clear();
    }
  }
}
