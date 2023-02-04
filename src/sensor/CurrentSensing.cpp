#include "settings.h"
#include "sensor/CurrentSensing.h"

// define pins here



CurrentSensing::CurrentSensing(int pin) {
    this->sensorPin = pin;
    pinMode(sensorPin, INPUT);
}

float CurrentSensing::read() {
  int ADCres = 1023; //sensitivity
  float voltage = analogRead(sensorPin) * (5.0 / ADCres);
  if (voltage>0){
    value = voltage;
  }
  else{
    value = '\0';
  }

  return value;
}

float CurrentSensing::getValue(){
  return value;
}


