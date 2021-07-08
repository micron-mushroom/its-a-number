#include "test.h"

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
        printf("\t result = %llu(%s)\n", result, result_str);
        return -1;
    }
    else
        printf("Passed test %s\n", name);

    free(result_str);
    return 0;
}

#define HEADER_WIDTH 80
#define HEADER_PADDR '-'

/**
 * Prettier test header printing. 
 */
void print_header(const char *str)
{
    // Where should we start printing the header string?
    unsigned len = strlen(str);
    unsigned pos = (HEADER_WIDTH >> 1) - (len >> 1) - 1;

    // Print the header
    for (unsigned i = 0; i < HEADER_WIDTH; i++)
    {        
        // We aren't within the bounds of the string, print the padder
        if (i < pos || i > pos + len)
            putchar(HEADER_PADDR);
        // We are within the bounds of the string, print the relevant chr
        else
            putchar(*(str + (i - pos)));
    }

    putchar('\n');
    fflush(stdout);
}

// Macros make things clean
#define RUN_TESTS(MOD_NAME, EXPR) \
    print_header(MOD_NAME); \
    EXPR;

int main(int argc, char *argv[])
{
#ifdef LIBRARY_NAME
    printf("Running tests for: %s\n", LIBRARY_NAME);
#else
    printf("Running tests\n");
#endif

    // Run the test
    RUN_TESTS(" BINARY ", bin_test());
    RUN_TESTS(" HEX ", hex_test());
    RUN_TESTS(" KAKTOVIK ", kaktovik_test());
    RUN_TESTS(" OCTAL ", oct_test());

    // Exit
    printf("Finished testing... time to exit.\n");
    return 0;
}
