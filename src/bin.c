#include "its_a_number.h"
#include <string.h>

/**
 * Parse binary conventionally.
 */
unsigned long long parse_bin_int(char *str)
{
    // Buffer value
    unsigned long long buffer = 0;
    unsigned len = strlen(str);

    // Read the bits into buffer
    for(unsigned i = 0; i < len; i++)
    {
        if(str[len-i-1] == '1')
        {
            buffer |= (unsigned long long)1 << i;
        }
    }

    return buffer;
}
