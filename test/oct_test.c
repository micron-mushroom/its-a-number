#include "test.h"

void oct_test()
{
    parse_test64("oct_int", parse_oct_int, "7423", 07423);

    parse_test64("oct_int(2)", parse_oct_int, "325347", 0325347);
}