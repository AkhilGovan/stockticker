#include <Arduino.h>
#include "ledDisplay.h"

void setup() {
    Serial.begin(115200);
    initLEDDisplay();
    displayText("Hello, ESP32!", 5, 10, 0xF800);
}

void loop() {
    static int x = 5;
    static int dir = 1;

    displayText("Mhyyhhyhyhy", x, 100, 0x07E0);

    x += dir;
    if (x > 50 || x < 5) dir = -dir;

    delay(100);
}
