#include "test.h"

void kaktovik_test()
{
    parse_test64("kaktovik_int", &parse_kaktovik_int, "\\`%", 20);
    
    parse_test64("kaktovik_int(2)", &parse_kaktovik_int, "/\\`^\\/\\/", 134);

    parse_test64("kaktovik_int(3)", &parse_kaktovik_int, "\\/`^/\\/\\/`^/\\`^/\\/`/\\`^/\\/", 9574937);
}