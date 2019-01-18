#pragma once

#include <stdint.h>

class GameStateClass {
public:
    GameStateClass() : P1Energy(0), P2Energy(0), LastActivity(0) {;}

    float P1Energy;
    float P2Energy;
    uint32_t LastActivity;
};

extern GameStateClass GameState;

