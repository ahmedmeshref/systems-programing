#include <stdio.h>

int main (void)
{
    int n1, n2, *x, *y;
    printf("Enter two nums seperated by space: ");
    // TODO: why can't I use x and y directly here as they store address.
    scanf("%d %d", &n1, &n2);
    x = &n1; 
    y = &n2;
    if (*x > *y) {
        printf("max = %d\n", *x);
    } else if (*y > *x) {
        printf("max = %d\n", *y);
    } else {
        printf("Numbers are equal.\n");
    }
}