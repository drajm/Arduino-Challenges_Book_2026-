// Project 20 - Creating a Digital Thermometer

#define DATA 6   // connect to pin 14 on the 74HC595
#define LATCH 8  // connect to pin 12 on the 74HC595
#define CLOCK 10 // connect to pin 11 on the 74HC595

int temp = 0;
float voltage = 0;
int sensor = 0;

int digits[] = {
  252, 96, 218, 242, 102, 182, 190, 224, 254, 246,  // 0–9
  238, 62, 156, 122, 158, 142                       // A–F (optional)
};

void setup() {
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);
}

void loop() {
  sensor = analogRead(A5);                 // read sensor value
  voltage = sensor * 0.48828125;           // convert to millivolts
  temp = int(voltage / 10.0);              // crude conversion to °C
  displayNumber(temp);
  delay(500);
}

void displayNumber(int n) {
  int left = 0;
  int right = 0;

  if (n < 10) {
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, digits[n]);
    shiftOut(DATA, CLOCK, LSBFIRST, digits[0]); // leading zero
    digitalWrite(LATCH, HIGH);
  } else if (n < 100) {
    right = n % 10;
    left = n / 10;
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, digits[right]);
    shiftOut(DATA, CLOCK, LSBFIRST, digits[left]);
    digitalWrite(LATCH, HIGH);
  }
}
