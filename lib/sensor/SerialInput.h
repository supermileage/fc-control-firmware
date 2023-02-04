#ifndef SERIALINPUT_H
#define SERIALINPUT_H
#include "settings.h"
#include "sensor/Sensor.h"

class SerialInput: public Sensor<char> {
    public:
    /**
     * @brief Construct a new Serial Input sensor object
     * 
     * @param serial Pointer to the Serial object to read from
     */
    SerialInput(UartClass*);

    /**
     * @brief Read and return one character from the serial port if available,
     * otherwise return '\0'
     * 
     * @return The character read from the serial port, or '\0' if no character
     */
    char read() override;

    /**
     * @brief Get the last read character from the serial port
     * 
     * @return The last read character from the serial port
     */
    char getValue() override;


    private:
    UartClass *serial;  // Pointer to the serial object to read from
    char value;         // Last read character
};


#endif