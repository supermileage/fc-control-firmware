#include "settings.h"
#include "sensor/CurrentSensing.h"


CurrentSensing::CurrentSensing(uint8_t pin, float offset, float currentStep) {
    this->sensorPin = pin;
    this->offset = offset;
    this->currentStep = currentStep;
    pinMode(sensorPin, INPUT);
}

void CurrentSensing::read() {
  float ADCres = 1023.0; //sensitivity
  int raw = analogRead(sensorPin);
  value = ((float)((float)raw / ADCres) - offset) * currentStep;
  //SERIAL.println(raw/ADCres);
}

float CurrentSensing::getValue(){
  return value;
}

float* CurrentSensing::getValuePointer(){
  return &value;
}
