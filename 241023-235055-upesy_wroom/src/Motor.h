#pragma once

class Motor {
  public:
    // Constructor: Initialize motor control pins
    Motor(int in1, int in2, int pwmPin) {
      this->in1 = in1;
      this->in2 = in2;
      this->pwmPin = pwmPin;
    }

    // Initialize motor pins
    void begin() {
      pinMode(in1, OUTPUT);
      pinMode(in2, OUTPUT);
      pinMode(pwmPin, OUTPUT);
      stop();  // Start with the motor stopped
    }

    // Run motor forward at a given speed (0-255)
    void forward(int speed) {
      speed = constrain(speed, 0, 255);  // Ensure speed is in range
      digitalWrite(in1, HIGH);           // Set direction forward
      digitalWrite(in2, LOW);
      analogWrite(pwmPin, speed);        // Set motor speed
    }

    // Run motor backward at a given speed (0-255)
    void backward(int speed) {
      speed = constrain(speed, 0, 255);
      digitalWrite(in1, LOW);            // Set direction backward
      digitalWrite(in2, HIGH);
      analogWrite(pwmPin, speed);
    }

    // Stop the motor
    void stop() {
      analogWrite(pwmPin, 0);            // Set speed to 0
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);            // Both LOW stops the motor
    }

  private:
    int in1, in2, pwmPin;  // Pins for motor control
};
