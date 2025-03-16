#include <Arduino.h>
#include "Motor.h"
#include "DHT22Sensor.h" 
#define MOTOR_PIN1 2 
#define MOTOR_PIN2 4 
#define HT22_PIN 15
#define MOTOR_PWM 15

Motor motor(MOTOR_PIN1, MOTOR_PIN2, MOTOR_PWM);
DHT22Sensor humidSensor(HT22_PIN);

void setup() {
  Serial.begin(115200);
  Serial.println("Motor control with PWM initialized.");
  motor.begin();
  humidSensor.begin();
}

void loop() {
  humidSensor.readAndPrint();
  motor.backward(255);
  delay(6000);
  motor.forward(255);
  delay(6000);
  // motor.forward(150);
  // motor.stop();
  // delay(2000);
  // motor.backward(50);
  Serial.println("Finished loop");
}
