/*
 * Write a C program that will catch this signal and run your defined signal handler.
 *  The program should not terminate when Ctrl+Z is pressed. It prints a message and
 *  continues execution.
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigtsip(int signal)
{
    printf("\nsignal %d was caught.\n", signal);
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