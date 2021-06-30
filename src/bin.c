#include "its_a_number.h"

const char DIGITS[] = {'0', '1'};
const char *PREFIX = "0b";

typedef enum {
    IEEE32,
    IEEE64,
    SIGNED_MAGNITUDE,
    ONES_COMPLEMENT,
    TWOS_COMPLEMENT,
    FLOATING_POINT,
    DECIMAL,
} BinNumTypes;

/**
 * IEEE 32-bit floating point parsing. A note for convenience: 1 sign bit(31), 8
 * exponent bits(30-23), and 23 mantissa bits(22-0).
 */
float parse_bin_IEEE_float(char *str)
{
    // 32-bit buffer value
    unsigned long buffer = 0;

    // Copy the data to the buffer
    for(char i = 0; i < 32; i++) {
        
        // Reverse i so that we index the back of the string because that's where the lowest order bits are
        if(*(str + (31 - i) * sizeof(char)) == '1')
        {
            // Set the bit
            buffer |= (unsigned long)1 << i;
        }
    }

    // Relable the bits as a double and return the double
    return *(float *)&buffer;
}

/**
 * IEEE 64-bit floating point parsing. A note for convenience: 1 sign bit(63), 11
 * exponent bits(62-52), and 52 mantissa bits(51-0).
 */
double parse_bin_IEEE_double(char *str)
{
    // 64-bit buffer value
    unsigned long long buffer = 0;

    // Copy the data to the buffer
    for(char i = 0; i < 64; i++)
    {
        // Reverse i so that we index the back of the string because that's where the lowest order bits are
        if (*(str + (63 - i) * sizeof(char)) == '1')
        {
            // Set the bit
            buffer |= (unsigned long long)1 << i;
        }
    }

    // Relable the bits as a double and return the double
    return *(double *)&buffer;
}

/**
 * Parse binary conventionally.
 */
unsigned long long parse_bin_int(char *str)
{
    // Buffer value
    unsigned long long buffer = 0;
    unsigned size = 0;

    // Get the size of the string
    for(;;)
    {
        char c = *(str + size * sizeof(char));

        if(c == '0' | c == '1') size++;
        else break;
    }

    // Read the bits into buffer
    for(unsigned i = 0; i < size; i++)
    {
        if(*(str + (size-1 - i) * sizeof(char)) == '1')
        {
            buffer |= (unsigned long long)1 << i;
        }
    }

    return buffer;
}
