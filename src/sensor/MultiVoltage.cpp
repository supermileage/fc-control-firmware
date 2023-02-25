#include "sensor/MultiVoltage.h"
#include "settings.h"
#include "utils/Utils.h"

MultiVoltage::MultiVoltage(float voltageSettings[FC_NUM_CELLS][2]) {
  for (uint8_t i = 0; i < FC_NUM_CELLS; i++) {
    voltageValues[i] = 0;
  }

  // Copy voltage settings
  for (int i = 0; i < FC_NUM_CELLS; i++) {
    for (int j = 0; j < 2; j++) {
      this->voltageSettings[i][j] = voltageSettings[i][j];
    }
  }
}

void MultiVoltage::read() {
  for (uint8_t i = 0; i < FC_NUM_CELLS; i++) {
    voltageValues[i] = Utils::readMux(i);
    /// 1023.0 * 5.0  // Convert to voltage
    /// voltageSettings[i][0] + voltageSettings[i][1];  // Apply multiplier and trim
  }
}

float* MultiVoltage::getValue() {
  return (float*)voltageValues;
}