/**
 * its-a-number is a library to help with parsing numbers from different base
 * and numeral systems. It contains the ability to parse the standard bases you
 * would typically encounter on computers like binary, octal, and hex. But in
 * addition, it also allows the parsing of alternate numeral systems like the
 * Kaktovik Inupiaq numerals.
 */

// Binary
float parse_bin_float(char *str);
double parse_bin_double(const char *str, unsigned begin, unsigned end);
unsigned long long parse_bin_int(const char *str);

// Hex
float parse_hex_float(char *str);
double parse_hex_double(char *str);
unsigned long long parse_hex_int(char *str);

// Kaktovik Inupiaq
float parse_kaktovik_float(char *str);
double parse_kaktovik_double(char *str);
unsigned long long parse_kaktovik_int(const char *str);

// Octal
float parse_oct_float(char *str);
double parse_oct_double(char *str);
unsigned long long parse_oct_int(char *str);

