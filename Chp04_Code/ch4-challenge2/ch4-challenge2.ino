// Challenge 2: Write a program that displays the numbers 1 through 8 
// on a seven-segment display.

int bcdPins[] = {3, 4, 5, 6};
int latchPin = 2;

byte bcdCode[10][4] = {
    {0, 0, 0, 0},

    {0, 0, 0, 1},
    {0, 0, 1, 0},
    {0, 0, 1, 1},
    {0, 1, 0, 0},
    {0, 1, 0, 1},
    {0, 1, 1, 0},
    {0, 1, 1, 1},
    {1, 0, 0, 0},
    {1, 0, 0, 1}
};

void displayDigit(int digit) {
    for (int i = 0; i < 4; i++) {
        digitalWrite(bcdPins[i], bcdCode[digit][i]);
    }
    digitalWrite(latchPin, HIGH);
    delay(10);
    digitalWrite(latchPin, LOW);
}

void setup() {
    for (int i = 0; i < 4; i++) {
        pinMode(bcdPins[i], OUTPUT);
    }
    pinMode(latchPin, OUTPUT);
    digitalWrite(latchPin, LOW);
}

void loop() {
    for (int n = 1; n <= 8; n++) {
        displayDigit(n);
        delay(1000);
    }
}
