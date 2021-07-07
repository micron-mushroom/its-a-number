#include "test.h"

int parse_test64(const char *name, u_int64_t (*parse_fn)(const char *), const char *str, const uint64_t val)
{
    u_int64_t result = parse_fn(str);

    char *result_str = str_from_64bits(&result);

    ASSERT_EQ(val, result, name, "%llu(%s)", result, result_str);
    free(result_str);
    return 0;
}

int main(int argc, char *argv[])
{
#ifdef LIBRARY_NAME
    printf("Running tests for: %s\n", LIBRARY_NAME);
#else
    printf("Running tests\n");
#endif

    // Run the test
    printf("-----Testing binary-----\n");
    bin_test();
    printf("-----Testing hex-----\n");
    hex_test();
    printf("-----Testing kaktovik-----\n");
    kaktovik_test();
    printf("-----Testing oct-----\n");
    oct_test();

    // Exit
    printf("Finished testing...time to exit.\n");
    return 0;
}