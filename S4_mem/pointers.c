#include <stdio.h>
#include <string.h>

int main ()
{
    int n = 10;
    // int *p = &n;
    // printf("%p\n", p);

    // strings with pointers to the first char
    char *s = "HI";
    printf("%s\n", s);
    for (int i = 0, n = strlen(s); i < n; i++){
        printf("%c\n", s[i]);
    }
    return 0;
}