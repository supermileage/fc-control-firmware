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
  {4.33, 0},    // cell 19
  {4.33, 0}     // cell 20
};

SerialInput* serialInput = new SerialInput();

Voltage* voltage = new Voltage(1, 1);
MultiVoltage* multiVoltage = new MultiVoltage(voltageSettings);

MillisTimer* millisTimer = new MillisTimer();

Blink* blink0 = new Blink(SWITCHED_POWER_0, 3000, 0, millisTimer);
Blink* blink1 = new Blink(BIG_PIMP, 3000, 1000, millisTimer);
Blink* blink2 = new Blink(LIL_PUMP, 3000, 2000, millisTimer);
SerialEcho<char>* serialMonitor = new SerialEcho<char>(serialInput);
SerialEcho<float>* serialVoltage = new SerialEcho<float>(voltage);
SerialEcho<float*>* serialMultiVoltage = new SerialEcho<float*>(multiVoltage);

Readable* readables[] = {
  //voltage,
  multiVoltage,
  serialInput
};
Dependable* dependables[] = {
  millisTimer
};
Output* outputs[] = {
  serialMonitor,
  //serialVoltage,
  serialMultiVoltage,
  blink0,
  blink1,
  blink2
};

#endif