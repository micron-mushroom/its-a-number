#include "its_a_number.h"
#include <string.h>


int bin_value(char c)
{
    if (c == '1')
        return 1;
    else if (c == '0')
        return 0;
    else
        return -1;
}

int is_binary_digit(char c)
{
    if (c == '1' || c == '0') return 1;
    else return 0;
}

#include <stdio.h>

float parse_bin_float(const char *str)
{
    int digits[80];
    unsigned len = 0;

    // The position of the dot in the string
    int dot_pos = -1;

    // The position of the vestigial one in the string
    int vest_pos = -1;

    // Read in the float digits
    for (unsigned i = 0;; i++)
    {
        char c = *(str + i);

        if (is_binary_digit(c))
        {
            int val = bin_value(c);

            // We hit the vestigial one, keep it's position for later
            if (val == 1 && vest_pos < 0)
            {
                vest_pos = i;
            }

            *(digits + len) = val;
            len++;
        }
        else if (c == '.' && dot_pos < 0)
            dot_pos = i - 1;
        else
            break;
    }

    // Calculate mantissa
    u_int32_t mantissa = 0;
    uint32_t mant_len = (len - vest_pos - 1);

    for (unsigned i = 0; i < len; i++)
    {
        mantissa |= *(digits + vest_pos + i) << i;
    }

    mantissa <<= 23 - mant_len;

    // Calculate exponent 
    uint32_t exponent = (uint32_t)(dot_pos - vest_pos + 127) << 23;


    // Fit the components together
    uint32_t buffer = exponent | mantissa;

    // Evil cast
    return *(float *)&buffer;
}

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
