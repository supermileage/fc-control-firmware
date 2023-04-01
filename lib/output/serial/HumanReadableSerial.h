#ifndef HUMANREADABALESERIAL_H
#define HUMANREADABALESERIAL_H
#include "settings.h"
#include "output/Output.h"
#include "sensor/SerialInput.h"
#include "variable/Voltages.h "
#include "sensor/CurrentSensing.h"
#include "variable/StateController.h"

class HumanReadableSerial: public Output {
public:
  /**
   * @brief Construct a new SerialEcho device with a Uart object
   * and a serial in to echo
   * 
   */
  HumanReadableSerial(Voltages*, CurrentSensing*, CurrentSensing*, StateController*);

  /**
   * @brief Refresh output
   */
  void refresh();
  
private:
  Voltages* voltages;
  CurrentSensing* motorCurrent;
  CurrentSensing* fcCurrent;
  StateController* state;
};

#endif