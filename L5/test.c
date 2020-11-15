#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int* c;
    char s;
    printf("Enter: ");
    scanf("%c%d", s, c);
    printf("%c, %d\n", s, c);
}