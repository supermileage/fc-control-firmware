#include "settings.h"
#include "variable/Voltages.h"

Voltages::Voltages(AdcAnalog* adc, uint8_t numAdcs, uint8_t numVoltages) {
  this->adc = adc;
  this->numAdcs = numAdcs;
  this->numVoltages = numVoltages;
}

void Voltages::refresh() {
  for (uint8_t i = 0; i < numVoltages; i++) {
    voltages[i] = (float)adc->getValue()[i] * 5 / 4096 * (5.3) * VOLTAGE_MULTIPLIER;
  }
}

float* Voltages::getValue() {
  return voltages;
}