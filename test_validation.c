#include <stdio.h>
#include <assert.h>

#include "../../src/validation/validation.h"

int main(void)
{
    assert(validateMenuChoice(1) == 1);
    assert(validateMenuChoice(6) == 1);

    assert(validateMenuChoice(10) == 0);

    assert(validateStationName("Chennai") == 1);

    assert(validateStationName("") == 0);

    assert(validateStationName("@@@") == 0);

    assert(validateStationIndex(0) == 1);

    assert(validateStationIndex(500) == 0);

    printf("Validation Unit Test Passed\n");

    return 0;
}