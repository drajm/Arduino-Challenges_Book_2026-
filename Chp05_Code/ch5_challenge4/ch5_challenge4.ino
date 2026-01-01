#include <LiquidCrystal.h>
LiquidCrystal lcd(6, 7, 8, 9, 10, 11, 12);
void setup()
{
lcd.begin(16, 2);
lcd.clear();
lcd.print("chalesh 4");
delay(1000);
lcd.setCursor(2, 1);
lcd.print("salam ");
lcd.cursor();
delay(3000);
lcd.noCursor();
delay(3000);
lcd.blink();
delay(3000);
lcd.noBlink();
delay(2000);
lcd.noDisplay();
delay(4000);
lcd.display();
delay(1000);
lcd.clear();
delay(100);
lcd.print("َtext");
for (int i = 0 ; i &lt; 22 ; i++)
{
lcd.scrollDisplayRight();
delay(500);
}
for (int i = 0 ; i &lt; 22 ; i++)
{
lcd.scrollDisplayLeft();
delay(500);
}
delay(2000);
lcd.clear();
lcd.setCursor(0, 0);
for (int thisChar = 0; thisChar &lt; 10; thisChar++) {
lcd.print(thisChar);
delay(500);
}
lcd.setCursor(16, 1);
lcd.autoscroll();
for (int thisChar = 0; thisChar &lt; 10; thisChar++) {
lcd.print(thisChar);
delay(500);
}
lcd.noAutoscroll();
delay(1000);
lcd.clear();
lcd.rightToLeft();
lcd.setCursor(15, 0);
lcd.print("123456");
lcd.leftToRight();
lcd.setCursor(0, 0);
lcd.print("123456");
delay(2000);
lcd.clear();
lcd.print("End");
}
void loop()
{
}
