// use two threads to get the sum of elements in the arraay
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

const int MAXLEN = 16;
const int MAXTHREADS = 4;

int a[] = {1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 64, 110, 220};
int sum[4] = {0};
int part = 0;
// pthread_mutex_t lock;

void *getSum(void *vargb)
{
    // pthread_mutex_lock(&lock);
    // printf("Part before: %d\n", part);
    // part++;
    // printf("Part After: %d\n", part);
    // pthread_mutex_unlock(&lock);

    int thread_part = part++;

    for (int j = thread_part * (MAXLEN / MAXTHREADS); j < (thread_part + 1) * (MAXLEN / MAXTHREADS); j++)
    {
        sum[thread_part] += a[j];
    }
}

int main(void)
{
    pthread_t thread[4];

    // create all threads
    for (int i = 0; i < MAXTHREADS; i++)
        pthread_create(&thread[i], NULL, getSum, NULL);

    // join all threads
    for (int i = 0; i < MAXTHREADS; i++)
        pthread_join(thread[i], NULL);

    // collect the sum of all threads
    int tot = 0;
    for (int i = 0; i < MAXTHREADS; i++)
        tot += sum[i];

    printf("Sum: %d\n", tot);

    return 0;
}

