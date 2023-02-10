#include "settings.h"
#include "sensor/Voltage.h"

Voltage::Voltage(uint8_t id, uint8_t muxIndex) {
    this->id = id;
    this->muxIndex = muxIndex;
}

void Voltage::read(){
    value = Utils::readMux(muxIndex);
}

// Getters
float Voltage::getValue(){
    return (float)value / 1023 * 5 / 4.33 ;
}
uint8_t Voltage::getId() {
    return id;
}