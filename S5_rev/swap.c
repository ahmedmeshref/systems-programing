#include <stdio.h>

void swap (int *x,int *y);

int main (void)
{
    int a = 10, b = 20;
    printf("A= %d\nB= %d\n", a, b);
    swap(&a, &b);
    printf("A= %d\nB= %d\n", a, b);
}

void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 