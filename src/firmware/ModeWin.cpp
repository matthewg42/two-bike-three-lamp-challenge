#include <MutilaDebug.h>
#include <Millis.h>
#include "Settings.h"
#include "Config.h"
#include "Modes.h"
#include "ModeReset.h"
#include "ModeWin.h"
#include "GameState.h"
#include "P1Lamps.h"
#include "P2Lamps.h"

ModeWinClass ModeWin;

ModeWinClass::ModeWinClass()
{
}

void ModeWinClass::modeStart()
{
    _modeStartMs = Millis();
    _p1Win = GameState.P1Energy >= WinningWattSeconds.get();
    _p2Win = GameState.P2Energy >= WinningWattSeconds.get();
    _flash = true;
    _lastDisplayMs = Millis();
}

void ModeWinClass::updateLamps()
{
    bool p = PrintState.get();
    if (p) { Serial.print("ModeWin: "); }
    if (_p1Win && _flash) {
        P1Lamps.setBar(LampCount);
        if (p) { Serial.print(F("P1[***]   ")); }
    } else {
        P1Lamps.setBar(0);
        if (p) { Serial.print(F("P1[   ]   ")); }
    }
    if (_p2Win && _flash) {
        P2Lamps.setBar(LampCount);
        if (p) { Serial.println(F("P2[***]")); }
    } else {
        P2Lamps.setBar(0);
        if (p) { Serial.println(F("P2[   ]")); }
    }
}

void ModeWinClass::modeUpdate()
{
    if (DoEvery(WinModeFlashMs.get(), _lastDisplayMs)) {
        _flash = !_flash;
        updateLamps();   
    }

    if (DoEvery(WinModeDuration.get() * 1000, _modeStartMs)) {
        Modes.switchMode(&ModeReset);
    }
}

