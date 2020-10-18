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



// void change_val (int *p)
// {
//     int q = 10;
//     printf("Add in fun %p\n", p);
//     p = &q;
//     // note when I enter p = *q, it changes everything 
// }

// int main (void)
// {
//     int a = 50;
//     int *p;
//     p = &a;
//     change_val(p);
//     printf("Add outside %p\n", p);
//     printf("%d\n", *p);
// }


// int main (void)
// {
//     char pt[] = "Happy";

//     char *ptr = pt;

//     while (*ptr != '\0')
//     {
//         printf("%c", ++*ptr++);
//     }
//     printf("\n");
//     return 0;
// }

int main (void)
{
    int a = 10, b = 20, *p, s= 0;

    p = &a;
    a++;

    (*p)++;
    s = a + b + *p;
    
    printf("%d\n", s);
    return 0;
}