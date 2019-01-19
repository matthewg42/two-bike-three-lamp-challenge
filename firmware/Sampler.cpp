#include "Sampler.h"
#include "Settings.h"
#include "StrUtil.h"
#include "Millis.h"

Sampler::Sampler(uint8_t player, uint8_t pin) :
    _player(player),
    _pin(pin),
    _sampler(NULL)
{
}

void Sampler::begin()
{
    if (_sampler != NULL) {
        delete _sampler;
    }

    _sampler = new EMAVDivSampler(_pin, 
            RBottom.get(),
            RTop.get(),
            VRef.get(),
            SampleIntervalMs.get(),
            DampingAlpha.get());

    _resNet = ((RPowerBottom.get() + RPowerTop.get()) / RPowerBottom.get()) * ((RTop.get() + RBottom.get()) / RBottom.get());
    _resLoad = RPowerTop.get() + RPowerBottom.get();
    _sampler->begin();
    _lastPrint = 0;
}

void Sampler::update()
{
    if (_sampler) {
        _sampler->update();
    }
}

float diodeDrop(float Vin)
{
    if (Vin > DiodeDropZero.get()) {
        return DiodeDrop.get();
    } else {
        return 0;
    }   
}

float Sampler::averagePower()
{
    if (_sampler) {
        float Va = _sampler->averageVolts();
        float Vd = diodeDrop(Va);
        float VGen = (_resNet * Va) + Vd;
        float P = (VGen * VGen) / _resLoad;
        if (PrintPower.get() && DoEvery(PrintPowerMs.get(), _lastPrint)) {
            Serial.print(F("Player "));
            Serial.print(_player);
            Serial.print(F(" Va="));
            Serial.print(pad(String(Va, 3), 6));
            Serial.print(F(" VGen="));
            Serial.print(pad(String(VGen, 3), 7));
            Serial.print(F(" P="));
            Serial.println(String(P, 1));
        }
        return P;
    } else {
        return 0;
    }
}



