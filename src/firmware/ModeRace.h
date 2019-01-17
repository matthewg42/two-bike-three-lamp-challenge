#pragma once

#include <Mode.h>

class ModeRaceClass : public Mode {
public:
    ModeRaceClass();
    void modeStart();
    void modeStop();
    void modeUpdate();

};

extern ModeRaceClass ModeRace;

