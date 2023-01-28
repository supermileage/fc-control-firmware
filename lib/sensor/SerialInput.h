#ifndef SERIALINPUT_H
#define SERIALINPUT_H
#include "settings.h"
#include "sensor/Sensor.h"

class SerialInput: public Sensor<char> {
    // constructor
    public:
    SerialInput(UartClass*);
    char read() override;
    void init() override;
    char getValue() override;


    private:
    UartClass *serial;
    int baudRate;
    char value;
};


#endif