#ifndef SERIALINPUT_H
#define SERIALINPUT_H
#include "settings.h"
#include "sensor/Sensor.h"

class SerialInput: public Sensor<char> {
  public:
  /**
   * @brief Construct a new Serial Input sensor object
   */
  SerialInput();

  /**
   * @brief Read and return one character from the serial port if available,
   * otherwise return '\0'
   */
  void read();

  /**
   * @brief Get the last read character from the serial port
   * 
   * @return The last read character from the serial port
   */
  char getValue() override;


  private:
  char value;         // Last read character
};


#endif