#include <stdint.h>
#include <MutilaDebug.h>
#include <Millis.h>
#include "Settings.h"
#include "Modes.h"
#include "ModeRace.h"
#include "ModeReset.h"
#include "GameState.h"

ModeRaceClass ModeRace;

ModeRaceClass::ModeRaceClass()
{
}

void ModeRaceClass::modeStart()
{
    setUpdatePeriod(SampleIntervalMs.get());
}

void ModeRaceClass::modeStop()
{
}

void ModeRaceClass::modeUpdate()
{
    DBLN(F("Racing..."));
    GameState.P1Energy += 5;
    GameState.P2Energy += 5;

    //TODO: if (EITHERPLAYERACTIVE) {
    //    GameState.LastActivity = Millis();
    //}

    if (MillisSince(GameState.LastActivity) > PauseModeDuration.get() * 1000) {
        Modes.switchMode(&ModeReset);
    }
}

