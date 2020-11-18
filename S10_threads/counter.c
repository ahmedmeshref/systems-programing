#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// global var to be stored in the queue and be accessed by main process & threads
long int a = 0;
pthread_mutex_t lock;

// A normal C function that is executed as a thread
void *threadfunc(void *vargb)
{
    int localA = 0;
    for (int i = 0; i < 50000; i++)
    {
        localA += i;
    }
    // obtain the lock
    pthread_mutex_lock(&lock);
    a += localA;    
    // release the lock
    pthread_mutex_unlock(&lock);
    return 0;
}

void *threadfunc2(void *vargb)
{
    int localA = 0;
    for (int i = 0; i < 50000; i++)
    {
        localA += i;
    }
    // obtain the lock
    pthread_mutex_lock(&lock);
    a += localA;
    // release the lock
    pthread_mutex_unlock(&lock);
    return 0;
}

int main(void)
{
    pthread_t id_1, id_2;
    int i;
    a = 0;

    //pthread_create(address_to_thread, attributes, function_name, arguments_passed_to_func)
    if (pthread_create(&id_1, NULL, threadfunc, NULL) != 0)
    {
        printf("Failed to create thread 1.\n");
        return 1;
    }
    if (pthread_create(&id_2, NULL, threadfunc2, NULL) != 0)
    {
        printf("Failed to create thread 2.\n");
        return 2;
    }

    // The pthread_join() function makes the program stops in order
    // to wait for the end of the selected thread, similar to wait().
    pthread_join(id_1, NULL);
    pthread_join(id_2, NULL);

    printf("A: %ld\n", a);
    return 0;
}