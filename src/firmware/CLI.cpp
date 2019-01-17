#include <MutilaDebug.h>
#include "Settings.h"
#include "CLI.h"

CLIClass::CLIClass(String prompt) :
    CommandInterface(48)
{
    _prompt = prompt;
}

void CLIClass::begin(Stream& stream)
{
    CommandInterface::begin(stream);
    DBLN(F("CLIClass::begin"));
    strcpy(_buf, "h");
    runCmd();
}

void CLIClass::runCmd()
{
    uint8_t i;
    String cmd;
    for (i = 0; i < _maxLen && _buf[i] != ' ' && _buf[i] != '\0'; i++) {
        cmd += _buf[i];
    }
    while (_buf[i] == ' ') { ++i; }
    if (cmd == "h") {
        _stream->print(
          F("Commands:\n"
            "h - this cruft\n"
            "p - print a list of settings\n"
            "r - reset settings to defaults\n\n"
            "To set the value of individual settings enter the name of the setting,\n"
            "a space and the new value for the setting, for example:\n\n"
            "  WinningWattSeconds 1500\n"));
    } else if (cmd == "p") {
        dumpSettings(*_stream);
    } else if (cmd == "r") {
        factoryReset(*_stream);
    } else if (cmd == "WinningWattSeconds") {
        WinningWattSeconds.set(String(_buf+i).toInt());
        WinningWattSeconds.save();
    } else if (cmd == "InvertLampLogic") {
        InvertLampLogic.set(String(_buf+i).toInt());
        InvertLampLogic.save();
    } else if (cmd == "PauseModeDuration") {
        PauseModeDuration.set(String(_buf+i).toInt());
        PauseModeDuration.save();
    } else if (cmd == "WinModeDuration") {
        WinModeDuration.set(String(_buf+i).toInt());
        WinModeDuration.save();
    } else if (cmd == "RTop") {
        RTop.set(String(_buf+i).toFloat());
        RTop.save();
    } else if (cmd == "RBottom") {
        RBottom.set(String(_buf+i).toFloat());
        RBottom.save();
    } else if (cmd == "RPowerTop") {
        RPowerTop.set(String(_buf+i).toFloat());
        RPowerTop.save();
    } else if (cmd == "RPowerBottom") {
        RPowerBottom.set(String(_buf+i).toFloat());
        RPowerBottom.save();
    } else if (cmd == "DampingAlpha") {
        DampingAlpha.set(String(_buf+i).toFloat());
        DampingAlpha.save();
    } else if (cmd == "SampleIntervalMs") {
        SampleIntervalMs.set(String(_buf+i).toInt());
        SampleIntervalMs.save();
    } else if (cmd == "VRef") {
        VRef.set(String(_buf+i).toFloat());
        VRef.save();
    } else if (cmd == "ExternalVRef") {
        ExternalVRef.set(String(_buf+i).toInt());
        ExternalVRef.save();
    } else if (cmd == "DiodeDrop") {
        DiodeDrop.set(String(_buf+i).toFloat());
        DiodeDrop.save();
    } else if (cmd == "DiodeDropZero") {
        DiodeDropZero.set(String(_buf+i).toFloat());
        DiodeDropZero.save();
    } else {
        _stream->println(F("invalid command"));
    }
    _stream->print(_prompt);
}

CLIClass CLI("\nCMD> ");

