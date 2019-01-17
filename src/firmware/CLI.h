#pragma once

#include <Arduino.h>
#include <CommandInterface.h>

class CLIClass : public CommandInterface 
{
public:
    CLIClass(String prompt);
    void begin(Stream& stream);
    void runCmd();

private:
    String _prompt;

};

extern CLIClass CLI;

