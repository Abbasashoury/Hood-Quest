#include "Hash.h"

int ConvertToHash(const string &pass)
{
    size_t hash = 0;
    for (char c : pass)
    {
        hash = hash * 31 + c;
    }
    return hash;
}