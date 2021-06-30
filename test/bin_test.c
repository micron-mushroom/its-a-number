#include "test.h"
#include <string.h>

/**
 * Helper function to format a 32 bit type as a str
 */
char* str_from_32bits(unsigned long *val)
{
    // Allocate cstring with 32 characters for bits and an extra for the null terminator
    char *str = (char *)calloc(33, sizeof(char));
    memset(str, '\0', 33);

    // Read the bits into the string
    for(int i = 0; i < 32; i++)
    {
        char *index = str + (i*sizeof(char));

        if(*val >> (31 - i) & 1) *index = '1';
        else *index = '0';
    }

    // Return
    return str;
}

/**
 * Helper function to format a 64 bit type as a str
 */
char* str_from_64bits(unsigned long long *val)
{
    // Allocate cstring with 64 character for bits and an extra for the null terminator
    char *str = (char*)calloc(65, sizeof(char));
    memset(str, '\0', 65);

    // Read the bits into the string
    for(int i = 0; i < 64; i++)
    {
        char *index = str + (i*sizeof(char));

        if(*val >> (63 - i) & 1) *index = '1';
        else *index = '0';
    }

    // Return
    return str;
}

/**
 * Parsing pi as an IEEE float and double. Does it work or does it not?
 */
void pi_test()
{
    // 32 bit IEEE
    {
        const float pi = 3.14;
        float result = parse_bin_IEEE_float("01000000010010001111010111000011");

        char *pi_str = str_from_32bits((unsigned long *)&pi);
        char *result_str = str_from_32bits((unsigned long *)&result);

        ASSERT_EQ(result, pi, "bin_test->pi_test(32)", fprintf(stderr, "\tresult = %s\n\tpi     = %s\n", result_str, pi_str));

        free(pi_str);
        free(result_str);
    }

    // 64 bit IEEE
    {
        const double pi = 3.1415926535897;
        double result = parse_bin_IEEE_double("0100000000001001001000011111101101010100010001000010110001000110");

        char *pi_str = str_from_64bits((unsigned long long*)&pi);
        char *result_str = str_from_64bits((unsigned long long*)&result);

        ASSERT_EQ(result, pi, "bin_test->pi_test(64)", fprintf(stderr, "\tresult = %s\n\tpi     = %s\n", result_str, pi_str));

        free(pi_str);
        free(result_str);
    }
}

void plain_test()
{
    const unsigned long long value = 0b01100101;
    unsigned long long result = parse_bin_int("01100101");

    char *v_str = str_from_64bits(&value);
    char *result_str = str_from_64bits(&result);

    ASSERT_EQ(result, value, "bin_test->plain_test", fprintf(stderr, "\tresult = %s\n\tvalue  = %s", result_str, v_str));

    free(v_str);
    free(result_str);
}

/**
 * Test function
 */
void bin_test() {
    pi_test();
    plain_test();
}