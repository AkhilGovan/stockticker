#pragma once

#include <Arduino.h>

class PushButton {
public:
  PushButton(uint8_t pin) : buttonPin(pin) {
    pinMode(buttonPin, INPUT_PULLUP);
  }

  bool isPressed() {
    return digitalRead(buttonPin) == LOW;
  }

  void whilePressed(void (*callback)()) {
    while (isPressed()) {
      callback();
    }
  }

private:
  uint8_t buttonPin;
};