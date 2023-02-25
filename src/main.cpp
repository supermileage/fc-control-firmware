#include "queen.h"

void setup(){
  SERIAL.begin(SERIAL_BAUD_RATE);
  Utils::setupMux();
  // Set up outputs
  SERIAL.println("starting");
  
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