#ifndef OUTPUT_H
#define OUTPUT_H
#include "settings.h"
#include "sensor/SerialInput.h"

class Output {
public:
  /**
   * @brief Refresh output
   */
  virtual void refresh();
};

#endif