// Write a program in C to replace a specific line with another text in a file
// Input the file name to be opened : test.txt

// Input the content of the new line : Yes, I am the new text instead of test line 2

// Input the line no you want to replace : 2

#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>

int get_positive_number(void);
void replace_line (char* fName, char* newLine, int lineNum);

int main(void)
{   
    // get fileName 
    char fName[30];
    printf("Input the file name to be opened: ");
    fgets(fName, sizeof(fName), stdin);

    // get new line text
    char text[500];
    printf("Input the content of the new line: ");
    fgets(text, sizeof(text), stdin);

    // get line number
    int lineNum = get_positive_number();

    replace_line(fName, text, lineNum);
    return 0;
}

void replace_line (char* fName, char* newLine, int lineNum)
{
    FILE* ptr = fopen(fName, "r");
    if (ptr == NULL)
    {
        printf("file failed to open.");
        return 1;
    }
    // open a temp file and write all lines except the lineNum -> write newLine 
    // remove(ptr);
    // replace the name of the temp to the fName
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



