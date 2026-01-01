void setup() {
  pinMode(13, OUTPUT);  //Select pin 13 as output
  pinMode(12, OUTPUT);  // Select pin 12 as output
  pinMode(11, OUTPUT);  // Select pin 11 as output
  pinMode(10, OUTPUT);  // Select pin 10 as output
  pinMode(9, OUTPUT);   // Select pin 9 as output
  pinMode(8, OUTPUT);   // Select pin 8 as output
  pinMode(7, OUTPUT);   // Select pin 7 as output
  pinMode(6, OUTPUT);   // Select pin 6 as output
}
void loop() {
  digitalWrite(13, LOW);   // Digital value “0” on pin 13
  digitalWrite(12, HIGH);  // Digital value “1” on pin 12
  digitalWrite(11, HIGH);  // Digital value “1” on pin 11
  digitalWrite(10, LOW);   // Digital value “0” on pin 10
  digitalWrite(9, LOW);    // Digital value “0” on pin 9
  digitalWrite(8, LOW);    // Digital value “0” on pin 8
  digitalWrite(7, LOW);    // Digital value “0” on pin 7
  digitalWrite(6, LOW);    // Digital value “0” on pin 6
}
