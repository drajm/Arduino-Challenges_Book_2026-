unsigned long time_m,time_u;
void setup()
{
 Serial.begin(9600);
}
void loop()
{
 Serial.print("Time: ");
 time_m = millis();
 time_u = micros();
 Serial.print(time_m);Serial.print('\t');
 Serial.println(time_u);
 delay(1000);
}
