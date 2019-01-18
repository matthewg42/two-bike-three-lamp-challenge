#include "Sampler.h"
#include "Settings.h"

Sampler::Sampler(uint8_t pin) :
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
        float VGen = (_resNet * Va) + diodeDrop(Va);
        return (VGen * VGen) / _resLoad;
    } else {
        return 0;
    }
}



