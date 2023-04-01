#ifndef ADCANALOG_H
#define ADCANALOG_H
#include "settings.h"
#include "sensor/Sensor.h"
#include "sensor/Adc.h"
#include "SPI.h"

class AdcAnalog: public Sensor<uint16_t*> {
  public:
  /**
   * @brief Construct a new Adc Sensor Object
   */
  AdcAnalog(Adc** , uint8_t);

  /**
   * @brief Read all voltages from the adc
   */
  void read();

  /**
   * @brief Read all voltages from the adc
   */
  uint16_t* getValue() override;

  private:
  Adc** adcs;
  uint8_t numAdcs;
  uint16_t adcValues[ADCChannels * NUM_ADCS];         // Last read character
  arduino::SPISettings spiSettings;
};

#endif