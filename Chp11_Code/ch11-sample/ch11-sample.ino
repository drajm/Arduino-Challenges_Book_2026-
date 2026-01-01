#include <Keypad.h>
const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'#','0','*'}
};
byte rowPins[ROWS] = { 9, 8, 7, 6 };
byte colPins[COLS] = { 5,4,3 };
Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
#define ledpin 13
void setup()
{
pinMode(ledpin,OUTPUT);
digitalWrite(ledpin, HIGH);
Serial.begin(9600);
}
void loop()
{
char key = kpd.getKey();
if(key) // Check for a valid key.
{
switch (key)
{
case '*':
digitalWrite(ledpin, LOW);
break;
case '#':
digitalWrite(ledpin, HIGH);
break;
default:
Serial.println(key);
}
}
}
