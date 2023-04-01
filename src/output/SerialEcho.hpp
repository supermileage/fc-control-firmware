#include "settings.h"
#include "sensor/SerialInput.h"
#include "output/Output.h"
#include "output/SerialEcho.h"

template <typename T>
SerialEcho<T>::SerialEcho(T* value, boolean isList = false, uint16_t listLen = 0) {
  this->value = value;
  this->isList = isList;
  this->listLen = listLen;
}

template <typename T>
void SerialEcho<T>::refresh() {
  if (isList) {
    for (uint16_t i = 0; i < listLen; i++) {
      SERIAL.print((T)(this->value[i]));
      SERIAL.print(" ");
    }
    SERIAL.println();
  } else {
    SERIAL.println((T)*(this->value));
  }
}

template <>
void SerialEcho<char*>::refresh() {
  if (this->isList) {
    SERIAL.println(*(this->value));
  } else {
    if (*(this->value) != '\0') {
      SERIAL.print(*(this->value));
    }
    SERIAL.println();
  }
}

template <>
void SerialEcho<const char*>::refresh() {
  if (this->isList) {
    SERIAL.println(*(this->value));
  } else {
    if (*(this->value) != '\0') {
      SERIAL.print(*(this->value));
    }
    SERIAL.println();
  }
}