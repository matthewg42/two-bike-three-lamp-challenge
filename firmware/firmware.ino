/* NOTE: this sketch uses Mutila dev branch from 2019-01-17, which will
 * become release v1.1.4
 */

#include <Arduino.h>
#include <EEPROM.h>
#include <MutilaDebug.h>
#include <PersistentSetting.h>
#include "Settings.h"
#include "CLI.h"
#include "Config.h"
#include "Modes.h"
#include "ModeReset.h"
#include "ModeRace.h"
#include "ModeWin.h"
#include "P1Sampler.h"
#include "P2Sampler.h"
#include "P1Lamps.h"
#include "P2Lamps.h"

void setup()
{
    Serial.begin(115200);

    if (SettingSignature.get() != MagicNumber) {
        DBLN(F("New device for these settings, saving defaults."));
        factoryReset();
    } else {
        DBLN(F("Loaded settings from EEPROM."));
    }

    if (ExternalVRef.get()) {
        analogReference(EXTERNAL);
    } else {
        analogReference(INTERNAL);
    }

    P1Lamps.begin();
    P2Lamps.begin();

    P1Sampler.begin();
    P2Sampler.begin();

    CLI.begin(Serial);

    // Init mode objects
    ModeReset.begin();
    ModeRace.begin();
    ModeWin.begin();
    
    // Init mode manager & set poweron start mode
    Modes.begin(&ModeReset);
}

void loop()
{
    CLI.update();
    P1Sampler.update();
    P2Sampler.update();
    Modes.update();
}

