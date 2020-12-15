#include <stdio.h>
#include <signal.h>
#include <type/bool>

// use in the toggle function 
bool CHILDRUNNING = true;

void killProcess(int dummy)
{
    printf("ctrl-z caught, killing child process");

    printf("ctrl-z caught, killing main process");
}

void toggleProcess(int p)
{
    printf("ctrl-z caught, stopping child process");

    printf("ctrl-z caught, resuming child process");
}

int main()
{
    pid_t id;

    id = fork();

    // Your main program should fork and exec a new child process to run the "yes" command.
    // which process should be always running?
    // How to pass a variable to signal handler?

    // Set the SIGTSTP (Ctrl-Z) signal handler to suspend/resume process
    signal(SIGTSTP, toggleProcess);

    // set the SIGINT (ctrl+C) to kill process or parent
    signal(SIGINT, killProcess);

    while (1)
    {
    }
}