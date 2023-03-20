#include "sensor/Adc.h"
#include "settings.h"
#include "SPI.h"

Adc::Adc(uint8_t chipSelect) {
  this->CS = chipSelect;
}

void Adc::read() {
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE3));
  digitalWrite(this->CS, LOW);
  for (uint16_t i = 0; i < 1; i++) {
    uint16_t value = SPI.transfer16((i+1) << 3 << 8);
    this->adcValues[i] = (float)value;
    SERIAL.print(value);
    SERIAL.print(" ");
  }
  digitalWrite(this->CS, HIGH);
  SPI.endTransaction();

  SERIAL.println();
}

float* Adc::getValue() {
  return (float*)this->adcValues;
}