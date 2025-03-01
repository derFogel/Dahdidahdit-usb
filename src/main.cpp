#include <Keyboard.h>
#include <string>

constexpr int PADDLE_DI D6;
constexpr int PADDLE_DAH D7;

template <int pin, char key> void interruptHandler() {
  attachInterrupt(
      digitalPinToInterrupt(pin),
      []() {
        // inverted logic, the pin is pulled high when not pressed
        // -> if high release key
        auto pressed = digitalRead(pin);
        if (pressed) {
          Keyboard.release(key);
        } else {
          Keyboard.press(key);
        }
      },
      CHANGE);
}

void setup() {
  Serial.begin(9600);
  pinMode(PADDLE_DAH, INPUT_PULLUP);
  pinMode(PADDLE_DI, INPUT_PULLUP);

  interruptHandler<PADDLE_DAH, 'a'>();
  interruptHandler<PADDLE_DI, 'b'>();
}

void loop() {}
