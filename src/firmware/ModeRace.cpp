#include <stdint.h>
#include <MutilaDebug.h>
#include <Millis.h>
#include "Settings.h"
#include "Modes.h"
#include "ModeRace.h"
#include "ModeReset.h"
#include "GameState.h"
#include "P1Sampler.h"
#include "P2Sampler.h"
#include "StrUtil.h"

uint32_t lastOut = 0;

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
    float P1Pow = P1Sampler.averagePower();
    float P2Pow = P2Sampler.averagePower();

    GameState.P1Energy += (P1Pow * SampleIntervalMs.get() / 1000.0);
    GameState.P2Energy += (P2Pow * SampleIntervalMs.get() / 1000.0);

    if (DoEvery(1000, lastOut)) {
        DB(F("RACING ### Player 1: power="));
        DB(pad(String(P1Pow, 0) + " W", 9));
        DB(F(" energy="));
        DB(pad(String(GameState.P1Energy, 0) + " WS", 9));
        DB(F("     Player 2: power="));
        DB(pad(String(P2Pow, 0) + " W", 9));
        DB(F(" energy="));
        DBLN(pad(String(GameState.P2Energy, 0) + " WS", 9));
    }

    if (P1Pow > 0 || P2Pow > 0) {
        GameState.LastActivity = Millis();
    }

    if (MillisSince(GameState.LastActivity) > PauseModeDuration.get() * 1000) {
        Modes.switchMode(&ModeReset);
    }
}

