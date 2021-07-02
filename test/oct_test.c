#include "test.h"

void oct_test()
{
    unsigned long long val = 07423;
    unsigned long long result = parse_oct_int("7423");

    char *result_str = str_from_64bits(&result);
    ASSERT_EQ(val, result, "oct_test->parse_int", "%llu(%s)", result, result_str);
    free(result_str);
}