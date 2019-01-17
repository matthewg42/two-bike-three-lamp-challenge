#include <Arduino.h>
#include <EEPROM.h>
#include <MutilaDebug.h>
#include <PersistentSetting.h>
#include "Settings.h"
#include "CLI.h"
#include "Config.h"

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
}

void loop()
{
    CLI.update();
}

