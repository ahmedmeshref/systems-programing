/*
 * Write a program to calculate the sum of all array elements using 2 threads.
*/
#include <stdio.h>
#include <pthread.h>

const int MAXLEN = 10;
const int MAXTHREADS = 2;

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int sum[2] = {0, 0};
int thread_num = 0;
pthread_mutex_t lock;

void *getSum(void *vargb)
{
    // obtain lock for the current thread
    pthread_mutex_lock(&lock);
    // traverse half of the array for each thread
    for (int i = thread_num * (MAXLEN / MAXTHREADS); i < (thread_num + 1) * (MAXLEN / MAXTHREADS); i++)
    {
        sum[thread_num] += arr[i];
    }
    thread_num++;
    // release the lock
    pthread_mutex_unlock(&lock);
}

int main(void)
{
    // intialize threads
    pthread_t threads[MAXTHREADS];

    // create the threads
    for (int i = 0; i < MAXTHREADS; i++)
    {
        if (pthread_create(&threads[i], NULL, getSum, NULL) != 0)
        {
            printf("Thread creation failed.\n");
            return 1;
        }
    }

    // wait for all threads
    for (int j = 0; j < MAXTHREADS; j++)
        pthread_join(threads[j], NULL);

    // sum the output from all threads
    int tot = 0;
    for (int k = 0; k < MAXTHREADS; k++)
        tot += sum[k];

    printf("Total: %d\n", tot);

    return 0;
}