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
    if (PrintState.get()) {
        Serial.println(F("ModeWin"));
    }
    _modeStartMs = Millis();
    _p1Win = GameState.P1Energy >= WinningWattSeconds.get();
    _p2Win = GameState.P2Energy >= WinningWattSeconds.get();
    _flash = true;
    updateLamps();
    _lastDisplayMs = Millis();
}

void ModeWinClass::updateLamps()
{
    bool p = PrintState.get();
    if (p) { 
        Serial.print(F("ModeWin: P1=")); 
        Serial.print(GameState.P1Energy, 3);
        Serial.print("Ws [");
    }

    if (_p1Win && _flash) {
        P1Lamps.setBar(LampCount);
        if (p) { Serial.print(F("***")); }
    } else {
        P1Lamps.setBar(0);
        if (p) { Serial.print(F("   ")); }
    }

    if (p) { 
        Serial.print(F("]   P2=")); 
        Serial.print(GameState.P2Energy, 3);
        Serial.print("Ws [");
    }

    if (_p2Win && _flash) {
        P2Lamps.setBar(LampCount);
        if (p) { Serial.print(F("***")); }
    } else {
        P2Lamps.setBar(0);
        if (p) { Serial.print(F("   ")); }
    }

    if (p) { 
        Serial.println(']');
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

