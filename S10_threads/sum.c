// use two threads to get the sum of elements in the arraay
#include <stdio.h>
#include <stdlib.h>

const int MAXLEN = 32;

int a[] = {1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 64,
           110, 220, 1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 64, 110, 220};

int main(void)
{
    int tot = 0;
    for (int i = 0; i < MAXLEN; i++)
    {
        tot += a[i];
    }
    printf("Tot: %d\n", tot);
}