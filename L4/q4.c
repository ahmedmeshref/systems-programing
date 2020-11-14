// Write a program in C to replace a specific line with another text in a file

#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>

int get_positive_number(void);
int replace_line (char fName[], char newLine[], int lineNum);

int main(void)
{   
     // get new line text
    char text[255];
    printf("Input the content of the new line: ");
    fgets(text, sizeof(text), stdin);

    // get fileName 
    char fName[30];
    printf("Input the file name to be opened: ");
    scanf("%s", fName);

    // get line number
    int lineNum = get_positive_number();

    // repalce line and return 0 if successful, 1 otherwise.
    if (replace_line(fName, text, lineNum) == 1) return 1;
    else return 0;
}

int replace_line (char fName[], char newLine[], int lineNum)
{
    // open the main file in read mode
    FILE* ptr = fopen(fName, "r");
    if (ptr == NULL)
    {
        printf("Input file failed to open.\n");
        return 1;
    }
    // create a new file with temp name to save the new data
    char tempName[] = "file.txt";
    FILE* ptr_2 = fopen(tempName, "w");
    if (ptr_2 == NULL)
    {
        printf("Output file failed to open.\n");
        return 1;
    }
    
    // create a buffer to hold each line's data
    int bufferLength = 255;
    char buffer[bufferLength];
    int currentLineNum = 1;
    while (fgets(buffer, bufferLength, ptr)) {
        if (currentLineNum == lineNum) fputs(newLine, ptr_2);
        else fputs(buffer, ptr_2);
        currentLineNum++;
    }
    // if the line was not added, add it on a new line at the end of the temp file. 
    if (currentLineNum < lineNum) {
        fputc('\n', ptr_2);
        fputs(newLine, ptr_2);
    }

    // close all files
    fclose(ptr);
    fclose(ptr_2);
    // remove the old file
    remove(fName);
    // rename the temp file to have the name of the deleted file
    rename(tempName, fName);
    printf("Replacement did successfully..!!\n");
    return 0;
}


int get_positive_number(void)
{
    int num;
    int result;

    while (1) {
        printf("Positive Number: ");
        result = scanf("%d", &num);
        if (result == 0) {
            // find the new line to recieve new input
            while(fgetc(stdin) != '\n');
        }
        if (num > 0) {
            break;
        } else {
            printf("Error, please enter a positive number.\n");
        }
    }
    return num;
}



