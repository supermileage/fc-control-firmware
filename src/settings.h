#include "Arduino.h"
#include "fcp-common/fcp-common.h"

#define LED 13

#define SWITCHED_POWER_0 7
#define BIG_PIMP 8
#define LIL_PUMP 9

#define SERIAL_BAUD_RATE 9600
#define SERIAL Serial

#define ADCSelect0 3
#define ADCSelect1 4
#define ADCSelect2 5
#define ADCSelect3 6

#define MUX_OUT_1 A0
#define MUX_OUT_0 A1


/* Debugging */
#define DEBUG_SERIAL_EN 1

#if DEBUG_SERIAL_EN
#define DEBUG_SERIAL_LN(x) Serial.println(x)
#define DEBUG_SERIAL(x) Serial.print(x)
#else
#define DEBUG_SERIAL_LN(x) { }
#define DEBUG_SERIAL(x) { }
#endif