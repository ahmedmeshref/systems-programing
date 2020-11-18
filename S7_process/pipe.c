//  communication between processes
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    // array to store read & write vals in pipe
    int fd[2][2];

    // create a pipe
    if (pipe(fd[0]) == -1)
    {
        printf("Error - can't create a pipe.\n");
        return 1;
    }

    // create a new child process
    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Error - can't create a child process.\n");
        return 2;
    }
    else if (pid == 0)
    {
        // write to the pipe from child
        close(fd[0][0]);
        int x;
        printf("Enter an int: ");
        scanf("%d", &x);
        // write x to pd[1]
        if (write(fd[0][1], &x, sizeof(int)) == -1)
        {
            printf("Error - can't write to the pipe.\n");
            return 3;
        }
        close(fd[0][1]);
    }
    else
    {
        // read from the pipe 
        close(fd[0][1]);
        int y;
        if (read(fd[0][0], &y, sizeof(int)) == -1)
        {
            printf("Error - can't read from the pipe.\n");
            return 4;
        }
        close(fd[0][0]);
        printf("Num: %d\n", y);
    }
}
