Three Lamp Pedal Power Challenge Firmware
=========================================

This is the firmware for Re-innovation Three Lamp Pedal Power Challenge project. The project is the implementation of a game with two static bicycles with pedal generators. As the players pedal, the generated energy runs the system which comprises three lamps per player, a control box with a resistive load, some rectifiers and other electronics and an Arduino Nano, which holds the game logic and state.

A fraction of rectified voltage from each pedal generator is fed into analog pins of the Arduino. From this the generated power is calculated. This power is accumulated to a total energy produced by each player since the start of the game.

The goal for the players is to be the first one to have accumulated `WinningWattSeconds` (a configurable setting). The three lamps for each player give some indication of progress toward that goal - the first lamp will illuminate when the energy level exceeds `WinningWattSeconds / 3`, the second lamp will also illuminate when the energy level exceeds `(2 * WinningWattSeconds) / 3`. When one of the players wins, all lamps are turned off, and then the winning player's lamps will be flashed for `WinModeDuration` second.

In the case that both players pass `WinningWattSeconds` at approximately the same time (in the same sampling period), the game is considered a draw, and both player's lamps are flashed.

Power Measurement
-----------------

Each player's generator output is rectified, and the resulting current passed through a resistive load. 

The load comprises a set of low-resistance power resistors with a tap somewhere. Logically this can be looked as as a potential divider, with two power resistors (RPowerTop * RPowerBottom) in series between the ground and rectified output of the generator, and the tap between them.

The tapped voltage is placed across a second potential divider (with high-value resistors, RTop and RBottom). The centre voltage of this second divider is measured by an analog pin of the Arduino.

The values of the various resistors are chosen such that the generator voltage of ~0-60V is converted to a voltage on the analog pin of the Arduino of 0-5V (conservatively set on the low end of this range to reduce the risk of damage to the Arduino from over-voltage should the generated voltage spike for any reason).

Settings
--------

Most settings used in the system are run-time configurable using a simple command line interface through the Arduino's serial port. The interface runs at 115200 baud.

