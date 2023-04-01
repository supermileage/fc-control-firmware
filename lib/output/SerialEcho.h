#ifndef SERIALECHO_H
#define SERIALECHO_H
#include "settings.h"
#include "output/Output.h"
#include "sensor/SerialInput.h"

template <typename T>
class SerialEcho: public Output {
public:
  /**
   * @brief Construct a new SerialEcho device with a Uart object
   * and a serial in to echo
   * 
   */
  SerialEcho(T*, boolean, uint16_t);

  /**
   * @brief Refresh output
   */
  void refresh();
  
private:
  T *value;
  boolean isList;
  uint16_t listLen;
};

#include "output/SerialEcho.hpp"

#endif