#ifndef READABLE_H
#define READABLE_H
#include "settings.h"

class Readable {
public:
  /**
   * @brief Read from sensor, and value
   */
  virtual void read()=0;
};


#endif