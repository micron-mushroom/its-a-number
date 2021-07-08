#include "test.h"

void hex_test()
{
    parse_test64("hex_int", parse_hex_int, "FF", 0xFF);
    
    parse_test64("hex_int(2)", parse_hex_int, "FFA365", 0xFFA365);
}