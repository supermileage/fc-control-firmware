#ifndef STATECONTROLLER_H
#define STATECONTROLLER_H
#include "settings.h"
#include "variable/Variable.h"
#include "utils/ControlState.h"
#include "variable/Voltages.h"
#include "variable/MillisTimer.h"
#include "variable/Minimum.h"
#include "variable/CellVoltages.h"

class StateController : public Variable<ControlState>{
public:
  /**
   * @brief Construct a new ControlState object
   */
  StateController(CellVoltages*, uint8_t, MillisTimer*, Minimum*);

  /**
   * @brief Update Control State
   */
  void refresh();

  /**
   * @brief Get the last read value of the sensor
   * 
   * @return The last read value of the sensor
   */
  ControlState getValue() override;

  /**
   * @brief get the current state as a string
   * 
   * @return the current state as a string
  */
  const char** getString();

private:
  ControlState state;
  CellVoltages* voltages;
  MillisTimer* timer;
  uint8_t numVoltages;
  Minimum* minVoltage;
  const char* stateString;
};
  

#endif