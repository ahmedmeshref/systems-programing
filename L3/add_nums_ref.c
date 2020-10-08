#include <stdio.h>

int get_sum(int *x,int *y);

int main (void)
{
    int n1, n2;
    printf("Enter two nums seperated by space: ");
    scanf("%d %d", &n1, &n2);
    int sum = get_sum(&n1, &n2);
    printf("Sum = %d\n", sum);
}

int get_sum(int *x,int *y)
{
    return *x + *y;
}