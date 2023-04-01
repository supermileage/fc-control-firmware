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

    CurrentSensing(uint8_t, float, float);

    void read() override;
    float getValue() override;
    float* getValuePointer();

    private:
        uint8_t sensorPin;
        float value;
        float offset;
        float currentStep; // dA/d(% voltage) 

};


#endif