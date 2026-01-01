void setup() {
  Serial.begin(4800);  // Enable serial monitor with 4800 exchange rate
}
void loop() {
  for (int i = 1; i <= 100; i++) {  // if conditional statement
    Serial.println(i);              // The value of the variable i is given in the serial monitor.
  }
}
