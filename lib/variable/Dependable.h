#ifndef DEPENDANT_H
#define DEPENDANT_H
#include "settings.h"

class Dependable {
public:
  /**
   * @brief Refresh Dependable state
   */
  virtual void refresh()=0;
};


#endif