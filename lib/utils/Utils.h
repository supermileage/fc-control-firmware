#ifndef UTILS_H
#define UTILS_H
#include "settings.h"

class Utils {
  public:
    /**
     * @brief Read analog value from mux index
     */
    static uint16_t readMux(uint8_t);

    /**
     * @brief Setup mux pins
     */
    static void setupMux();
};

#endif