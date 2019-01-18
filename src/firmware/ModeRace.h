#pragma once

#include <Mode.h>

class ModeRaceClass : public Mode {
public:
    ModeRaceClass();
    void modeStart();
    void modeUpdate();

private:
    uint32_t _lastOut;

};

extern ModeRaceClass ModeRace;

