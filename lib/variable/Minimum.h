#ifndef MINIMUM_FLOAT_H
#define MINIMUM_FLOAT_H
#include "settings.h"
#include "variable/Variable.h"

class Minimum : public Variable<float>{
public:
  /**
   * @brief Construct a new Voltages object
   */
  Minimum(float*, uint8_t);

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
  float getValue() override;

private:
  float *values;
  uint8_t numValues;
  float minimum;
};
  

#endif