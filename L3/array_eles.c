#include <stdio.h>

int main (void)
{
    int nums[10] = {10, 20, 30, 40, 50, 120};
    for (int i = 0; nums[i] != '\0'; i++) {
        // nums stores the address of the first num in array, so use * to get value each address
        printf("N%d: %d\n", i+1, *(nums+i));
    }
}