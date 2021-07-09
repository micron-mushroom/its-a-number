#include "test.h"
#include <string.h>

/**
 * Test function
 */
void bin_test() {
    // Int tests
    parse_test64("bin_int", parse_bin_int, "01100101", 0b01100101);

    parse_test64("bin_int(2)", parse_bin_int, "101111011011010101000101", 0b101111011011010101000101);

    // Float tests
    parse_testf("bin_float", parse_bin_float, "101.01", 5.25f);
}