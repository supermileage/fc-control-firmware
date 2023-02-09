#ifndef SERIALECHO_H
#define SERIALECHO_H
#include "settings.h"
#include "output/Output.h"
#include "sensor/SerialInput.h"

class SerialEcho: public Output {
public:
  /**
   * @brief Construct a new SerialEcho device with a Uart object
   * and a serial in to echo
   * 
   */
  SerialEcho(SerialInput*);

  /**
   * @brief Refresh output
   */
  void refresh();
  
private:
  SerialInput *serialInput;
};

#endif