#include <Keypad.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8, 7);
const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
{'1', '2', '3'},
{'4', '5', '6'},
{'7', '8', '9'},
{'*', '0', '#'}
};
byte rowPins[ROWS] = {0, 1, 2, 3};
byte colPins[COLS] = {4, 5, 6};
Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
void setup() {
lcd.begin(16, 2);
}
void loop() {
char key = kpd.getKey();
if (key) {
lcd.print(key);
if (key == '*')
{
lcd.clear();
}}}
