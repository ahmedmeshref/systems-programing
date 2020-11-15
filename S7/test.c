#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{

    int count[10000], i = 0;
    char all_words[10000][500];
    char single_word[500];
    int x = 0;

    FILE *fileptr;

    fileptr = fopen("file.txt", "r");

    if (fileptr == NULL)
    {
        printf("File can not be opened, Please check.\n");
        exit(1);
    }

    while (fscanf(fileptr, "%s", single_word) != EOF)
    {
        bool seen = false;
        for (int i = 0; i < x && !seen; i++)
        {
            if (strcmp(all_words[i], single_word) == 0)
            {
                count[i]++;
                seen = true;
            }
        }

        if (!seen)
        {
            strcpy(all_words[x], single_word);
            count[x] = 1;
            x++;
        }
    }

    for (int k = 0; k < x; k++)
    {
        printf("%s: %d\n", all_words[k], count[k]);
    }
}