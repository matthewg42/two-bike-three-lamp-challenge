#include <PersistentSetting.h>
#include <stdint.h>

const uint16_t MagicNumber = 0xACDC;

extern NamedPersistentSetting<uint16_t> WinningWattSeconds;
extern NamedPersistentSetting<bool>     InvertLampLogic;
extern NamedPersistentSetting<uint8_t>  PauseModeDuration;
extern NamedPersistentSetting<uint8_t>  WinModeDuration;
extern NamedPersistentSetting<uint16_t> WinModeFlashMs;
extern NamedPersistentSetting<float>    RTop;
extern NamedPersistentSetting<float>    RBottom;
extern NamedPersistentSetting<float>    RPowerTop;
extern NamedPersistentSetting<float>    RPowerBottom;
extern NamedPersistentSetting<float>    DampingAlpha;
extern NamedPersistentSetting<uint16_t> SampleIntervalMs;
extern NamedPersistentSetting<float>    VRef;
extern NamedPersistentSetting<bool>     ExternalVRef;
extern NamedPersistentSetting<float>    DiodeDrop;
extern NamedPersistentSetting<float>    DiodeDropZero;
extern NamedPersistentSetting<bool>     PrintState;
extern NamedPersistentSetting<uint16_t> PrintStateMs;
extern PersistentSetting<uint16_t>      SettingSignature;

// Reset all settings to default values and save them
void factoryReset(Stream& s=Serial);

// Dump details of all settings to stream (e.g. Serial)
void dumpSettings(Stream& s=Serial);

