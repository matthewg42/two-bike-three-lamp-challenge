#include <stdint.h>
#include <MutilaDebug.h>
#include <Millis.h>
#include "Modes.h"
#include "ModeReset.h"
#include "ModeRace.h"
#include "GameState.h"
#include "Settings.h"

ModeResetClass ModeReset;

ModeResetClass::ModeResetClass()
{
    // we have to have a constructor
}

void ModeResetClass::modeUpdate()
{
    // Update is mandatory, we'll do our work here and immediately switch
    // to ModeRace
    if (PrintState.get()) {
        Serial.println(F("ModeReset"));
    }
    GameState.P1Energy = 0;
    GameState.P2Energy = 0;
    GameState.LastActivity = Millis();
    Modes.switchMode(&ModeRace);
}

