include <TimerOne.h>
int ledState = LOW;
int ledPin = 12;
void setup() {
pinMode(ledPin, OUTPUT);
Timer1.initialize(1000000);
Timer1.attachInterrupt(blink);
}
void blink() {
ledState = !ledState;
digitalWrite(ledPin, ledState);
}
void loop() {
}
