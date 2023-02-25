#include "Arduino.h"

#define NUM_CELLS 20

#define LED 13

#define SERIAL_BAUD_RATE 9600
#define SERIAL Serial

#define MUX_SEL_0 7
#define MUX_SEL_1 8
#define MUX_SEL_2 9
#define MUX_SEL_3 10

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