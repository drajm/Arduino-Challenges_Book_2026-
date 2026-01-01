#include <avr/io.h> 
#include <util/delay.h>
int main(void) 
{ 
 pinMode(3, OUTPUT); 





TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);






TCCR2B = 
_BV(WGM22) | _BV(CS20);



OCR2A = 63; 


OCR2B = 0;
while (1) {
 _delay_us(5); 
 if ( OCR2B < 63 ) 
 OCR2B += 5; 
 else 
 OCR2B = 0; 
 }
}
