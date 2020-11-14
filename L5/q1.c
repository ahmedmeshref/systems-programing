#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

enum
{
    MAXWORDS = 300,
    bufferLength = 255
};

int main(void)
{
    // declear all needed vars
    FILE *ptr;
    pid_t id;
    char words[MAXWORDS][50];
    char word[50];
    int counter[MAXWORDS];
    int curr_ind = 0;
    // buffer is used to hold each line's data
    char buffer[bufferLength];

    // get fileName
    char fName[50];
    printf("File Name: ");
    scanf("%s", fName);

    // open the file
    ptr = fopen(fName, "r");

    // check if pointer maps to the file correctly
    if (ptr == NULL)
    {
        printf("Unable to open the file.");
        return 1;
    }

    // fillin counter with zeros
    for (int i = 0; i < MAXWORDS; i++)
    {
        counter[i] = 0;
    }

    // read file content by words
    while (fscanf(ptr, "%s", word) != EOF)
    {
        int isUnique = 1;
        // compare word to all previous seen words stored in words
        for (int i = 0; i < curr_ind; i++)
        {
            if (strcmp(words[i], word) == 0)
            {
                counter[i]++;
                isUnique = 0;
                break;
            }
        }
        // if the word is unique - not seen before -
        if (isUnique)
        {
            strcpy(words[curr_ind], word);
            counter[curr_ind]++;
            curr_ind++;
        }
    }

    // print found words and their occurance
    for (int i = 0; i < curr_ind; i++)
    {
        printf("%s: %d\n", words[i], counter[i]);
    }

    // close the file
    fclose(ptr);
    printf("File closed successfully\n");
    return 0;
}
