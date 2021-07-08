#include "its_a_number.h"
#include <string.h>


// Bias for exponent for floating point numbers
// double parse_bin_double(const char *str, unsigned begin, unsigned end)
// {
//     u_int64_t buffer = 0;

//     // Figure out if we have a sign and deal with it
//     switch (*str)
//     {
//     case '-':
//         // Looks like a negative, time to set the sign bit
//         buffer |= (u_int64_t)1 << 63;
//     case '+':
//         str++;
//         break;
    
//     default:
//         break;
//     }

//     // Find the floating point so we know where to split the string
//     const char* dot = strchr(str, '.');

//     // Get our fractional and our integer components
//     // u_int64_t integer = parse_bin_int(str, 0, str - dot);
//     // u_int64_t fraction = parse_bin_int(str, dot + 1, end);


//     // Encode the exponent
//     // int exp = 0;

//     // if(integer)
//     // {
        
//     // }
//     // else if(fraction)
//     // {

//     // }

//     // buffer |= 1023 + 
// }

/**
 * Parse binary conventionally.
 */
u_int64_t parse_bin_int(const char *str)
{
    // Buffer value
    u_int64_t buffer = 0;
    unsigned len = strlen(str);

    // Read the bits into buffer
    for(unsigned i = 0; i < len; i++)
    {
        if(str[len-i-1] == '1')
        {
            buffer |= (u_int64_t)1 << i;
        }
    }

    return buffer;
}
