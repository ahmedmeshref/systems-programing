// Write a program in C to count the number of words and characters in a file.
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    FILE* ptr = fopen("text.txt", "r");
    if (ptr == NULL)
    {
        printf("file failed to open.");
        return 1;
    }
    // count words and chars in the file 
    int words = 0, chars = 0;
    char ch;
    bool new_word = true;
    // check for the end of the file 
    while ((ch = fgetc(ptr)) != EOF)
    {
        // if space or new line found, then a new word may exist
        if (ch == ' ' || ch == '\n') new_word = true;
        // check for only characters in the current ch  
        else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            chars++;
            if (new_word) {
                words++;
                new_word = false;
            }
        }
    }
    printf("Number of words = %d\nNumber of chars = %d\n", words, chars);  
    fclose(ptr);
    printf("The file is now closed.\n");
    return 0;
}