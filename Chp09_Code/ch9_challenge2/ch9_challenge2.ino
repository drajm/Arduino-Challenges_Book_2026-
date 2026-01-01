void setup()
{
Serial.begin(9600);
}
void loop()
{
int x = analogRead(A0);
Serial.print("Received Digital Value => ");
Serial.println(x);
delay(2000);
}
