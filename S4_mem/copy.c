#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main (void) 
{
    char *s = "Hi!";
    int n = strlen(s);
    // add 1 to the len to accommodate the \0
    char *t = malloc(n + 1);
    // if memory alllocation was not successful 
    if (t == NULL) {
        return 1;
    }

    for (int i =0; i <= n; i++){
        t[i] = s[i];
    }

    if (strlen(t) > 0) t[1] = toupper(t[1]);

    printf("s: %s\nt: %s\n", s, t);

    // free the memory of t
    free(t);
    return 0;
}