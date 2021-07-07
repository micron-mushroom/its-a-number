/**
 * # Overview
 * Kaktovik as a base 20 numeral system(Read more on
 * https://en.wikipedia.org/wiki/Kaktovik_numerals). It's not a part of the
 * unicode standard, but it seems usefull to be able to parse the numerals so
 * this file provides a methode for formatting the numerals and some functions
 * to parse that format.
 *
 * # An informal grammar definition:
 * ```
 * float ::= [sign,] digits, ".", digits;
 * integer ::= [sign,] digits;
 * 
 * sign ::= "+" | "-";
 * 
 * digits ::= {digit, sep}+;
 * 
 * digit ::= "%" (* zero *)
 *         | "\" (* one *)
 *         | "\/" (* two *)
 *         | "\/\" (* three *)
 *         | "\/\/" (* four *)
 *         | "/" (* five *)
 *         | "/\" (* six *)
 *         | "/\/" (* seven *)
 *         | "/\/\" (* eight *)
 *         | "/\/\/" (* nine *)
 *         | "^" (* ten *)
 *         | "^\" (* eleven *)
 *         | "^\/" (* twelve *)
 *         | "^\/\" (* thirteen *)
 *         | "^\/\/" (* fourteen *)
 *         | "^/" (* fifteen *)
 *         | "^/\" (* sixteen *)
 *         | "^/\/" (* seventeen *)
 *         | "^/\/\"(* eighteen *)
 *         | "^/\/\/" (* nineteen *)
 *         ;
 * 
 * sep ::= "`" | "'" | "\0";
 * ```
 * 
 * # Example numbers
 * ```
 * 20 = \`%
 * 25 = \`/
 * 134 = /\`^\/\/
 * 9574937 = \/`^/\/\/`^/\`^/\/`/\`^/\/
 * ```
 */

#include <string.h>
#include <stdint.h>
#include <errno.h>

#include "its_a_number.h"

// djb2
unsigned long strhash(const char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;

    return hash;
}

int is_sep(const char c)
{
    if(c == '`' || c == '\'' || c == '\0') return 1;
    else return 0;
}

/**
 * Reads a kaktovik digit in from a string starting at index and moves the index
 * ahead accordingly.
 */
int read_digit(const char *str, unsigned *index)
{
    char buffer[7] = {'\0'};

    // Read the digit fragments into our buffer
    for (unsigned i = 0; !is_sep(*(str + *index)); i++, (*index)++)
        *(buffer + i) = *(str + *index);

    // Move forward to the next digit if we aren't at the end of the string
    if(*(str + *index) != '\0')
        (*index)++;

    // Figure out the value of the specific sequence
    switch (strhash(buffer))
    {
    // strhash("%") = 0x2b5ca
    case 0x2b5ca:
        return 0;

    // strhash("\") = 0x2b601
    case 0x2b601:
        return 1;

    // strhash("\/") = 0x597650
    case 0x597650:
        return 2;

    // strhash("\/\") = 0xb8840ac
    case 0xb8840ac:
        return 3;

    // strhash("\/\/") = 0x17c90565b
    case 0x17c90565b:
        return 4;

    // strhash("/") = 0x2b5d4
    case 0x2b5d4:
        return 5;

    // strhash("/\") = 0x5970b0
    case 0x5970b0:
        return 6;

    // strhash("/\/") = 0xb8786df
    case 0xb8786df:
        return 7;

    // strhash("/\/\") = 0x17c78631b
    case 0x17c78631b:
        return 8;

    // strhash("/\/\/") = 0x310b84c6aa
    case 0x310b84c6aa:
        return 9;

    // strhash("^") = 0x2b603
    case 0x2b603:
        return 10;

    // strhash("^\") = 0x5976bf
    case 0x5976bf:
        return 11;

    // strhash("^\/") = 0xb884ece
    case 0xb884ece:
        return 12;

    // strhash("^\/\") = 0x17c9228ea
    case 0x17c9228ea:
        return 13;

    // strhash("^\/\/") = 0x310ed74659
    case 0x310ed74659:
        return 14;

    // strhash("^/") = 0x597692
    case 0x597692:
        return 15;

    // strhash("^/\") = 0xb88492e
    case 0xb88492e:
        return 16;

    // strhash("^/\/") = 0x17c916f1d
    case 0x17c916f1d:
        return 17;

    // strhash("^/\/\") = 0x310ebf5319
    case 0x310ebf5319:
        return 18;

    // strhash("^/\/\/") = 0x652e6a9b668
    case 0x652e6a9b668:
        return 19;

    default:
        return -1;
    }
}


/**
 * Less slow exponentiation for my integer friends
 */
int ipow(int base, int exp)
{
    int result = 1; 

    for(;;)
    {
        if(exp & 1)
            result *= base;
        exp >>= 1;

        if(!exp)
            break;
        
        base *= base;
    }

    return result;
}

/**
 * Kaktovik int parsing
 */
u_int64_t parse_kaktovik_int(const char *str)
{
    uint64_t buffer = 0;

    // Read in out digits
    int digits[20];
    memset(digits, 21, 20*sizeof(int));

    unsigned pos = 0;
    unsigned len = strlen(str);

    for (int *i = digits; pos < len; i++)
    {
        int result = read_digit(str, &pos);

        if (result == -1)
        {
            errno = EILSEQ;
            return 0;
        }

        *i = result;
    }

    // Count digits
    unsigned num_digits = 0; 

    for (int *i = digits; *i < 20; i++)
        num_digits++;
        
    // Compute the final number from the array of digits
    for (int i = 0; i < num_digits; i++)
        buffer += (uint64_t) *(digits + i) * ipow(20, num_digits-1 - i);

    return buffer;
}