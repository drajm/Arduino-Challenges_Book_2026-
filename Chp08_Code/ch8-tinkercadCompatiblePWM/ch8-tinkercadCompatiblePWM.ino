#include <avr/interrupt.h>

volatile int timer = 0;   // must be volatile since it's modified in ISR
bool state = 0;

void setup() {
  pinMode(13, OUTPUT);

  // Reset Timer0
  TCCR0A = 0;
  TCCR0B = 0;
  TCNT0  = 0;

  // Set CTC mode (Clear Timer on Compare Match)
  TCCR0A = (1 << WGM01);

  // Compare value for 1 ms interrupt:
  // 16MHz / 64 prescaler = 250kHz (4 µs per tick)
  // 1 ms / 4 µs = 250 → OCR0A = 249
  OCR0A = 249;

  // Enable Timer0 compare interrupt
  TIMSK0 |= (1 << OCIE0A);

  // Set prescaler to 64 and start Timer0
  TCCR0B |= (1 << CS01) | (1 << CS00);

  // Enable global interrupts
  sei();
}

void loop() {
  // Toggle LED every 1000 ms
  if (timer >= 1000) {
    state = !state;
    digitalWrite(13, state);
    timer = 0;
  }
}

ISR(TIMER0_COMPA_vect) {
  timer++;
}
