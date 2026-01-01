#define BPI1 2
#define BPI2 3
 volatile int state = LOW;
 volatile int BSI1 = 0;
 volatile int BSI2 = 0;
void setup() {
  Serial.begin(9600);  
  pinMode(BPI1, INPUT);
  pinMode(BPI2, INPUT);
  attachInterrupt(0, KEY_1, CHANGE);  
  attachInterrupt(1, KEY_2, CHANGE);
}
void loop() {
  Serial.println("NORMAL MODE");
  delay(100);
 }
void KEY_1(){ 
 BSI1 = digitalRead(BPI1);
 if (BSI1== HIGH){
  Serial.println("KEY 1:A");
  }  
  delay(10);
  }
void KEY_2(){ 
 BSI2 = digitalRead(BPI2);
 if (BSI2== HIGH){
  Serial.println("KEY 2:B");
  }  
delay(10);  }
