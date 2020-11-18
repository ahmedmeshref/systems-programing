#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    pid_t pid = fork();
    printf("Parent: %d\n", getpid());
    if (pid < 0)
    {
        printf("process creation faild.\n");
        return 1;
    }
    else if (pid == 0)
    {
        // child task 
        printf("Parent: %d\n", getpid());
        // replace existing process with a new one in ben l
        execl("/bin/ls", NULL);
    }
    else
    {
        // wait for the child to finish
        wait(NULL);
        printf("Child done.\n");
    }
}