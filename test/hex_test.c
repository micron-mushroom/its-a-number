#include "test.h"

void hex_test()
{
    {
        unsigned long long result = parse_hex_int("FF");

        char *result_str = str_from_64bits(&result);
        ASSERT_EQ(255, result, "hex_test->parse_hex", "%llu(%s)", result, result_str);
        free(result_str);
    }
    {
        unsigned long long result = parse_hex_int("FFA365");
        char *result_str = str_from_64bits(&result);
        ASSERT_EQ(0xFFA365, result, "hex_test->parse_hex(2)", "%llu(%s)", result, result_str);
        free(result_str);
    }
}