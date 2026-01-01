#include <TM1637Display.h>
const int CLK = 3; 
const int DIO = 2; 
int numCounter = 0;
TM1637Display display(CLK, DIO); 
void setup()
{
display.setBrightness(0x0a);
}
void loop()
{
for(numCounter = 0; numCounter < 1000; numCounter++)
{
display.showNumberDec(numCounter); 
delay(1000);
}
