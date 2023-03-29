#ifndef CELLVOLTAGES_H
#define CELLVOLTAGES_H
#include "settings.h"
#include "variable/Variable.h"
#include "variable/Voltages.h"
#include "sensor/AdcAnalog.h"

class CellVoltages : public Variable<float*>{
public:
  /**
   * @brief Construct a new Voltages object
   */
  CellVoltages(Voltages*);

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
  float* getValue() override;

private:
  float cellVoltages[FC_NUM_CELLS];
  Voltages *voltages;
};
  

#endif