#include <stdio.h>

// // write to a file chars.txt
// int main (void)
// {
//     FILE* ptr = fopen("chars.txt", "w");
//     if (!ptr)
//     {
//         return 1;
//     }
//     char arr[3] = {'a', 'c', 'd'};
//     fwrite(arr, sizeof(char), 3, ptr);
//     fclose(ptr);
//     return 0;
// }

// read from chars.txt
int main (void)
{
    FILE* ptr2 = fopen("chars.txt", "r");
    if (ptr2 == NULL)
    {
        return 1;
    }
    char ch;
    while ((ch = fgetc(ptr2)) != EOF)
    {
        printf("%c\n", ch);
    }
    fclose(ptr2);
    return 0;
}