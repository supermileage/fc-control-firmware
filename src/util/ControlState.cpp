#include "utils/ControlState.h"

const char * controlStateToString(ControlState state){
  return (const char *[]) {
    "init",
    "recover_init",
    "recover_main",
    "main",
    "fault"
  }[state];
}