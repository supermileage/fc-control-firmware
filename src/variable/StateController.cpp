#include "settings.h"
#include "variable/StateController.h"
#include "variable/Voltages.h"
#include "variable/MillisTimer.h"
#include "utils/ControlState.h"
#include "variable/Minimum.h"
#include "variable/CellVoltages.h"

StateController::StateController(CellVoltages* voltages, uint8_t numVoltages, MillisTimer* timer, Minimum* minVoltage) {
  this->voltages = voltages;
  this->timer = timer;
  this->numVoltages = numVoltages;
  this->minVoltage = minVoltage;
  this->state = ControlState::INIT;
}

void StateController::refresh() {
  switch(this->state) {
    case ControlState::INIT:
      if (this->timer->getValue() > INIT_TIME_LIMIT) {
        this->state = ControlState::RECOVER_INIT;
      } else if (this->minVoltage->getValue() > RECOVERY_VOLTAGE) {
        this->state = ControlState::MAIN;
      }
      break;
    case ControlState::RECOVER_INIT:
      if (this->minVoltage->getValue() > RECOVERY_VOLTAGE) {
        this->state = ControlState::MAIN;
      } else if (this->timer->getValue() > RECOVERY_TIME_LIMIT + INIT_TIME_LIMIT) {
        this->state = ControlState::FAULT;
      }
      break;
    case ControlState::MAIN:
      if (this->minVoltage->getValue() < RECOVERY_VOLTAGE) {
        this->state = ControlState::RECOVER_MAIN;
      }
      break;
    case ControlState::RECOVER_MAIN:
      if (this->minVoltage->getValue() > RECOVERY_VOLTAGE + EXIT_RECOVERY_DIFF) {
        this->state = ControlState::MAIN;
      } else if (this->minVoltage->getValue() < FAULT_VOLTAGE) {
        this->state = ControlState::FAULT;
      }
      break;
    default:
      this->state = this->state;
      break;
  }
  this->stateString = controlStateToString(state);
}

ControlState StateController::getValue() {
  return state;
}

const char** StateController::getString() {
  return &stateString;
}