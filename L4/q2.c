// Write a C program to read the EmplRecord.txt file and display its 
//  contents on the console.
#include <stdio.h>

int main(void)
{
    FILE* ptr = fopen("EmplRecord.txt", "r");
    char data[500];
    if (ptr == NULL)
    {
        printf("file failed to open.");
        return 1;
    }
    while (fgets(data, 50, ptr) != NULL)
    {
        printf("%s", data);
    }
    fclose(ptr);
    printf("The file is now closed.\n");
    return 0;
}
