// Write a C program to create a file called EmplRecord.txt and store information about a person,
//  in terms of his/her name, age, and salary.
#include <stdio.h>

int main()

{
    // Declare the file pointer in the write mode
    FILE *ptr = fopen("EmplRecord.txt", "w");

    // Declar user info (name, age, salary)
    char *name = "Mohamed";
    char* age = "20";
    char* salary = "1000.0";

    // check if file exist
    if (ptr == NULL)
    {
        printf("file failed to open.");
        return 1;
    }
    // write data to the file 
    fputs(name, ptr);
    fputc('\n', ptr);
    fputs(age, ptr);
    fputc('\n', ptr);
    fputs(salary, ptr);
    fputc('\n', ptr);

    // Closing the file
    fclose(ptr);
    printf("Data successfully written in file EmplRecord.txt\n");
    printf("The file is now closed.\n");
    return 0;
}   