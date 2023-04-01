#ifndef ADC_H
#define ADC_H
#include "settings.h"
#include "sensor/Sensor.h"
#include "SPI.h"

class Adc: public Sensor<uint16_t*> {
  public:
  /**
   * @brief Construct a new Adc Sensor Object
   */
  Adc(uint8_t);

  /**
   * @brief Read all voltages from the adc
   */
  void read();

  /**
   * @brief Read all voltages from the adc
   */
  uint16_t* getValue() override;

  private:
  uint16_t adcValues[ADCChannels];         // Last read character
  uint8_t CS;
  arduino::SPISettings spiSettings;
};

#endif