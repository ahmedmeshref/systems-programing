#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// Define global variables

const int MIN_LINE_LEN = 75;
const int MAX_LINE_LEN = 150;
const int MAX_WORDS_PER_LINE = 20;
const int MAX_WORD_LEN = 40;

int getTotalChars(FILE *fp)
{
    // seek to the end of the file
    fseek(fp, 0L, SEEK_END);
    int charsCount = ftell(fp);

    // seek to the begining of the file
    rewind(fp);

    return charsCount;
}

int countWords(char buffer[], int fd[])
{

    char *pch;
    char words[MAX_WORDS_PER_LINE][MAX_WORD_LEN];
    int wordsCounter[MAX_WORDS_PER_LINE];
    int curr_ind = 0;

    // extract words from the buffer.
    pch = strtok(buffer, " ");

    // read the buffer's content word by word.
    while (pch != NULL)
    {
        // word is unique by default (not seen before).
        int isUnique = 1;
        // compare word to all previous seen words, in the words array.
        for (int i = 0; i < curr_ind; i++)
        {
            if (strcmp(words[i], pch) == 0)
            {
                wordsCounter[i]++;
                isUnique = 0;
                break;
            }
        }
        // if the word is unique, not seen before.
        if (isUnique)
        {
            strcpy(words[curr_ind], pch);
            wordsCounter[curr_ind] = 1;
            curr_ind++;
        }

        // set pch to next word.
        pch = strtok(NULL, " ");
    }

    /* write results in the pipe. */
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
    char buffer[MAX_LINE_LEN];
    int currLine = 0;
    FILE *ptr;

    // open a file for reading
    ptr = fopen("file.txt", "r");

    // check if pointer maps to the file correctly
    if (ptr == NULL)
    {
        printf("Unable to open the file.");
        return 1;
    }

    // get total number of chars in a file
    int totChars = getTotalChars(ptr);

    // count the number of pipes/forks needed. (Each line should have max of 75 chars)
    int maxLines = (totChars / MIN_LINE_LEN) + 1;

    printf("Number of lines in your file: %d\n", maxLines);

    // create n pipes. (1 for each line -child process-)
    int fd[maxLines][2];

    // read the file content by file
    while (fgets(buffer, MAX_LINE_LEN - 1, ptr))
    {
        // check if the pipe creation failed.
        if (pipe(fd[currLine]) == -1)
        {
            printf("Pipe Creation Failed");
            return 1;
        }
        // Remove trailing newline
        buffer[strcspn(buffer, "\n")] = 0;

        // create new process
        // create a new child process
        pid_t pid = fork();

        // creation of child process faild.
        if (pid < 0)
        {
            printf("fork Creation Failed");
            return 1;
        }
        // child process: count the number of unique words in giving line.
        else if (pid == 0)
        {
            // printf("Curr_pipe: %d\n", currLine);
            // printf("buffer: %s\n", buffer);
            countWords(buffer, fd[currLine]);
        }

        currLine++;
    }

    // Wait for all child processes to send data
    wait(NULL);

    /* combine the content of all pipes. */
    // define vars  
    char allWords[200][MAX_WORD_LEN];
    int allWordsCount[200];
    int wordsLastIndex = 0;

    // read the content of each pipe  
    for (int i = 0; i < currLine; i++)
    {
        int last_ind;
        char words[MAX_WORDS_PER_LINE][MAX_WORD_LEN];
        int wordsCount[MAX_WORDS_PER_LINE];
        // close writing end of the pipe
        close(fd[i][1]);

        // read data from pipes
        read(fd[i][0], &last_ind, sizeof(int));
        read(fd[i][0], words, sizeof(words));
        read(fd[i][0], wordsCount, sizeof(wordsCount));

        // close reading end of the pipe
        close(fd[i][0]);

        // print unqiue words and their number of occurance
        for (int i = 0; i < last_ind; i++)
        {
            int seen = 0;
            // look for the word in all seen words (ALL_WORDS)
            for (int j = 0; j < wordsLastIndex; j++)
            {
                if (strcmp(words[i], allWords[j]) == 0)
                {
                    allWordsCount[j] += wordsCount[i];
                    seen = 1;
                    break;
                }
            }
            if (!seen)
            {
                allWordsCount[wordsLastIndex] = wordsCount[i];
                strcpy(allWords[wordsLastIndex], words[i]);
                wordsLastIndex++;
            }
        }
    }

    // print all found words alongside with their occurance
    for (int i = 0; i < wordsLastIndex; i++)
    {
        printf("%s: %d\n", allWords[i], allWordsCount[i]);
    }

    return 0;
}
