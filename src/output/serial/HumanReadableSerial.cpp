#include "settings.h"
#include "output/serial/HumanReadableSerial.h"

HumanReadableSerial::HumanReadableSerial(Voltages* voltages, CurrentSensing* motorCurrent, CurrentSensing* fcCurrent, StateController* state){
  this->voltages = voltages;
  this->state = state;
  this->motorCurrent = motorCurrent;
  this->fcCurrent = fcCurrent;
}

void HumanReadableSerial::refresh(){
  Serial.println("--------------------------------------------");
  Serial.print("State: ");
  Serial.println(controlStateToString(state->getValue()));
  Serial.print("Motor Current: ");
  Serial.print(motorCurrent->getValue());
  Serial.print("\t\tFC Current: ");
  Serial.println(fcCurrent->getValue());
  Serial.print("Voltages: ");
  for (int i = 0; i < FC_NUM_CELLS; i++){
    Serial.print(voltages->getValue()[i]);
    Serial.print(" ");
  }
  Serial.println("");
}