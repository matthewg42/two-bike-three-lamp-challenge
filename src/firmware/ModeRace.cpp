#include <stdint.h>
#include <MutilaDebug.h>
#include <Millis.h>
#include "Settings.h"
#include "Config.h"
#include "Modes.h"
#include "ModeRace.h"
#include "ModeReset.h"
#include "ModeWin.h"
#include "GameState.h"
#include "P1Sampler.h"
#include "P2Sampler.h"
#include "P1Lamps.h"
#include "P2Lamps.h"
#include "StrUtil.h"

ModeRaceClass ModeRace;

ModeRaceClass::ModeRaceClass()
{
}

void ModeRaceClass::modeStart()
{
    // force a debug output immediately
    setUpdatePeriod(SampleIntervalMs.get());
    _lastOut = 0;
}

void ModeRaceClass::modeUpdate()
{
    float P1Pow = P1Sampler.averagePower();
    float P2Pow = P2Sampler.averagePower();

    GameState.P1Energy += (P1Pow * SampleIntervalMs.get() / 1000.0);
    GameState.P2Energy += (P2Pow * SampleIntervalMs.get() / 1000.0);

    uint8_t P1LampCount = ((uint32_t)GameState.P1Energy * (uint32_t)LampCount) / (uint32_t)WinningWattSeconds.get();
    uint8_t P2LampCount = ((uint32_t)GameState.P2Energy * (uint32_t)LampCount) / (uint32_t)WinningWattSeconds.get();

    if (PrintState.get() && DoEvery(500, _lastOut)) {
        Serial.print(F("ModeRace: win="));
        Serial.print(WinningWattSeconds.get());
        Serial.print(F(" P1: power="));
        Serial.print(pad(String(P1Pow, 0) + "W", 9));
        Serial.print(F(" energy="));
        Serial.print(pad(String(GameState.P1Energy, 0) + "WS", 9));
        Serial.print(F(" lamps="));
        Serial.print(P1LampCount);
        Serial.print(F("     P2: power="));
        Serial.print(pad(String(P2Pow, 0) + "W", 9));
        Serial.print(F(" energy="));
        Serial.print(pad(String(GameState.P2Energy, 0) + "WS", 9));
        Serial.print(F(" lamps="));
        Serial.println(P2LampCount);
    }

    P1Lamps.setBar(P1LampCount);
    P2Lamps.setBar(P2LampCount);

    if (GameState.P1Energy >= WinningWattSeconds.get() || GameState.P2Energy >= WinningWattSeconds.get()) {
        Modes.switchMode(&ModeWin);
    }

    if (P1Pow > 0 || P2Pow > 0) {
        GameState.LastActivity = Millis();
    }

    if (MillisSince(GameState.LastActivity) > PauseModeDuration.get() * 1000) {
        Modes.switchMode(&ModeReset);
    }
}

