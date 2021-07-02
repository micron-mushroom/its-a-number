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
        fprintf(stderr, "Failed test " TEST_NAME ":\n"); \
        fprintf(stderr, "\t" #RESULT " = " FMT_STR, ##__VA_ARGS__); \
        exit(1); \
    } \
    else printf("Passed test " TEST_NAME "\n");

/**
 * Helpful functions
 */
char* str_from_64bits(unsigned long long *val);

/**
 * Different tests tht can be run.
 */
void bin_test();
void hex_test();
void oct_test();

#endif