#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int createProcesses(int n)
{
    // create n (num_threads) new processes
    for (int i = 0; i < n; i++)
    {
        pid_t id = fork();
        if (id == 0) // creation of child process successed.
        {
            printf("Child process -> pid: %d | parent pid: %d.\n", getpid(), getppid());
            exit(0);
        }
        else if (id < 0) // creation of child process failed.
        {
            printf("Error, faild to create a child process.\n");
            return 1;
        }
    }
}

int createNestedProcesses(int n)
{
    if (n == 0) // base case (last child).
    {
        printf("Last process. parent pid: %d.\n", getppid());
        return 0;
    }
    // create a new processes
    pid_t id = fork();
    if (id == 0) // child process.
    {
        printf("Child process num %d -> pid: %d | parent pid: %d.\n", n, getpid(), getppid());
        // recursivly call the createNestedProcesses function to create n nested processes
        createNestedProcesses(n - 1);
        printf("Exit -> Child process num %d -> pid: %d | parent pid: %d.\n", n, getpid(), getppid());
        exit(0);
    }
    else if (id < 0) // creation of child process failed.
    {
        printf("Error, faild to create a process.\n");
        return 1;
    }
    else  // parent process
    {
        wait(NULL);
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Error: too few arguments, number of processes to create is missing.\n");
        return 1;
    }

    pid_t wpid;
    int status = 0;

    int num_process = atoi(argv[1]);

    printf("---------- Creating %d Processes by parent: %d ----------\n", num_process, getpid());
    createProcesses(num_process);
    while ((wpid = wait(&status)) > 0); // wait for processes to finish executation
    printf("---------- Done creating %d processes by parent: %d ----------\n", num_process, getpid());

    printf("---------- Creating %d chained Processes by parent: %d ----------\n", num_process, getpid());
    createNestedProcesses(num_process);
    printf("---------- Done creating %d chained processes by parent: %d  ----------\n\n", num_process, getpid());

    return 0;
}