#include <stdlib.h>
#include <time.h>

#include "tests.h"

int main(int argc, char **argv)
{
    srand(time(NULL));

    if (test_runner(argc, argv) != 0)
    {
        return -1;
    }

    return 0;
}