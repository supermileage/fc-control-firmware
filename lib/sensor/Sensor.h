#ifndef SENSOR_H
#define SENSOR_H
#include "settings.h"

template <typename T>
class Sensor {
  // constructor
public:
  virtual T read()=0;
  virtual void init()=0;
  virtual T getValue()=0;

private:
  T value;
};


#endif