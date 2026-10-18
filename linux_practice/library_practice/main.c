#include <stdio.h>
#include "arithmetic.h"

int main(void)
{
    double a = 10;
    double b = 3;

    printf("add: %.2f\n", add(a, b));
    printf("sub: %.2f\n", sub(a, b));
    printf("mul: %.2f\n", mul(a, b));
    printf("div: %.2f\n", div(a, b));

    return 0;
}
