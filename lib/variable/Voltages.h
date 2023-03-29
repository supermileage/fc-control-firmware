#ifndef VOLTAGES_H
#define VOLTAGES_H
#include "settings.h"
#include "variable/Variable.h"
#include "sensor/AdcAnalog.h"

class Voltages : public Variable<float*>{
public:
  /**
   * @brief Construct a new Voltages object
   */
  Voltages(AdcAnalog*, uint8_t, uint8_t);

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
  float voltages[ADCChannels * NUM_ADCS];         // Last read character
  AdcAnalog* adc;
  uint8_t numAdcs;
  uint8_t numVoltages;
};
  

#endif