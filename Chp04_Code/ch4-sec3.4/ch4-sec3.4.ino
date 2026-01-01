const int bit_clock_pin = 10;
const int digit_clock_pin = 9;
const int data_pin = 8;
const byte digit_pattern[16] =
{
B00111111, // 0
B00000110, // 1
B01011011, // 2
B01001111, // 3
B01100110, // 4
B01101101, // 5
B01111101, // 6
B00000111, // 7
B01111111, // 8
B01101111, // 9
B01110111, // A
B01111100, // b
B00111001, // C
B01011110, // d
B01111001, // E
B01110001  // F
};
unsigned int counter = 0;
void setup()
{
pinMode(data_pin, OUTPUT);
pinMode(bit_clock_pin, OUTPUT);
pinMode(digit_clock_pin, OUTPUT);
}
void update_one_digit(int data)
{
int i;
byte pattern;
pattern = digit_pattern[data];
digitalWrite(digit_clock_pin, LOW);
shiftOut(data_pin, bit_clock_pin, MSBFIRST, ~pattern);
digitalWrite(digit_clock_pin, HIGH);
}
void loop()
{
int i;
unsigned int digit_base;
counter++;
digit_base = 16;
update_one_digit(counter % digit_base);
delay(500);
}
