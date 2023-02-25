#ifndef VOLTAGE_H
#define VOLTAGE_H
#include "settings.h"
#include "sensor/Sensor.h"
#include "utils/Utils.h"

class Voltage : public Sensor<float>{

public:
/**
 * @brief Construct a new Voltage Sensor Object
 * 
 * @param id sensor id tag
 * @param muxIndex number from 0-31 indicating the mux output this sensor is associated with
*/
Voltage(uint8_t,uint8_t);

/**
* @brief read and return the cell voltage
* 
* @return the voltage of the associated cell
*/
void read() override;

/**
* @brief get the most recent voltage reading
* 
* @return the most recent voltage reading from the cell
*/
float getValue() override;

/**
* @brief get the ID of the voltage sensor
* 
* @return the ID of the voltage sensor
*/
uint8_t getId();

private:
    uint8_t id;
    uint8_t muxIndex;
};

#endif