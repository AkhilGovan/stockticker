#include <Arduino.h>
#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#include "ledDisplay.h"
#define PANEL_WIDTH 64
#define PANEL_HEIGHT 32
#define PANEL_CHAIN 1


void setup() {
  Serial.begin(115200);
  delay(1000);

  HUB75_I2S_CFG mxconfig(PANEL_WIDTH, PANEL_HEIGHT, PANEL_CHAIN);
  mxconfig.gpio.e = -1; // No E line
  mxconfig.double_buff = false; // Simplify for testing

  matrix = new MatrixPanel_I2S_DMA(mxconfig);
  if (!matrix->begin()) {
    Serial.println("Matrix init failed!");
    return;
  }
  int centerX = 64 / 2;  // 32
int centerY = 32 / 2;  // 16
int radius = 10;
  Serial.println("Matrix initialized");
  matrix->setBrightness8(5);
  matrix->fillScreen(matrix->color565(255, 0, 0));
}

void loop() {
  // matrix->fillScreen(matrix->color565(255, 0, 0));  // Red background
  matrix->setTextSize(1);
  matrix->setTextColor(matrix->color565(10, 0, 0));  // Black

  int centerX = (64 - 6) / 2;
  int centerY = (32 - 8) / 2;
  matrix->setCursor(centerX, centerY);
  matrix->print("C");

  delay(10000); // hold for 10s
}
