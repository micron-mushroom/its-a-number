#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <its_a_number.h>

/**
 * Helper function to format a 64 bit type as a str
 */
char *str_from_bits(const uint64_t *val)
{
    // Allocate cstring with 64 character for bits and an extra for the null terminator
    char *str = (char *)calloc(65, sizeof(char));
    memset(str, '\0', 65);

    // Read the bits into the string
    for (int i = 0; i < 64; i++)
    {
        char *index = str + (i * sizeof(char));

        if (*val >> (63 - i) & 1)
            *index = '1';
        else
            *index = '0';
    }

    // Return
    return str;
}

char *str_from_bits32(const uint32_t *val)
{
    char *str = (char*)calloc(33, sizeof(char));
    memset(str, '\0', 33);

    for (uint32_t i = 0; i < 32; i++)
    {
        char *index = str + (i * sizeof(char));

        if (*val >> (31 - i) & 1)
            *index = '1';
        else
            *index = '0';
    }

    return str;
}

/**
 * Used for testing the int parsing functions.
 */
int parse_test64(const char *name, u_int64_t (*parse_fn)(const char *), const char *str, const uint64_t val)
{
    u_int64_t result = parse_fn(str);
    char *result_str = str_from_bits(&result);

    // Testing time
    if (val != result)
    {
        printf("Failed test %s:\n", name);
        printf("\t%llu != %llu\n", val, result);
        printf("\tresult = %llu(%s)\n", result, result_str);
        return -1;
    }
    else
        printf("Passed test %s\n", name);

    free(result_str);
    return 0;
}

/**
 * Used for testing the float parsing functions
 */
int parse_testf(const char *name, float (*parse_fn)(const char *), const char *str, const float val)
{
    float result = parse_fn(str);
    char *result_str = str_from_bits32((uint32_t *)&result);

    // Test time
    if (val != result)
    {
        printf("Failed test %s:\n", name);
        printf("\t%f != %f\n", val, result);
        printf("\tresult = %f(%s)\n", result, result_str);
        return -1;
    }
    else
        printf("Passed test %s\n", name);

    free(result_str);
    return 0;
}

void bin_test() {
    // Int tests
    parse_test64("bin_int", parse_bin_int, "01100101", 0b01100101);
    parse_test64("bin_int(2)", parse_bin_int, "101111011011010101000101", 0b101111011011010101000101);

    // Float tests
    parse_testf("bin_float", parse_bin_float, "101.01", 5.25f);
}

void hex_test()
{
    parse_test64("hex_int", parse_hex_int, "FF", 0xFF);
    parse_test64("hex_int(2)", parse_hex_int, "FFA365", 0xFFA365);
}

void kaktovik_test()
{
    parse_test64("kaktovik_int", &parse_kaktovik_int, "\\`%", 20);
    parse_test64("kaktovik_int(2)", &parse_kaktovik_int, "/\\`^\\/\\/", 134);
    parse_test64("kaktovik_int(3)", &parse_kaktovik_int, "\\/`^/\\/\\/`^/\\`^/\\/`/\\`^/\\/", 9574937);
}

void oct_test()
{
    parse_test64("oct_int", parse_oct_int, "7423", 07423);
    parse_test64("oct_int(2)", parse_oct_int, "325347", 0325347);
}

int main(int argc, char *argv[])
{
#ifdef LIBRARY_NAME
    printf("Running tests for: %s\n", LIBRARY_NAME);
#else
    printf("Running tests\n");
#endif

    printf("----- Binary -----\n");
    bin_test();

    printf("----- Hex -----\n");
    hex_test();

    printf("----- Kaktovik numerals -----\n");
    kaktovik_test();

    printf("----- Octal -----\n");
    oct_test();

    printf("Finished testing... time to exit.\n");
    return 0;
}

