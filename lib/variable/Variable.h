#ifndef VARIABLE_H
#define VARIABLE_H
#include "settings.h"
#include "variable/Dependable.h"

template <typename T>
class Variable : public Dependable{
public:
  /**
   * @brief Read from sensor, and value
   * 
   * @return The value read from the sensor 
   */
  void refresh();

  /**
   * @brief Get the last read value of the sensor
   * 
   * @return The last read value of the sensor
   */
  virtual T getValue()=0;

private:
  T value;
};
  

#endif