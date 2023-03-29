#include "settings.h"
#include "output/StateToggle.h"
#include "output/Output.h"

/**
 * @brief Construct a new StateToggle device
 * 
 * @param stateController The state controller
 * @param states The states to toggle on in
 * @param numStates The number of states to toggle on in
 * @param pin The pin to toggle
 */
StateToggle::StateToggle(StateController* stateController, ControlState* states, uint8_t numStates, uint8_t pin, PinStatus initialState = LOW){
  this->stateController = stateController;
  this->states = states;
  this->numStates = numStates;
  this->pin = pin;
  pinMode(pin, OUTPUT);
  digitalWrite(pin, initialState);
}

/**
 * @brief Refreshes output state
 */
void StateToggle::refresh(){
  ControlState state = stateController->getValue();
  for(uint8_t i = 0; i < numStates; i++){
    if(state == states[i]){
      digitalWrite(pin, HIGH);
      return;
    }
  }
  digitalWrite(pin, LOW);
}