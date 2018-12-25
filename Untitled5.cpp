#include <stdio.h>

int main()
{
    int a = 3;
    int *pa = &a;

    printf("*pa = %d\n", *pa); // *pa = 3

    *pa = 4;
    printf("*pa = %d\n", *pa); // *pa = 4

    printf("a = %d\n", a);

    return 0;
}
