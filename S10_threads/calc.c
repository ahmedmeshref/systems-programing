#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int main(void)
{
    int *arr;
    arr = (int *)malloc(sizeof(int) * 3);

    arr[1] = 120;

    for (int i = 0; i < 3; i++)
    {
        printf("Num: %d\n", arr[i]);
    }
}