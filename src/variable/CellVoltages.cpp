#include "settings.h"
#include "variable/CellVoltages.h"

CellVoltages::CellVoltages(Voltages* voltages) {
  this->voltages = voltages;
}

void CellVoltages::refresh() {
  for (int i = 0; i < FC_NUM_CELLS; ++i) {
    cellVoltages[i] = this->voltages->getValue()[i+1] - this->voltages->getValue()[i];
  }
}

float* CellVoltages::getValue() {
  return cellVoltages;
}