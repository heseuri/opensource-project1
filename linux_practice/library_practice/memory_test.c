#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *arr = malloc(10 * sizeof(int));

    if (arr == NULL) {
        return 1;
    }

    arr[0] = 100;
    printf("%d\n", arr[0]);


    return 0;
}
