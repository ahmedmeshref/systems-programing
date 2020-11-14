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
    printf("Hello, %d\n",  getpid());

    if (fork() == 0) {
        // child work
        printf("Hello World, %d\n", getpid());
        exit(0);
    }
    // the parent work 
    printf("I am done, %d. Waiting for child to end\n", (int) getpid ());
    wait(NULL);
    printf("parent ending\n");
    return 0;
}