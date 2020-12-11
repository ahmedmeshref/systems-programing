#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// Define global variables
enum
{
    MAXWORDS = 300,
    MAXWORDLEN = 50
};

int words_occurance(char fName[], int fd[])
{
    FILE *ptr;
    char words[MAXWORDS][MAXWORDLEN];
    char word[MAXWORDLEN];
    int wordsCounter[MAXWORDS];
    int curr_ind = 0;

    // open the file
    ptr = fopen(fName, "r");

    // check if pointer maps to the file correctly
    if (ptr == NULL)
    {
        printf("Unable to open the file.");
        return 1;
    }

    // read file content and count the occurence of each word
    while (fscanf(ptr, "%s", word) != EOF)
    {
        // word is unique by default (not seen before).
        int isUnique = 1;
        // compare word to all previous seen words, in the words array.
        for (int i = 0; i < curr_ind; i++)
        {
            if (strcmp(words[i], word) == 0)
            {
                wordsCounter[i]++;
                isUnique = 0;
                break;
            }
        }
        // if the word is unique, not seen before.
        if (isUnique)
        {
            strcpy(words[curr_ind], word);
            wordsCounter[curr_ind] = 1;
            curr_ind++;
        }
    }

    // close the file
    fclose(ptr);
    printf("File closed successfully\n");

    /* store results in the pipe. */
    // close reading end of first pipe.
    close(fd[0]);

    // write the last index in words array into pipe
    write(fd[1], &curr_ind, sizeof(int));
    // Write the words array into pipe
    write(fd[1], words, sizeof(words));
    // write the words' counts array into pipe
    write(fd[1], wordsCounter, sizeof(wordsCounter));

    // Close writing end of pipe
    close(fd[1]);
    exit(0);
}

int main(void)
{
    int fd[2];
    pid_t id;

    // check if the pipe creation failed.
    if (pipe(fd) == -1)
    {
        printf("Pipe Creation Failed");
        return 1;
    }

    // create a new child process
    id = fork();

    // creation of child process faild.
    if (id < 0)
    {
        printf("fork Creation Failed");
        return 1;
    }
    // child process for opening a giving file and counting the words occurance.
    else if (id == 0)
    {
        // get fileName
        char fName[50];
        printf("File Name: ");
        scanf("%s", fName);

        // call teh words_occurance function
        words_occurance(fName, fd);
    }
    // parent process to read the occurance from the pipe
    else
    {
        int last_ind;
        char words[MAXWORDS][MAXWORDLEN];
        int wordsCount[MAXWORDS];

        // Wait for child to send data
        wait(NULL);

        // close writing end of the pipe
        close(fd[1]);

        // read data from pipes
        read(fd[0], &last_ind, sizeof(int));
        read(fd[0], words, sizeof(words));
        read(fd[0], wordsCount, sizeof(wordsCount));

        // close reading end of the pipe
        close(fd[0]);

        // print unqiue words and their number of occurance
        for (int i = 0; i < last_ind; i++)
        {
            printf("%s: %d\n", words[i], wordsCount[i]);
        }
    }

    return 0;
}
