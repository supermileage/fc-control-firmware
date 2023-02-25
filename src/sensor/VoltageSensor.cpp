#include "settings.h"
#include "sensor/VoltageSensor.h"

VoltageSensor::VoltageSensor(int id, int muxIndex) : Sensor<double>{
    this->id = id;
    this->muxIndex = muxIndex;
    this->value = this->read();
}

VoltageSensor::read(){
    tempMuxIndex = muxIndex;
    digitalWrite(MUX_SEL_0, (tempMuxIndex) & 1);
    digitalWrite(MUX_SEL_1, ((tempMuxIndex) & 2) >> 1);
    digitalWrite(MUX_SEL_2, ((tempMuxIndex) & 4) >> 2);
    digitalWrite(MUX_SEL_3, ((tempMuxIndex) & 8) >> 3);

    if(muxIndex < 15){
        value = analogRead(MUX_OUT_0);
    }else{
        value = analogRead(MUX_OUT_1);
    }

    return value;
}

VoltageSensor::getValue(){
    return value;
}