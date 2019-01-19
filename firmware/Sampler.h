#pragma once

#include <stdint.h>
#include <EMAVDivSampler.h>

class Sampler {
public:
    Sampler(uint8_t player, uint8_t pin);
    void begin();
    void update();
    float averagePower();

private:
    uint8_t _player;
    uint8_t _pin;
    EMAVDivSampler* _sampler;
    float _resNet;
    float _resLoad;
    uint32_t _lastPrint;

};

