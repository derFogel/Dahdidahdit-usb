#include <Keyboard.h>
#include <string>

constexpr int PADDLE_DI D6;
constexpr int PADDLE_DAH D7;

void setup() {
  Serial.begin(9600);
  pinMode(PADDLE_DAH, INPUT_PULLUP);
  pinMode(PADDLE_DI, INPUT_PULLUP);

  attachInterrupt(
      digitalPinToInterrupt(PADDLE_DAH),
      []() {
        auto dah = digitalRead(PADDLE_DAH);
        if (dah) {
          Keyboard.release('a');
        } else {
          Keyboard.press('a');
        }
      },
      CHANGE);

  attachInterrupt(
      digitalPinToInterrupt(PADDLE_DI),
      []() {
        auto dah = digitalRead(PADDLE_DI);
        if (dah) {
          Keyboard.release('b');
        } else {
          Keyboard.press('b');
        }
      },
      CHANGE);
}

void loop() {}
