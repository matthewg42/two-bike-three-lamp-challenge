#pragma once

#include "Config.h"

class PlayerLamps {
public:
    // Constructor
    PlayerLamps(const uint8_t lampPins[LampCount]);

    // Init (called from setup()) - sets pin modes
    void begin();

    // Turn on lamps like a bar chart... count is 0 .. LampCount
    // where 0 means "all off", 1 means just the first lamp on
    // up to LampCount which means all lamps on...
    // If count > LampCount, it acts like count == LampCount.
    void setBar(uint8_t count);

    // set a specific lamp on or off. lampIdx in range 0 .. LampCount-1, 
    // if lampIdx >= LampCount, do nothing.
    void setLamp(uint8_t lampNumer, bool on);

private:
    uint8_t _pins[LampCount];

};

