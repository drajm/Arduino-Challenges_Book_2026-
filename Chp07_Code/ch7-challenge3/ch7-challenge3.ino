void setup() {
  pinMode(3, OUTPUT);   // OC2B
  pinMode(11, OUTPUT);  // OC2A
}

void loop() {
  analogWrite(3, 128);   // ~50% duty cycle, ~490 Hz
  analogWrite(11, 64);   // ~25% duty cycle, ~490 Hz
}
