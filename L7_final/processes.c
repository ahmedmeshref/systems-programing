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
            printf("hello. My pid: %d\n", getpid());
            exit(0);
        }
        else if (id < 0) // creation of child process failed.
        {
            printf("Error, faild to create a process.\n");
            return 1;
        }
    }

    wait(NULL);  // wait for processes to finish executation

    return 0;
}

int createNestedProcesses(int n)
{
    if (n == 0)  // base case (last child).
    {
        printf("Hello From the last child process.\n");
        exit(0);
    }
    // create a new processes
    pid_t id = fork();
    if (id == 0) // creation of child process successed.
    {
        // recursivly call the createNestedProcesses function to create n nested processes 
        createNestedProcesses(n - 1);
        exit(0);
    }
    else if (id < 0) // creation of child process failed.
    {
        printf("Error, faild to create a process.\n");
        return 1;
    }

    wait(NULL);  // wait for processes to end
}

int main(int argc, char **argv)
{
    if (argc < 2)  
    {
        printf("Error: too few arguments, number of processes to create is missing.\n");
        return 1;
    }

    int num_process = atoi(argv[1]);

    printf("--------------------- Num Of Processes: %d ---------------------\n", num_process);

    createProcesses(num_process);
    createNestedProcesses(num_process);
    
    return 0;
}