// Combined: LCD + Temperature Sensor
#include <Adafruit_LiquidCrystal.h>

// LCD setup
Adafruit_LiquidCrystal lcd(0);  // using I2C address 0

// Temperature sensor setup
int tempPin = A1;  // analog pin A1
float temp = 0;

void setup() {
  // LCD init
  lcd.begin(16, 2);
  lcd.print("Digital Thermo");

  // Serial init
  Serial.begin(9600);
}

void loop() {
  // Read sensor
  temp = analogRead(tempPin);
  temp = temp * 0.48828125;   // convert to Celsius (approx)

  // Print to Serial
  Serial.print("TEMPERATURE = ");
  Serial.print(temp);
  Serial.println(" *C");

  // Print to LCD
  lcd.setCursor(0, 1);       // second line
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print((char)223);      // degree symbol
  lcd.print("C   ");         // clear trailing digits if shorter

  // Blink backlight to indicate refresh
  lcd.setBacklight(1);
  delay(500);
  lcd.setBacklight(0);
  delay(500);
}
