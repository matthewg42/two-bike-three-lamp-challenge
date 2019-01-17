Three Lamp Pedal Power Challenge Firmware
=========================================

This is the firmare for Re-innovation Three Lamp Pedal Power Challenge project. The project is the implementation of a game with two static bicycles with pedal generators. As the players pedal, the generated energy runs the system which comprises three lamps per player, a control box with a resistive load, some rectifiers and other electroncs and an Arduino Nano, which holds the game logic and state.

A fraction of rectified voltage from each pedal generator is fed into analog pins of the Arduino. From this the generated power is calculated. This power is accumulated to a total energy produced by each player since the start of the game.

The goal for the players is to be the first one to have accumulated `WinningWattSeconds` (a confirable setting). The three lamps for each player give some indication of progress toward that goal - the first lamp will illuminate when the energy level exceeds `WinningWattSeconds / 3`, the second lamp will also illuminate when the energy level exceeds `(2 * WinningWattSeconds) / 3`. When one of the players wins, all lamps are turned off, and then the winning player's lamps wil be flashed.

Game states
-----------

1. Reset mode
  * Reset energy levels
  * Turn all lamps off
  * Switch immediately to "Playing" mode

2. Playing mode
  * Periodically read voltages, calculate power for each player
    * If both players power is zero, switch to "Pause" mode
    * Else add `power(W) * period(s)` to energy total for each plater
  * Set state of lamps according to energy levels
  * If either player's accumulated exceeds `WinningWattSeconds`, switch to "Win" mode

3. Pause mode
  * Start timer
  * If timer exceeds `PauseModeDuration` setting, switch to "Reset" mode
  * Else read voltages. If either is > 0, switch back to Playing mode
  * Wait some period (e.g. 50 ms)
  * Loop back to "If timer"

4. Win mode
  * If player 1's accumulated energy exceeds `WinningWattSeconds`, they are a winner
  * If player 2's accumulated energy exceeds `WinningWattSeconds`, they are a winner
  * (it is possible for both players to be a winner (draw)
  * turn off lamps for non-winning player
  * for each winner, flash lamps (in sequence)
  * after `WinModeDuration` seconds

Power Measurement
-----------------

Each player's generator output is rectified, and the resulting current passed through a resistive load. 

The load comprises a set of low-resistance power resistors with a tap somewhere. Logically this can be looked as as a potential divider, with two power resitors in series between the ground and rectified output of the generator, and the tap between them.  The voltage at the tap is related to the voltage from the generator by the usual potential divider equation.

The tapped voltage is placed accross another potential divider, this time with high-value resistors. The centre voltage of this divider is measured by an analog pin of the Arduino.

The values of the various reistors are chosen such that the generator voltage of ~0-60V is converted to a voltage on the analog pin of the Arduino of 0-5V (consertively set on the low end of this range.



Settings
--------

While some values may be hard-coded in the firmware, various numeric values are stored in EEPROM, with their value being settable through a simple serial interface. The Arduino's serial interface shall be monitored for commands which can be used to query and set these.






