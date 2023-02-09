#include "settings.h"
#include "sensor/SerialInput.h"
#include "sensor/Sensor.h"
#include "sensor/Readable.h"
#include "output/Output.h"
#include "output/SerialEcho.h"
#include "variable/Variable.h"
#include "variable/Dependable.h"
#include "output/Blink.h"

SerialInput* serialInput = new SerialInput();
SerialEcho* serialEcho = new SerialEcho(serialInput);
MillisTimer* millisTimer = new MillisTimer();
Blink* blink0 = new Blink(SWITCHED_POWER_0, 24000, 0, millisTimer);
Blink* blink1 = new Blink(BIG_PIMP, 24000, 8000, millisTimer);
Blink* blink2 = new Blink(LIL_PUMP, 24000, 16000, millisTimer);

Readable* readables[] = {
  serialInput
};
Dependable* dependables[] = {
  millisTimer
};
Output* outputs[] = {
  serialEcho,
  blink0,
  blink1,
  blink2
};

void setup(){
  SERIAL.begin(SERIAL_BAUD_RATE);
}

void loop(){
  // SERIAL.print("loop");
  // Read Readables
  for (int i = 0; i < sizeof(readables) / sizeof(readables[0]); ++i) {
    readables[i]->read();
  }

  // Set Vars
  for (int i = 0; i < sizeof(dependables) / sizeof(dependables[0]); ++i){
    dependables[i]->refresh();
  }
  // refresh outputs
  for (int i = 0; i < sizeof(outputs) / sizeof(outputs[0]); ++i) {
    outputs[i]->refresh();
  }
  delay(1);
}