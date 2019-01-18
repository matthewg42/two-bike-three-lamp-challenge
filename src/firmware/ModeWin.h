#pragma once

#include <stdint.h>
#include <Mode.h>

class ModeWinClass : public Mode {
public:
    ModeWinClass();
    void modeStart();
    void modeUpdate();
    void updateLamps();

private:
    uint32_t _modeStartMs;
    uint32_t _lastDisplayMs;
    bool _p1Win;
    bool _p2Win;
    bool _flash;

};

extern ModeWinClass ModeWin;

