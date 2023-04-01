#ifndef CONTROLSTATE_H
#define CONTROLSTATE_H

typedef enum {
  INIT,
  RECOVER_INIT,
  RECOVER_MAIN,
  MAIN,
  FAULT
} ControlState;

/**
 * @brief Converts ControlState to string form
*/
const char * controlStateToString(ControlState);

#endif