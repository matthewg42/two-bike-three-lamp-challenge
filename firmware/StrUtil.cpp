#include "StrUtil.h"

String pad(const String& s, unsigned int len, char p)
{
    String r(s);
    for (unsigned int i=0; i < len - s.length(); i++) {
        r += p;
    }
    return r;
}

String pad(const char* s, unsigned int len, char p)
{
    String r(s);
    return pad(r, len, p);
}
