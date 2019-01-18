#include <stdio.h>
#include "StrUtil.h"
#include "Settings.h"

// Game-wide persistent settings backed by EEPROM
//                                                      min    max      default  name
NamedPersistentSetting<uint16_t> WinningWattSeconds    (100,   10000,   1000,    "WinningWattSeconds");
NamedPersistentSetting<bool>     InvertLampLogic       (false, true,    true,    "InvertLampLogic");
NamedPersistentSetting<uint8_t>  PauseModeDuration     (0,     60,      5,       "PauseModeDuration");
NamedPersistentSetting<uint8_t>  WinModeDuration       (0,     60,      10,      "WinModeDuration");
NamedPersistentSetting<uint16_t> WinModeFlashMs        (10,    1000,    200,     "WinModeFlashMs");
NamedPersistentSetting<float>    RTop                  (1e-2,  1e12,    470000,   "RTop");
NamedPersistentSetting<float>    RBottom               (1e-2,  1e12,    10000,    "RBottom");
NamedPersistentSetting<float>    RPowerTop             (1e-2,  1e12,    1,        "RPowerTop");
NamedPersistentSetting<float>    RPowerBottom          (1e-2,  1e12,    3,        "RPowerBottom");
NamedPersistentSetting<float>    DampingAlpha          (0,     1,       0.9,     "DampingAlpha");
NamedPersistentSetting<uint16_t> SampleIntervalMs      (1,     1000,    50,      "SampleIntervalMs");
NamedPersistentSetting<float>    VRef                  (1,     20,      3.3,     "VRef");
NamedPersistentSetting<bool>     ExternalVRef          (false, true,    true,    "ExternalVRef");
NamedPersistentSetting<float>    DiodeDrop             (0,     20,      1.4,     "DiodeDrop");
NamedPersistentSetting<float>    DiodeDropZero         (0,     1,       0.001,   "DiodeDropZero");
NamedPersistentSetting<bool>     PrintState            (false, true,    false,   "PrintState");
NamedPersistentSetting<uint16_t> PrintStateMs          (50,    10000,   1000,    "PrintStateMs");
PersistentSetting<uint16_t>      SettingSignature      (0,     UINT16_MAX, MagicNumber);

void factoryReset(Stream& s)
{
    WinningWattSeconds.reset(true);
    InvertLampLogic.reset(true);
    PauseModeDuration.reset(true);
    WinModeDuration.reset(true);
    WinModeFlashMs.reset(true);
    RTop.reset(true);
    RBottom.reset(true);
    RPowerTop.reset(true);
    RPowerBottom.reset(true);
    DampingAlpha.reset(true);
    SampleIntervalMs.reset(true);
    VRef.reset(true);
    ExternalVRef.reset(true);
    DiodeDrop.reset(true);
    DiodeDropZero.reset(true);
    PrintState.reset(true);
    PrintStateMs.reset(true);
    SettingSignature.reset(true);
    s.println(F("Settings reset to defaults"));
}

void dumpSettings(Stream& s)
{

#define DUMP_SETTING(setting) do { \
    s.print(pad(setting.getName(), 30)); \
    s.print(pad(String(setting.get()), 10)); \
    s.print(pad(String(setting.getMinimum()), 10)); \
    s.println(String(setting.getMaximum())); \
    } while (0) 

    // Header
    s.print(pad("SETTING", 30));
    s.print(pad("CURRENT", 10));
    s.print(pad("MIN", 10));
    s.println(F("MAX"));

    DUMP_SETTING(WinningWattSeconds);
    DUMP_SETTING(InvertLampLogic);
    DUMP_SETTING(PauseModeDuration);
    DUMP_SETTING(WinModeDuration);
    DUMP_SETTING(WinModeFlashMs);
    DUMP_SETTING(RTop);
    DUMP_SETTING(RBottom);
    DUMP_SETTING(RPowerTop);
    DUMP_SETTING(RPowerBottom);
    DUMP_SETTING(DampingAlpha);
    DUMP_SETTING(SampleIntervalMs);
    DUMP_SETTING(VRef);
    DUMP_SETTING(ExternalVRef);
    DUMP_SETTING(DiodeDrop);
    DUMP_SETTING(DiodeDropZero);
    DUMP_SETTING(PrintState);
    DUMP_SETTING(PrintStateMs);

#undef DUMP_SETTING
}

