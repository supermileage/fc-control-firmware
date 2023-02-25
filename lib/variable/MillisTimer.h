#ifndef MILLISTIMER_H
#define MILLISTIMER_H
#include "settings.h"
#include "variable/Variable.h"

class MillisTimer: public Variable<unsigned long> {
  public:
  /**
   * @brief Construct a new Millisecond Timer object
   */
  MillisTimer();

  /**
   * @brief Re-read timer
   */
  void refresh();

  /**
   * @brief Get the last read time since start
   * 
   * @return The last read time since start
   */
  unsigned long getValue() override;


  private:
  unsigned long value;         // Last read character
};
#endif