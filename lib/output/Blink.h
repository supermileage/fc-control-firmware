#ifndef BLINK_H
#define BLINK_H
#include "settings.h"
#include "output/Output.h"
#include "variable/MillisTimer.h"

class Blink: public Output {
public:
  /**
   * @brief Construct a new Blink Object
   * 
   * @params: pin number, delay, offset, timer variable object
   */
  Blink(uint8_t, uint8_t, uint8_t, MillisTimer*);

  /**
   * @brief Refresh output
   */
  void refresh();
  
private:
  uint8_t pin;
  uint8_t delay;
  uint8_t offset;
  unsigned long last_blunk;
  boolean state;
  MillisTimer* timer;
};

#endif