#include "settings.h"
#include "output/SerialEcho.h"
#include "sensor/SerialInput.h"
#include "output/Output.h"

SerialEcho::SerialEcho(SerialInput* serialIn) {
  this-> serialInput = serialIn;
}

void SerialEcho::refresh(){
  if (serialInput->getValue() != '\0') {
    SERIAL.print(serialInput->getValue());
  }
}