// write a program in c to show memorey allocation for an array
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *arr = malloc(3 * sizeof(int));
    if (arr == NULL)
    {
        printf("Failed to allocated memory for arr!\n");
        return 1;
    }

    // fillin the array with values
    for (int i = 1; i <= 3; i++)
        arr[i - 1] = i;

    // create a bigger temp memory
    int *temp = realloc(arr, 4 * sizeof(int));
    free(arr);
    if (temp == NULL)
    {
        printf("Falied to allocate memory\n");
        free(arr);
        return 2;
    }
    temp[3] = 4;
    arr = temp;

    for (int i = 0; i < 4; i++)
        printf("Index: %d, Val: %d\n", i, arr[i]);

    free(arr);
    return 0;
}