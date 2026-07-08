#include "Hash.h"

size_t ConvertToHash(const string &pass)
{
    size_t hash = 0;
    for (char c : pass)
    {
        hash = hash * 31 + c;
    }
    return hash;
}