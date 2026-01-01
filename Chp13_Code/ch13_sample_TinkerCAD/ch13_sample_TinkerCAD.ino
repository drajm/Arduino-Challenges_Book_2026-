#include <Adafruit_LiquidCrystal.h>

// LCD
Adafruit_LiquidCrystal lcd(0);

// Motor A
int enA = 9;
int in1 = 8;
int in2 = 7;

// Motor B
int enB = 3;
int in3 = 5;
int in4 = 4;

// Buttons
int key1 = 1; // Button 1 pin
int key2 = 2; // Button 2 pin

// Motor speed
int motorSpeed = 200; // fixed speed for button control

void setup() {
  // LCD setup
  lcd.begin(16, 2);
  lcd.setBacklight(1);
  lcd.print("Robot Ready");

  // Motor pins
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Button pins
  pinMode(key1, INPUT_PULLUP);
  pinMode(key2, INPUT_PULLUP);

  delay(1000);
  lcd.clear();
}

// Motor control functions
void motor_stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void motor_both_cw() { // Both motors clockwise
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void motor_both_ccw() { // Both motors counterclockwise
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void motor_cw_ccw() { // Motor1 CW, Motor2 CCW
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void loop() {
  bool state1 = digitalRead(key1) == HIGH; // HIGH = pressed
  bool state2 = digitalRead(key2) == HIGH; // HIGH = pressed

  lcd.clear();

  if (!state1 && !state2) {           // Row 1
    motor_stop();
    lcd.print("Both motor stop");
  }
  else if (state1 && !state2) {       // Row 2
    motor_both_cw();
    analogWrite(enA, motorSpeed);
    analogWrite(enB, motorSpeed);
    lcd.print("Both Motor move CW");
  }
  else if (!state1 && state2) {       // Row 3
    motor_both_ccw();
    analogWrite(enA, motorSpeed);
    analogWrite(enB, motorSpeed);
    lcd.print("Both Motor move CCW");
  }
  else if (state1 && state2) {        // Row 4
    motor_cw_ccw();
    analogWrite(enA, motorSpeed);
    analogWrite(enB, motorSpeed);
    lcd.print("Motor1:CW Motor2:CCW");
  }

  delay(200); // debounce & LCD refresh
}
