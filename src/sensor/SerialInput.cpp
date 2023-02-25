#include "settings.h"
#include "sensor/SerialInput.h"

SerialInput::SerialInput() {
}

void SerialInput::read() {
  if (SERIAL.available() > 0) {
    value = SERIAL.read();
  } else {
    value = '\0';
  }
}

char SerialInput::getValue() {
  return value;
}