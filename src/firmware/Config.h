#pragma once

#include <stdint.h>
#include <Arduino.h>

// IO Pin setup
const uint8_t Player1VaPin          = A1;
const uint8_t Player2VaPin          = A0;
const uint8_t P1LampPin[3]          = { 5,  6,  10 };
const uint8_t P2LampPin[3]          = { 11, 12, 13 };

// Size of command buffer
const uint8_t MaxCmdLen             = 32;

// Game params
/*
const float WinningWattSeconds      = 1000.0;   // typical values: 100-1000?
const uint8_t IdleResetSeconds      = 5;

// We account for the voltage drop from the rectifier diode with an on/off model
// If the input to the diode is less than DiodeModelVZero, we consider it off,
// and so it has no voltage drop, else there will be a drop of DiodeDropMax.
const float DiodeModelVZero         = 0.001;
const float DiodeDropMax            = 1.4;

// Load voltage divider values (same for both players)
const float RPowerTop               = 1.0;
const float RPowerBottom            = 3.0;
const float VRef                    = 3.3;
const uint16_t VSampleMs            = 50;
const float VSampleAlpha            = 0.95;

// Small voltage divider for analog pin (same for both players)
const float RTop                    = 470000.0;
const float RBottom                 = 10000.0;
*/
