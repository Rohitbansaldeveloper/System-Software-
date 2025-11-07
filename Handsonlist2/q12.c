/*
========================================================================================================
Name : Q12.c
Author : Rohit Bansal
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to the parent process from the child process.
Date: 21 Sept, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    
    if (!fork())
    {
        sleep(5);
        printf("Child process pid: %d\n", getpid());
        kill(getppid(), SIGKILL);
        printf("Parent process killed\n");
        sleep(10);
    }
    else
    {
        printf("Process id of Parent: %d\n", getpid());
        sleep(15);
    }

    return 0;
}
/*
Process id of Parent: 80175
Child process pid: 80177
Parent process killed
*/