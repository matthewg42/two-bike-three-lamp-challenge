#include <Arduino.h>
#include "PlayerLamps.h"
#include "Settings.h"


PlayerLamps::PlayerLamps(const uint8_t lampPins[LampCount])
{
    for (uint8_t i = 0; i < LampCount; ++i) {
        _pins[i] = lampPins[i];
    }
}

void PlayerLamps::begin()
{
    for (uint8_t i = 0; i < LampCount; ++i) {
        pinMode(_pins[i], OUTPUT);
        setLamp(i, false);
    }
}

void PlayerLamps::setBar(uint8_t count)
{
    for (uint8_t i=0; i < LampCount; ++i) {
        setLamp(i, i < count ? true : false);
    }
}

void PlayerLamps::setLamp(uint8_t lampIdx, bool on)
{
    digitalWrite(_pins[lampIdx], InvertLampLogic.get() ? !on : on);
}

