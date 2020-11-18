#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int handle_sigtsip(int signal)
{
    printf("signal %d was caught.\n", signal);
    return 0;
}

int main(void)
{
    signal(SIGTSTP, handle_sigtsip);
    while (1)
    {
        printf("Program is executing.\n");
        sleep(1);
    }
    return 0;
}

// TODO: create a calc with threads and try to see if you can 
//  run multiple functions at once with sleep()