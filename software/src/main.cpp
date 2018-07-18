#include <Arduino.h>
#include "max6675.h"
#include <SPI.h>
#include <TFT.h>

static const uint8_t THERMOCOUPLE_CS_PIN = 4;
static const uint8_t TFT_CS_PIN = 7;
static const uint8_t TFT_DC_PIN = 9;
static const uint8_t TFT_RST_PIN = 8;

TFT mTFTscreen = TFT(TFT_CS_PIN, TFT_DC_PIN, TFT_RST_PIN);
MAX6675 mThermocouple;
char displayBuf[4];

void setup() {
  SPI.begin();

  // Set up the display
  mTFTscreen.begin();
  mTFTscreen.setRotation(0);
  mTFTscreen.background(250, 16, 200);
  mTFTscreen.textSize(3);

  // Set up the thermocouple
  mThermocouple.begin(THERMOCOUPLE_CS_PIN);
  // wait for MAX chip to thermally stabilize
  delay(500);
}

void loop() {
  double temp = mThermocouple.readCelsius();

  // Clear off existing text first
  mTFTscreen.stroke(250, 16, 200);
  mTFTscreen.text(displayBuf, 5, 5);
  mTFTscreen.write(247); // degree symbol
  mTFTscreen.print("C"); 
  // Update text
  itoa(temp, displayBuf, 10);
  mTFTscreen.stroke(250, 250, 250);
  mTFTscreen.text(displayBuf, 5, 5);  
  mTFTscreen.write(247); // degree symbol
  mTFTscreen.print("C"); 

  delay(200);
}
