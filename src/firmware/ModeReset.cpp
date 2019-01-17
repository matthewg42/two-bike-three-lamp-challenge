#include <stdint.h>
#include <MutilaDebug.h>
#include <Millis.h>
#include "Modes.h"
#include "ModeReset.h"
#include "ModeRace.h"
#include "GameState.h"

ModeResetClass ModeReset;

ModeResetClass::ModeResetClass()
{
}

void ModeResetClass::modeUpdate()
{
    DBLN(F("Game Reset"));
    GameState.P1Energy = 0;
    GameState.P2Energy = 0;
    GameState.LastActivity = Millis();
    Modes.switchMode(&ModeRace);
}

