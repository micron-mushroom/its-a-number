#include "its_a_number.h"
#include <string.h>

int oct_value(char c)
{
    switch(c)
    {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;

        default: 
            return -1;
    }
}

uint64_t parse_oct_int(const char *str)
{
    uint64_t buffer = 0; 
    unsigned len = strlen(str);

    for(unsigned i = 0; i < len; i++)
    {
        buffer |= (uint64_t)oct_value(str[len-i-1]) << (3 * i);
    }

    return buffer;
}
