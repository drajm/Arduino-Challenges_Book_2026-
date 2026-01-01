int bcd_pins[4]; /* array for driver IC pins*/
void bcd_control_pins(int a, int b, int c, int d) /* Assigns driver IC pins to Arduino board */
{ 
 	bcd_pins[0] = a; 
 	bcd_pins[1] = b;
 	bcd_pins[2] = c;
 	bcd_pins[3] = d;
}
void displaydigits(int num) /* Function for displaying number from 0 to 9) */
{
 	switch(num)
 	{
 	 case 0:
 	 digitalWrite(bcd_pins[0], LOW);  digitalWrite(bcd_pins[1], LOW);
 	 digitalWrite(bcd_pins[2], LOW);  digitalWrite(bcd_pins[3], LOW);
 	 break;
 	
 case 1:
  digitalWrite(bcd_pins[0], HIGH);  digitalWrite(bcd_pins[1], LOW);
 	 digitalWrite(bcd_pins[2], LOW);  digitalWrite(bcd_pins[3], LOW);
 	 break;
  
case 2:
  digitalWrite(bcd_pins[0], LOW);  digitalWrite(bcd_pins[1], HIGH);
  digitalWrite(bcd_pins[2], LOW);  digitalWrite(bcd_pins[3], LOW);
  break;
 
case 3:
 digitalWrite(bcd_pins[0], HIGH);   digitalWrite(bcd_pins[1], HIGH);
  	digitalWrite(bcd_pins[2], LOW);  digitalWrite(bcd_pins[3], LOW);
  	break;
  
case 4:
  	digitalWrite(bcd_pins[0], LOW);  digitalWrite(bcd_pins[1], LOW);
 	 digitalWrite(bcd_pins[2], HIGH);  digitalWrite(bcd_pins[3], LOW);
 	 break;
 
 case 5:
 	 digitalWrite(bcd_pins[0], HIGH);  digitalWrite(bcd_pins[1], LOW);
 	 digitalWrite(bcd_pins[2], HIGH);  digitalWrite(bcd_pins[3], LOW);
 	 break;
  
case 6:
  	digitalWrite(bcd_pins[0], LOW);  digitalWrite(bcd_pins[1], HIGH);
  	digitalWrite(bcd_pins[2], HIGH);  digitalWrite(bcd_pins[3], LOW);
  	break;
  
case 7:
 	 digitalWrite(bcd_pins[0], HIGH);  digitalWrite(bcd_pins[1], HIGH);
 	 digitalWrite(bcd_pins[2], HIGH);  digitalWrite(bcd_pins[3], LOW);
 	 break;
 
 case 8:
  	digitalWrite(bcd_pins[0], LOW);  digitalWrite(bcd_pins[1], LOW);
  	digitalWrite(bcd_pins[2], LOW);  digitalWrite(bcd_pins[3], HIGH);
  	break;
  
case 9:
 	 digitalWrite(bcd_pins[0], HIGH);  digitalWrite(bcd_pins[1], LOW);
 	 digitalWrite(bcd_pins[2], LOW);  digitalWrite(bcd_pins[3], HIGH);
 	 break;
  	default:
  	digitalWrite(bcd_pins[0], LOW);  digitalWrite(bcd_pins[1], LOW);
  	digitalWrite(bcd_pins[2], LOW);  digitalWrite(bcd_pins[3], LOW);
  	break;
 	}}
void setup() {
 	pinMode(8, OUTPUT); 
 	pinMode(9, OUTPUT);
 	pinMode(10, OUTPUT);
 	pinMode(11, OUTPUT);
 	bcd_control_pins(11,10,9,8);
}
void loop() {
 	int i=0;
 	for(i = 9; i>=0; i--) {
  	displaydigit(i);
  	delay(1000);
 	}
 	for(i = 0; i<=9; i++) {
  	displaydigit(i);
  	delay(1000);
 	}
}
