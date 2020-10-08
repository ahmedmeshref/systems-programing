#include <stdio.h>

int main (void)
{
    int n1, n2, *x, *y;
    printf("Enter two nums seperated by space: ");
    scanf("%d %d", &n1, &n2);
    x = &n1; 
    y = &n2;
    printf("Sum = %d\n", *x + *y);
}