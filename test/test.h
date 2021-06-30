#ifndef __TEST
#define __TEST

/**
 * Macros to make test writing easier. Maybe I copied them from rust?
 */
#include <stdio.h>
#include <stdlib.h>
#include <its_a_number.h>

#define ASSERT_EQ(A, B, TEST_NAME, LOG_EXPR) \
    if (A != B) \
    { \
        fprintf(stderr, "Failed test " TEST_NAME ":\n\t" #A " != " #B "\n"); \
        LOG_EXPR; \
        exit(1); \
    } \
    else printf("Passed test" TEST_NAME "\n");

/**
 * Different tests tht can be run.
 */
void bin_test();

#endif