void setup() {
pinMode(13,OUTPUT);
}
void loop() {
digitalWrite(13,HIGH);
delayMicroseconds(400); //delay for 400 Microseconds
digitalWrite(13,LOW);    //delay for 1600 Microseconds
}
