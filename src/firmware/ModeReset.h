#pragma once

#include <Mode.h>

class ModeResetClass : public Mode {
public:
    ModeResetClass();
    void modeUpdate();

};

extern ModeResetClass ModeReset;

