#include "queen.h"
#include "SPI.h"

void setup(){
  SPI.begin();
  SERIAL.begin(SERIAL_BAUD_RATE);
  // Set up outputs
  SERIAL.println("starting");
  
  pinMode(ADCSelect0, OUTPUT);
  pinMode(ADCSelect1, OUTPUT);
  pinMode(ADCSelect2, OUTPUT);
  pinMode(ADCSelect3, OUTPUT);
  digitalWrite(ADCSelect0, HIGH);
  digitalWrite(ADCSelect1, HIGH);
  digitalWrite(ADCSelect2, HIGH);
  digitalWrite(ADCSelect3, HIGH);

  pinMode(MISO, INPUT_PULLDOWN);
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
  delay(500);
}