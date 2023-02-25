#include "settings.h"
#include "utils/Utils.h"

/**
 * @brief Read analog value from mux
 * 
 * @param idx Mux index to read from
 */
uint16_t Utils::readMux(uint8_t idx) {
    digitalWrite(MUX_SEL_0, (idx) & 1);
    digitalWrite(MUX_SEL_1, ((idx) & 2) >> 1);
    digitalWrite(MUX_SEL_2, ((idx) & 4) >> 2);
    digitalWrite(MUX_SEL_3, ((idx) & 8) >> 3);

    delay(100);

    if(idx < 15){
        return analogRead(MUX_OUT_0);
    }else{
        return analogRead(MUX_OUT_1);
    }
}

/**
 * @brief Setup mux pins
 */
void Utils::setupMux() {
    pinMode(MUX_SEL_0, OUTPUT);
    pinMode(MUX_SEL_1, OUTPUT);
    pinMode(MUX_SEL_2, OUTPUT);
    pinMode(MUX_SEL_3, OUTPUT);

    pinMode(MUX_OUT_0, INPUT_PULLDOWN);
    pinMode(MUX_OUT_1, INPUT_PULLDOWN);
}
