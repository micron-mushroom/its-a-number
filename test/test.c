#include "test.h"

int main(int argc, char *argv[])
{
#ifdef LIBRARY_NAME
    printf("Running tests for: %s\n", LIBRARY_NAME);
#else
    printf("Running tests\n");
#endif

    // Run the test
    printf("-----Testing binary-----\n");
    bin_test();
    printf("-----Testing hex-----\n");
    hex_test();
    printf("-----Testing oct-----\n");
    oct_test();

    // Exit
    printf("Finished testing...time to exit.\n");
    return 0;
}