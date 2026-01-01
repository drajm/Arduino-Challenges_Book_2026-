void setup() {
  pinMode(13, OUTPUT);
}
void loop() {
  digitalWrite(13, HIGH);
  delay(5);  // Delay for 5 ms
  digitalWrite(13, LOW);
  delay(5);  // Delay for 5 ms
}
