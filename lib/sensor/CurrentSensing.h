#ifndef CURRENTSENSING_H
#define CURRENTSENSING_H
#include "settings.h"
#include "sensor/Sensor.h"


class CurrentSensing: public Sensor<float>{
    public:
     /**
     * @brief Construct a new current sensor object
     * 
     * @param sensorPin Pin to read from
     * 
     */

    CurrentSensing(int);

    float read() override;
    float getValue() override;

    private:
        int sensorPin;
        float value;

};


#endif