#pragma once

#include <stdint.h>
#include <Arduino.h>

// IO Pin setup
const uint8_t Player1VaPin          = A1;
const uint8_t Player2VaPin          = A0;
const uint8_t LampCount             = 3;
const uint8_t P1LampPin[LampCount]  = { 5,  6,  10 };
const uint8_t P2LampPin[LampCount]  = { 11, 12, 13 };

// Size of command buffer
const uint8_t MaxCmdLen             = 32;

