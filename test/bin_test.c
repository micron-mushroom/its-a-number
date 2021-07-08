#include "test.h"
#include <string.h>

/**
 * Parsing for floating point numbers (TODO)
 */
// void pi_test()
// {
    // 32 bit IEEE
    // {
    //     const float pi = 3.14;
    //     float result = parse_bin_IEEE_float("01000000010010001111010111000011");

    //     char *pi_str = str_from_32bits((unsigned long *)&pi);
    //     char *result_str = str_from_32bits((unsigned long *)&result);

    //     ASSERT_EQ(result, pi, "bin_test->pi_test(32)", fprintf(stderr, "\tresult = %s\n\tpi     = %s\n", result_str, pi_str));

    //     free(pi_str);
    //     free(result_str);
    // }

    // 64 bit IEEE
    // {
    //     const double pi = 3.1415926535897;
    //     double result = parse_bin_IEEE_double("0100000000001001001000011111101101010100010001000010110001000110");

    //     char *pi_str = str_from_64bits((unsigned long long*)&pi);
    //     char *result_str = str_from_64bits((unsigned long long*)&result);

    //     ASSERT_EQ(result, pi, "bin_test->pi_test(64)", fprintf(stderr, "\tresult = %s\n\tpi     = %s\n", result_str, pi_str));

    //     free(pi_str);
    //     free(result_str);
    // }
// }

/**
 * Test function
 */
void bin_test() {
    parse_test64("bin_int", parse_bin_int, "01100101", 0b01100101);

    parse_test64("bin_int(2)", parse_bin_int, "101111011011010101000101", 0b101111011011010101000101);
}