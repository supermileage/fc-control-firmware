#ifndef ADC_H
#define ADC_H
#include "settings.h"
#include "sensor/Sensor.h"
#include "SPI.h"

#define ADCBits 12
#define ADCChannels 8

class Adc: public Sensor<float*> {
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
  float* getValue() override;

  private:
  float adcValues[ADCChannels];         // Last read character
  uint8_t CS;
  arduino::SPISettings spiSettings;
};

#endif