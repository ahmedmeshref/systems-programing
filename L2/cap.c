#include <stdio.h>
#include <stdbool.h>

char* cap_chars(char s[], int size);

const int MAX = 200;

int main(void)
{
    char s[MAX];
    printf("Enter sentence: ");
    fgets(s, sizeof(s), stdin);  // read string
    printf("Capitalized: %s", cap_chars(s, MAX));
    return 0;
}


char* cap_chars(char s[], int size) {
    bool first_char = true;
    for (int i = 0; i < size; i++) {
        if (s[i] == ' '){
            first_char = true;
        } else if (first_char) {
            // check for a small letter
            if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] = s[i] - 32;
            }
            first_char = false;
        }
    }
    return s;
}
