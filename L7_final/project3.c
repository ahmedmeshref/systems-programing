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
        if (id == 0)
        {
            // run a loop inside of the child
            printf("hello. My pid: %d\n", getpid());
            exit(0);
        }
        else if (id < 0)
        {
            printf("Error, faild to create a process.\n");
            return 1;
        }
    }
    // wait for processes to finish executation
    wait(NULL);

    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Error: Number of process to create is missing.\n");
        return 1;
    }

    int num_process = atoi(argv[1]);

    printf("Num of process: %d\n", num_process);

    createProcesses(num_process);
    return 0;
}