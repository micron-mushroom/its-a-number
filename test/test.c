#include "test.h"

int main(int argc, char *argv[])
{
#ifdef LIBRARY_NAME
    printf("Running tests for: %s\n", LIBRARY_NAME);
#else
    printf("Running tests\n");
#endif

    // Run the test
    bin_test();

    // Exit
    printf("Finished testing...time to exit.\n");
    return 0;
}