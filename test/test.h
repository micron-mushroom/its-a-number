#ifndef __TEST
#define __TEST

/**
 * Macros to make test writing easier. Maybe I copied them from rust?
 */
#include <stdio.h>
#include <stdlib.h>
#include <its_a_number.h>

#define ASSERT_EQ(CONST, RESULT, TEST_NAME, FMT_STR, ...) \
    if (CONST != RESULT) \
    { \
        fprintf(stderr, "Failed test %s:\n", TEST_NAME); \
        fprintf(stderr, "\t" #RESULT " = " FMT_STR "\n", ##__VA_ARGS__); \
        exit(1); \
    } \
    else printf("Passed test %s\n", TEST_NAME);

int parse_test64(const char *name, u_int64_t (*parse_fn)(const char *), const char *str, const uint64_t val);

/**
 * Helpful functions
 */
char* str_from_64bits(unsigned long long *val);

/**
 * Different tests tht can be run.
 */
void bin_test();
void hex_test();
void kaktovik_test();
void oct_test();

#endif