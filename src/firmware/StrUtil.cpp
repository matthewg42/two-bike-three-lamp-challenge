#include "StrUtil.h"

bool deb = true;

String pad(const String& s, unsigned int len, char p)
{
    String r(s);
    if (deb) { 
        Serial.print(F("\nPAD DEBUG{s=<"));
        Serial.print(s);
        Serial.print(F("> len="));
        Serial.print(len);
        Serial.print(F(" rpre=<"));
        Serial.print(r);
        Serial.print('>');
    }
    for (unsigned int i=0; i < len - s.length(); i++) {
        r += p;
    }
    if (deb) { 
        Serial.print(F(" rpost=<"));
        Serial.print(r);
        Serial.println(">");
        deb = false;
    }
    return r;
}

String pad(const char* s, unsigned int len, char p)
{
    String r(s);
    return pad(r, len, p);
}
