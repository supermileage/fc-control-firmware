#include "sensor/AdcAnalog.h"
#include "settings.h"
#include "SPI.h"

AdcAnalog::AdcAnalog(Adc **adcs, uint8_t numAdcs) {
  this->adcs = adcs;
  this->numAdcs = numAdcs;
}

void AdcAnalog::read() {
  for (uint8_t i = 0; i < this->numAdcs; i++) {
    this->adcs[i]->read();
    for (uint16_t j = 0; j < ADCChannels; j++) {
      this->adcValues[i * ADCChannels + j] = this->adcs[i]->getValue()[j];
    }
  }
}

uint16_t* AdcAnalog::getValue() {
  return (uint16_t*)this->adcValues;
}