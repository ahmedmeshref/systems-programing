/*
 * Write a simple program that asks the user for their age. Create a thread to 
 *  print the age and the age should be passed to the created thread as the argument.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int get_age(void)
{
    int num;
    int result;

    while (1)
    {
        printf("Enter your age: ");
        result = scanf("%d", &num);
        if (result == 0)
        {
            // find the new line to recieve new input
            while (fgetc(stdin) != '\n');
        }
        else
        {
            if (num > 0)
                break;
        }
        printf("Error, please enter a positive number.\n");
    }
    return num;
}

void *printAge(void *age)
{
    int user_age = *((int *)age);

    // print the age variable
    printf("Age: %d\n", user_age);
}

int main(void)
{
    pthread_t thread_id;

    // get age from user input
    int age = get_age();

    // pass age to a thread
    if (pthread_create(&thread_id, NULL, printAge, &age) != 0)
    {
        printf("Faild to create thread!\n");
        return 1;
    }

    // wait for the thread to finish executation
    pthread_join(thread_id, NULL);

    return 0;
}