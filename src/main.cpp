#include "settings.h"
#include "sensor/SerialInput.h"
#include "sensor/Sensor.h"

Sensor<char>* serialInput;

void setup(){
  SERIAL.begin(SERIAL_BAUD_RATE);
  serialInput = new SerialInput(&Serial);
}

void loop(){
  serialInput->read();
  if (serialInput->getValue() != '\0')
    Serial.print(serialInput->getValue());
}