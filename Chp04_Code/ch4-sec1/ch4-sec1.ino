#define A 11
#define B 10
#define C 7
#define D 8
#define E 9
#define F 12
#define G 13
#define DP 6

int segments[] = {A, B, C, D, E, F, G, DP};

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(segments[i], OUTPUT);
    digitalWrite(segments[i], LOW); // Ensure all OFF initially
  }
}

void displayDigit(int num) {
  // Turn all segments OFF first
  for (int i = 0; i < 7; i++) {
    digitalWrite(segments[i], LOW);
  }

  switch (num) {
    case 0: digitalWrite(A,HIGH); digitalWrite(B,HIGH); digitalWrite(C,HIGH);
            digitalWrite(D,HIGH); digitalWrite(E,HIGH); digitalWrite(F,HIGH); break;
    case 1: digitalWrite(B,HIGH); digitalWrite(C,HIGH); break;
    case 2: digitalWrite(A,HIGH); digitalWrite(B,HIGH); digitalWrite(D,HIGH);
            digitalWrite(E,HIGH); digitalWrite(G,HIGH); break;
    case 3: digitalWrite(A,HIGH); digitalWrite(B,HIGH); digitalWrite(C,HIGH);
            digitalWrite(D,HIGH); digitalWrite(G,HIGH); break;
    case 4: digitalWrite(B,HIGH); digitalWrite(C,HIGH); digitalWrite(F,HIGH);
            digitalWrite(G,HIGH); break;
    case 5: digitalWrite(A,HIGH); digitalWrite(C,HIGH); digitalWrite(D,HIGH);
            digitalWrite(F,HIGH); digitalWrite(G,HIGH); break;
    case 6: digitalWrite(A,HIGH); digitalWrite(C,HIGH); digitalWrite(D,HIGH);
            digitalWrite(E,HIGH); digitalWrite(F,HIGH); digitalWrite(G,HIGH); break;
    case 7: digitalWrite(A,HIGH); digitalWrite(B,HIGH); digitalWrite(C,HIGH); break;
    case 8: for (int i = 0; i < 7; i++) digitalWrite(segments[i], HIGH); break;
    case 9: digitalWrite(A,HIGH); digitalWrite(B,HIGH); digitalWrite(C,HIGH);
            digitalWrite(D,HIGH); digitalWrite(F,HIGH); digitalWrite(G,HIGH); break;
  }
}

void loop() {
  for (int i = 0; i <= 9; i++) {
    displayDigit(i);
    delay(1000);
  }
}
