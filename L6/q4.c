/* 
 * Write a program to prove process creation takes more time than thread creation
*/
#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

const int MAXPROCESS = 10000;
const int MAXTHREADS = 10000;
const int MAXLOOPS = 1000;

/*
 * timeIt()
 * Description:
 * - time a process (function)
 *
 * Arguments:
 * - func: input function address
 * 
 * Return: 
 * - (double) time spent to run the input function 
*/
double timeIt(int (*func)())
{
    // to store execution time of code
    double time_spent = 0.0;

    // start timer
    clock_t begin = clock();

    // run the input function
    func();

    // end timer
    clock_t end = clock();

    // calculate difference (end - begin) and dividing the
    //  difference by CLOCKS_PER_SEC to convert to seconds
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    return time_spent;
}

void loop()
{
    for (int i = 0; i < MAXLOOPS; i++)
        continue;
}

// create n process and run a loop inside of each one of them
int createProcesses(void)
{
    // create n (MAXPROCESS) new processes
    for (int i = 0; i < MAXPROCESS; i++)
    {
        int pid = fork();
        if (pid == 0)
        {
            // run a loop inside of the child
            loop(1000);
            exit(0);
        }
        else if (pid < 0)
        {
            printf("Error, faild to create a process.\n");
            return 1;
        }
    }
    // wait for processes to finish executation
    wait(NULL);

    return 0;
}

// create n threads and run a loop inside of each one of them
int createThreads(void)
{
    pthread_t threads[MAXTHREADS];

    // create n threads
    for (int i = 0; i < MAXTHREADS; i++)
        pthread_create(&threads[i], NULL, (void *)&loop, NULL);

    // wait for threads to finish execution
    for (int j = 0; j < MAXTHREADS; j++)
        pthread_join(threads[j], NULL);

    return 0;
}

// main function to compare the execution time of processes vs threads creating.
int main()
{
    printf("Creation %d new threads took: %f\n", MAXTHREADS, timeIt(createThreads));

    printf("Creation %d new process took: %f\n", MAXPROCESS, timeIt(createProcesses));

    return 0;
}