#ifndef STATETOGGLE_H
#define STATETOGGLE_H
#include "settings.h"
#include "output/Output.h"
#include "variable/StateController.h"
#include "utils/ControlState.h"

class StateToggle: public Output {
public:
  /**
   * @brief Construct a new StateToggle device
   * 
   */
  StateToggle(StateController*, ControlState*, uint8_t, uint8_t, PinStatus);

  /**
   * @brief Refresh output
   */
  void refresh();
  
private:
  ControlState* states;
  uint8_t numStates;
  StateController* stateController;
  uint8_t pin;
};

#endif