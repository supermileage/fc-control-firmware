#include "settings.h"
#include "variable/StateController.h"
#include "variable/Voltages.h"
#include "variable/MillisTimer.h"
#include "utils/ControlState.h"
#include "variable/Minimum.h"
#include "variable/CellVoltages.h"

StateController::StateController(CellVoltages* cellVoltages, Voltages* voltages, uint8_t numVoltages, MillisTimer* timer, Minimum* minVoltage) {
  this->cellVoltages = cellVoltages;
  this->voltages = voltages;
  this->timer = timer;
  this->numVoltages = numVoltages;
  this->minVoltage = minVoltage;
  this->state = ControlState::INIT;
  this->faultReason = "RUNNING";
}

void StateController::refresh() {
  switch(this->state) {
    case ControlState::INIT:
      if (this->timer->getValue() > INIT_TIME_LIMIT) {
        this->state = ControlState::RECOVER_INIT;
      }
      #ifndef STACK_STATE_CONTROL
      else if (this->minVoltage->getValue() > FAULT_VOLTAGE) {
        this->state = ControlState::MAIN;
      }
      #else
      else if (this->voltages->getValue()[numVoltages] > FAULT_VOLTAGE * numVoltages) {
        this->state = ControlState::MAIN;
      }
      #endif
      break;
    case ControlState::RECOVER_INIT:
      #ifndef STACK_STATE_CONTROL
      if (this->minVoltage->getValue() > FAULT_VOLTAGE) {
        this->state = ControlState::MAIN;
      }
      #else
      if (this->voltages->getValue()[numVoltages] > FAULT_VOLTAGE * numVoltages) {
        this->state = ControlState::MAIN;
      }
      #endif
      else if (this->timer->getValue() > RECOVERY_TIME_LIMIT + INIT_TIME_LIMIT) {
        this->faultReason = "INIT->TIMEOUT";
        this->state = ControlState::FAULT;
      }
      break;
    case ControlState::MAIN:
      #ifndef STACK_STATE_CONTROL
      if (this->minVoltage->getValue() < RECOVERY_VOLTAGE) {
        this->state = ControlState::RECOVER_MAIN;
      }
      #else
      if (this->voltages->getValue()[numVoltages] < RECOVERY_VOLTAGE * numVoltages) {
        this->state = ControlState::RECOVER_MAIN;
      }
      #endif
      #ifdef HIGH_VOLTAGE_FAULT
      // If stack voltage is higher than HIGH_FAULT_VOLTAGE, assume safety board fault
      else if (this->voltages->getValue()[numVoltages] > HIGH_FAULT_VOLTAGE) {
        this->faultReason = "MAIN->HIGH_VOLTAGE_FAULT";
        this->state = ControlState::FAULT;
      }
      #endif
      break;
    case ControlState::RECOVER_MAIN:
      #ifndef STACK_STATE_CONTROL
      if (this->minVoltage->getValue() > RECOVERY_VOLTAGE + EXIT_RECOVERY_DIFF) {
        this->state = ControlState::MAIN;
      } else if (this->minVoltage->getValue() < FAULT_VOLTAGE) {
        this->state = ControlState::FAULT;
        this->faultReason = "MAIN->FAULT_VOLTAGE";
      }
      #else
      if (this->voltages->getValue()[numVoltages] > RECOVERY_VOLTAGE * numVoltages + EXIT_RECOVERY_DIFF * numVoltages) {
        this->state = ControlState::MAIN;
      } else if (this->voltages->getValue()[numVoltages] < FAULT_VOLTAGE * numVoltages) {
        this->state = ControlState::FAULT;
        this->faultReason = "MAIN->FAULT_VOLTAGE";
      }
      #endif
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

char * StateController::getFaultReason() {
  return faultReason;
}