#ifndef SENSOR_H
#define SENSOR_H
#include "settings.h"
#include "sensor/Readable.h"

template <typename T>
class Sensor : public Readable {
public:
  /**
   * @brief Read from sensor, and value
   * 
   * @return The value read from the sensor 
   */
  void read();

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