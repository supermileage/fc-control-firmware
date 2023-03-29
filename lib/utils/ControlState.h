#ifndef CONTROLSTATE_H
#define CONTROLSTATE_H

typedef enum {
  INIT=0,
  RECOVER_INIT=1,
  RECOVER_MAIN=2,
  MAIN=3,
  FAULT=4
} ControlState;

#endif