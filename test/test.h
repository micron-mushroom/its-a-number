#ifndef __TEST
#define __TEST

/**
 * Macros to make test writing easier. Maybe I copied them from rust?
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <its_a_number.h>

int parse_test64(const char *name, u_int64_t (*parse_fn)(const char *), const char *str, const uint64_t val);
int parse_testf(const char *name, float (*parse_fn)(const char *), const char *str, const float val);

/**
 * Helpful functions
 */
char* str_from_bits(const uint64_t *val);

/**
 * Tests
 */
void bin_test();
void hex_test();
void kaktovik_test();
void oct_test();

#endif