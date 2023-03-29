#ifndef QUEEN_H
#define QUEEN_H

#include "settings.h"
#include "sensor/SerialInput.h"
#include "sensor/Sensor.h"
#include "sensor/Readable.h"
#include "output/Output.h"
#include "output/SerialEcho.h"
#include "variable/Variable.h"
#include "variable/Dependable.h"
#include "output/Blink.h"
#include "sensor/Voltage.h"
#include "sensor/MultiVoltage.h"
#include "sensor/Adc.h"
#include "sensor/AdcAnalog.h"
#include "variable/Voltages.h"
#include "variable/Minimum.h"
#include "variable/StateController.h"
#include "output/StateToggle.h"
#include "utils/ControlState.h"
#include "variable/CellVoltages.h"

float voltageSettings[FC_NUM_CELLS][2] = {
  {4.33, 0},    // cell 1
  {4.33, 0},    // cell 2
  {4.33, 0},    // cell 3
  {4.33, 0},    // cell 4
  {4.33, 0},    // cell 5
  {4.33, 0},    // cell 6
  {4.33, 0},    // cell 7
  {4.33, 0},    // cell 8
  {4.33, 0},    // cell 9
  {4.33, 0},    // cell 10
  {4.33, 0},    // cell 11
  {4.33, 0},    // cell 12
  {4.33, 0},    // cell 13
  {4.33, 0},    // cell 14
  {4.33, 0},    // cell 15
  {4.33, 0},    // cell 16
  {4.33, 0},    // cell 17
  {4.33, 0},    // cell 18
  {4.33, 0}    // cell 19
  // {4.33, 0}     // cell 20
};

// Inputs
SerialInput* serialInput = new SerialInput();
Adc *adcList[] = {
  new Adc(ADCSelect0),
  new Adc(ADCSelect1),
  new Adc(ADCSelect2),
  new Adc(ADCSelect3)
};
AdcAnalog* adcs = new AdcAnalog(adcList, NUM_ADCS);

// Variables
Voltages* voltages = new Voltages(adcs, NUM_ADCS, FC_NUM_CELLS + 1);
CellVoltages *cellVoltages = new CellVoltages(voltages);
MillisTimer* millisTimer = new MillisTimer();
Minimum* minimumVoltage = new Minimum(cellVoltages->getValue(), FC_NUM_CELLS);
StateController* stateController = new StateController(cellVoltages, FC_NUM_CELLS, millisTimer, minimumVoltage);

// Outputs
ControlState bigPumpOnStates[] = {ControlState::RECOVER_INIT, ControlState::RECOVER_MAIN};
ControlState lilPumpOnStates[] = {ControlState::INIT, ControlState::RECOVER_INIT, ControlState::MAIN, ControlState::RECOVER_MAIN};
ControlState faultOutputStates[] = {ControlState::FAULT};

StateToggle* bigPump = new StateToggle(stateController, bigPumpOnStates, sizeof(bigPumpOnStates) / sizeof(bigPumpOnStates[0]), BIG_PIMP, LOW);
StateToggle* lilPump = new StateToggle(stateController, lilPumpOnStates, sizeof(lilPumpOnStates) / sizeof(lilPumpOnStates[0]), LIL_PUMP, HIGH);
StateToggle* faultOutput = new StateToggle(stateController, faultOutputStates, sizeof(faultOutputStates) / sizeof(faultOutputStates[0]), SWITCHED_POWER_0, LOW);

SerialEcho<char>* serialMonitor = new SerialEcho<char>(&serialInput->value);
SerialEcho<float>* voltageSerialMonitor = new SerialEcho<float>(cellVoltages->getValue(), true, FC_NUM_CELLS);
SerialEcho<uint16_t>* adcSerialMonitor = new SerialEcho<uint16_t>(adcs->getValue(), true, ADCChannels * NUM_ADCS);

Readable* readables[] = {
  adcs
  //serialInput
};
Dependable* dependables[] = {
  voltages,
  cellVoltages,
  millisTimer,
  minimumVoltage,
  stateController
};
Output* outputs[] = {
  voltageSerialMonitor,
  bigPump,
  lilPump,
  faultOutput
};

#endif