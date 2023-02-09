#include "settings.h"
#include "output/Blink.h"
#include "output/Output.h"
#include "variable/MillisTimer.h"

/**
 * @brief Construct a new Blink Object
 * 
 * @param pin: The digital pin to blink
 * @param delay: Time between toggles
 * @param offset: Offset from delay to blink
 * @param timer: MillisTimer object for time keeping
 */
Blink::Blink(uint8_t pin, uint8_t delay, uint8_t offset, MillisTimer* timer) {
  this->pin = pin;
  this->delay = delay;
  this->offset = offset;
  this->state = false;
  this->last_blunk = 0;
  this->timer = timer;
  pinMode(pin, OUTPUT);
}

/**
 * @brief Refreshes blink state, toggling state if needed
 */
void Blink::refresh(){
  if ((timer->getValue()-last_blunk > delay ) || (!last_blunk && (timer->getValue() > offset))) {
    state = !state;
    digitalWrite(pin, state);
    last_blunk = timer->getValue();
  }
}