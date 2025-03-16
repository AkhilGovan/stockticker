#pragma once

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTTYPE DHT22 

class DHT22Sensor {
  
  public:
    DHT22Sensor(int dhtPin) : pin(dhtPin), dht(dhtPin, DHTTYPE) {}

    void begin() {
      dht.begin();
    }

    void readAndPrint() {
      float humidity = dht.readHumidity();
      float temperature = dht.readTemperature();

      if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
      }

      Serial.print("Humidity: ");
      Serial.print(humidity);
      Serial.print(" %\t");
      Serial.print("Temperature: ");
      Serial.print(temperature);
      Serial.println(" °C");
    }

    private:
    int pin;
    DHT dht;

};

