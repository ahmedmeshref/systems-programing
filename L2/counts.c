#include <stdio.h>
#include <string.h>

// prototype
int* count_chars(char sentence[]);

int main(void)
{
    char sentence[100];
    printf("Enter sentence: ");
    fgets(sentence, sizeof(sentence), stdin);  // read string
    int* out = count_chars(sentence);
    printf("UpperCase: %d\nLowerCase: %d\nSpecial Chars: %d\n", out[0], out[1], out[2]);
    return 0;
}


int* count_chars(char sentence[])
{
    // res = [upperCase, lowerCase, specialChars]
    static int res[3] = {0, 0, 0};
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] >= 'A' && sentence[i] <= 'Z') res[0]++;
        else if (sentence[i] >= 'a' && sentence[i] <= 'z') res[1]++;
        else if (sentence[i] >= '0' && sentence[i] <= '9') continue;
        else if (sentence[i] != '\n' && sentence[i] != ' ') res[2]++;
    }
    return res;
}