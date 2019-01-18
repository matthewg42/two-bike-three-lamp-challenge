#pragma once

#include <Arduino.h>

String pad(const String& s, unsigned int len, char p=' ');
String pad(const char* s, unsigned int len, char p=' ');

