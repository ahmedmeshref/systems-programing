# include <stdio.h>

// typedef struct
// {
//     /* data */
//     char *name;
//     float grade;
// }
// student;


// int main (void)
// {
//     student alu_students[2];
//     alu_students[0].name = "Ahmed";
//     alu_students[0].grade = 120.6;
//     printf("%s\n", alu_students[0].name);
// }


int main (void)
{
    int a = 10;
    int *p;
    p = &a;
    printf("%d\n", *p);
}