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

void setup()
{
    Serial.begin(115200);

    if (SettingSignature.get() != MagicNumber) {
        DBLN(F("New device for these settings, saving defaults."));
        factoryReset();
    } else {
        DBLN(F("Loaded settings from EEPROM."));
    }

    CLI.begin(Serial);

    ModeReset.begin();
    
    Modes.begin(&ModeReset);
}

void loop()
{
    CLI.update();
    Modes.update();
}

