#pragma once

#include <Arduino.h>
#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>

#define PANEL_WIDTH 64
#define PANEL_HEIGHT 32
#define PANEL_CHAIN 1

// wiring
#define R1  D_25
#define G1  D_26
#define B1  D_27
#define R2  D_14
#define G2  D_12
#define B2  D_13
#define A   D_23
#define B   D_19
#define C   D_5
#define D   D_17
#define E   D_16
#define CLK D_4
#define LAT D_15
#define OE  D_2

// Function to initialize the LED display
void initLEDDisplay();

// Function to display text
void displayText(const char *text, int x, int y, uint16_t color);