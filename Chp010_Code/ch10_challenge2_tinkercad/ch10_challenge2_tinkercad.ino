void setup() {
pinMode(A5, INPUT); 
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
Serial.begin(9600);
}
void loop() {
  int x = analogRead(A5);
  int y=map(x,0,1023,0,10);
  for (int i=10; i>y; i--)
  {
    digitalWrite(i+3,LOW);
  }
  for (int i=0; i<y; i++)
  {
    digitalWrite(i+4,HIGH);
  }
  delay(5);
}
