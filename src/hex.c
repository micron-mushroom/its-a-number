#include "its_a_number.h"
#include <string.h>

const char* symbols = "0123456789ABCDEFabcdef";

int is_hex(char c)
{
    for(int i = 0; i < strlen(symbols); i++)
    {
        if(symbols[i] == c) return 1;
    }
    return 0;
}

/**
 * Map chars to their hex values. If the input isn't a hex character it will return -1
 */
int hex_value(char c)
{
    switch (c)
    {
    // Digits
    case '1': return 0x1;
    case '2': return 0x2;
    case '3': return 0x3;
    case '4': return 0x4;
    case '5': return 0x5;
    case '6': return 0x6;
    case '7': return 0x7;
    case '8': return 0x8;
    case '9': return 0x9;
    case '0': return 0x0;

    // Letters A-F
    case 'A':
    case 'a': return 0xA;

    case 'B': 
    case 'b': return 0xB;

    case 'C': 
    case 'c': return 0xC;

    case 'D': 
    case 'd': return 0xD;

    case 'E': 
    case 'e': return 0xE;

    case 'F': 
    case 'f': return 0xF;
    
    // Non hex character return invalid
    default: return -1;
    }
}


unsigned long long parse_hex_int(char *str)
{
    unsigned long long buffer = 0;
    const unsigned len = strlen(str);

    // Copy bits into buffer
    for(unsigned i = 0; i < len; i++)
    {
        buffer |= (unsigned long long)hex_value(str[len-i-1]) << (4 * i);
    }

    return buffer;
}
