/**
 * its-a-number is a library to help with parsing numbers from different base
 * and numeral systems. It contains the ability to parse the standard bases you
 * would typically encounter on computers like binary, octal, and hex. But in
 * addition, it also allows the parsing of alternate numeral systems like the
 * Kaktovik Inupiaq numerals.
 */

#ifndef __ITS_A_NUMBER
#define __ITS_A_NUMBER

#include <stdint.h>

// Binary
// float parse_bin_float(const char *str);
// double parse_bin_double(const char *str);
uint64_t parse_bin_int(const char *str);

// Hex
// float parse_hex_float(const char *str);
// double parse_hex_double(const char *str);
uint64_t parse_hex_int(const char *str);

// Kaktovik Inupiaq
// float parse_kaktovik_float(const char *str);
// double parse_kaktovik_double(const char *str);
uint64_t parse_kaktovik_int(const char *str);

// Octal
// float parse_oct_float(const char *str);
// double parse_oct_double(const char *str);
uint64_t parse_oct_int(const char *str);

#endif