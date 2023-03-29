#include "settings.h"
#include "variable/Minimum.h"

Minimum::Minimum(float* values, uint8_t numValues) {
  this->values = values;
  this->numValues = numValues;
}

void Minimum::refresh() {
  float min = values[0];
  for (uint8_t i = 1; i < numValues; i++) {
    if (values[i] < min) {
      min = values[i];
    }
  }
  this->minimum = min;
}

float Minimum::getValue() {
  return minimum;
}