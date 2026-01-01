int pin = 2;
volatile int state = LOW;

void setup() {
  pinMode(13, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(pin), blink, CHANGE);
}

void loop() {
  digitalWrite(13, state);
}

void blink() {
  state = !state;
}
