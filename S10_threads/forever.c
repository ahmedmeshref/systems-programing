#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *func1(void *vargb)
{
    printf("Func 1 is running.\n");
}

void *func2(void *vargb)
{
    printf("Func 2 is running.\n");
}

int main(void)
{
    pthread_t threads[2];

    for (int i = 1; i < 1000; i++)
    {
        sleep(2);
        pthread_create(&threads[0], NULL, func1, NULL);
        pthread_create(&threads[1], NULL, func2, NULL);
        printf("Finished running for %d times.\n", i);
    }
}