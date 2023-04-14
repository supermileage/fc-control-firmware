#include "settings.h"
#include "output/serial/HumanReadableSerial.h"

HumanReadableSerial::HumanReadableSerial(CellVoltages* voltages, CurrentSensing* motorCurrent, CurrentSensing* fcCurrent, StateController* state){
  this->voltages = voltages;
  this->state = state;
  this->motorCurrent = motorCurrent;
  this->fcCurrent = fcCurrent;
}

void HumanReadableSerial::refresh(){
  String output = "";
  output += "--------------------------------------------";
  output += "\n";
  output += state->getFaultReason();
  output += "\n";
  output +="State: ";
  output += controlStateToString(state->getValue());
  output += "\n";
  output += "Motor Current: ";
  output += motorCurrent->getValue();
  output += "\t\tFC Current: ";
  output += fcCurrent->getValue();
  output += "\n";
  output += "Voltages: ";
  for (int i = 0; i < FC_NUM_CELLS; i++){
    output += voltages->getValue()[i];
    output += "\t";
  }
  Serial.println(output);
}