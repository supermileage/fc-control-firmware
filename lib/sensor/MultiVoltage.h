#ifndef MULTIVOLTAGE_H
#define MULTIVOLTAGE_H
#include "settings.h"
#include "sensor/Sensor.h"

class MultiVoltage: public Sensor<float*> {
  public:
  /**
   * @brief Construct a new MultiVoltage Sensor Object
   */
  MultiVoltage(float[FC_NUM_CELLS][2]);

  /**
   * @brief Read all voltages from the multiplexer
   */
  void read();

  /**
   * @brief Get the last read character from the serial port
   * 
   * @return The last read character from the serial port
   */
  float* getValue() override;


  private:
  float voltageValues[FC_NUM_CELLS];         // Last read character
  float voltageSettings[2][FC_NUM_CELLS];   // Voltage settings -> multiplier and trim
};


#endif