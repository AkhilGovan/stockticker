#include <Arduino.h>
#include "ledDisplay.h"
#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>

#define PANEL_WIDTH 64
#define PANEL_HEIGHT 32
#define PANEL_CHAIN 1

MatrixPanel_I2S_DMA *dma_display = nullptr;

void setup() {
  Serial.begin(115200);

  HUB75_I2S_CFG mxconfig(PANEL_WIDTH, PANEL_HEIGHT, PANEL_CHAIN);
  mxconfig.gpio.e = -1; 
  mxconfig.double_buff = true;

  dma_display = new MatrixPanel_I2S_DMA(mxconfig);
  dma_display->begin();

  dma_display->fillScreen(dma_display->color565(0, 0, 0));
  dma_display->setTextSize(1);
  dma_display->setCursor(5, 10);
  dma_display->setTextColor(dma_display->color565(255, 255, 0));
  dma_display->println("Hello P4!");
}

void loop() {
  // Optional animation
}
