#include "settings.h"
#include "sensor/SerialInput.h"
#include "output/Output.h"
#include "output/SerialEcho.h"

template <typename T>
SerialEcho<T>::SerialEcho(Sensor<T>* sensor) {
  this-> sensor = sensor;
}

template <typename T>
void SerialEcho<T>::refresh() {
  SERIAL.println((T)sensor->getValue());
}

template <>
void SerialEcho<char>::refresh() {
  if (sensor->getValue() != '\0') {
    SERIAL.print(sensor->getValue());
  }
}

// If type is array, assume array is for each cell
template <>
void SerialEcho<float*>::refresh() {
  for (int i = 0; i < 8; ++i) {
    SERIAL.print(sensor->getValue()[i]);
    SERIAL.print(" ");
  }
  SERIAL.println();
}