int ledPin = 13; 
int receivedNumber;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    receivedNumber = Serial.parseInt();

    switch (receivedNumber) {
      case 1:
        for (int i = 0; i < 1; i++) {
          digitalWrite(ledPin, HIGH);
          delay(500);
          digitalWrite(ledPin, LOW);
          delay(500);
        }
        break;

      case 2:
        for (int i = 0; i < 2; i++) {
          digitalWrite(ledPin, HIGH);
          delay(500);
          digitalWrite(ledPin, LOW);
          delay(500);
        }
        break;

      case 3:
        for (int i = 0; i < 3; i++) {
          digitalWrite(ledPin, HIGH);
          delay(500);
          digitalWrite(ledPin, LOW);
          delay(500);
        }
        break;

      case 4:
        for (int i = 0; i < 4; i++) {
          digitalWrite(ledPin, HIGH);
          delay(500);
          digitalWrite(ledPin, LOW);
          delay(500);
        }
        break;

      default:
        Serial.println("Enter 1, 2, 3, or 4");
        break;
    }
  }
}
