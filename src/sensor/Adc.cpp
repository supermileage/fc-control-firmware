#include "sensor/Adc.h"
#include "settings.h"
#include "SPI.h"

Adc::Adc(uint8_t chipSelect) {
  this->CS = chipSelect;
}

void Adc::read() {
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE3));
  digitalWrite(this->CS, LOW);
  for (uint16_t i = 0; i < ADCChannels; i++) {
    uint16_t value = SPI.transfer16((i+1) << 3 << 8);
    this->adcValues[i] = (uint16_t)value;
  }
  digitalWrite(this->CS, HIGH);
  SPI.endTransaction();
}

uint16_t* Adc::getValue() {
  return (uint16_t*)this->adcValues;
}