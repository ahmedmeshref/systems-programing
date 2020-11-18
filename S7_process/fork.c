#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/*
Note:
- The main Fork's return value is the child id, the child's return val is 0
*/

int main ()
{
    printf("Hello from the main, %d\n",  getpid());

    for (int i = 0; i < 3; i++)
    {
        if (fork() == 0) {
            // child work
            printf("Hello World, %d\n", getpid());
            return 'c';
        }
    }

    // the parent work 
    printf("I am done, %d. Waiting for child to end\n", (int) getpid ());
    wait(NULL);
    printf("parent ending\n");
    return 0;
}


// int main() 
// { 
//     printf("Main is running from %d\n", (int) getpid());
//     for (int i =0; i < 2; i++)
//     {
//         fork(); 
//         printf("hello from %d\n", (int) getpid()); 

//         // if (fork() == 0) {
//         //     printf("hello from %d\n", (int) getpid()); 
//         // }
//     }

//     return 0; 
// } 