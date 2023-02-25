#include "settings.h"
#include "variable/MillisTimer.h"

MillisTimer::MillisTimer() {

}

void MillisTimer::refresh() {
  value = millis();
}

unsigned long MillisTimer::getValue() {
  return value;
}