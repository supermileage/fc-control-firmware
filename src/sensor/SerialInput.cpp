#include "settings.h"
#include "sensor/SerialInput.h"

SerialInput::SerialInput(UartClass *serial) : Sensor<char>() {
  this->serial = serial;
}

void SerialInput::init() {
  
}

char SerialInput::read() {
  if (serial->available() > 0) {
    value = serial->read();
  } else {
    value = '\0';
  }
  return value;
}

char SerialInput::getValue() {
  return value;
}