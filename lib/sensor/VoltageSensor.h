include "settings.h"
include "sensor/Sensor.h"

class VoltageSensor : public Sensor<double>{

public:
/**
 * @brief Construct a new Voltage Sensor Object
 * 
 * @param id sensor id tag
 * @param muxIndex number from 0-31 indicating the mux output this sensor is associated with
*/
VoltageSensor(int,int);

/**
* @brief read and return the cell voltage
* 
* @return the voltage of the associated cell
*/
double read() override;

/**
* @brief get the most recent voltage reading
* 
* @return the most recent voltage reading from the cell
*/
double getValue() override;

private:
    double value;
    int id;
    int muxIndex;
};

#endif