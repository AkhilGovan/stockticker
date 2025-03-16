#include "ledDisplay.h"

// Global display object
MatrixPanel_I2S_DMA *matrix;

void initLEDDisplay() {
    HUB75_I2S_CFG mxconfig(
        PANEL_WIDTH, PANEL_HEIGHT, PANEL_CHAIN
    );

    matrix = new MatrixPanel_I2S_DMA(mxconfig);
    
    if (!matrix->begin()) {
        Serial.println("Matrix initialization failed!");
        return;
    }

    matrix->fillScreen(matrix->color565(0, 0, 0));  // Clear screen
}

void displayText(const char *text, int x, int y, uint16_t color) {
    matrix->fillScreen(matrix->color565(0, 0, 0));  // Clear previous text
    matrix->setCursor(x, y);
    matrix->setTextColor(color);
    matrix->print(text);
}