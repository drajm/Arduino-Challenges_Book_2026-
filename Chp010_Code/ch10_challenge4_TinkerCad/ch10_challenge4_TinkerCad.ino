#include <Keypad.h>

const int ROW_NUM = 4;     // 4 rows
const int COLUMN_NUM = 4;  // 3 columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pin_rows[ROW_NUM] = {9, 8, 7, 6};        // Row pinouts of the keypad
byte pin_columns[COLUMN_NUM] = {5, 4, 3, 2};     // Column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_columns, ROW_NUM, COLUMN_NUM);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    Serial.println(key);   // Print pressed key
  }
}
