#include <unistd.h>
/*
========================================================================================================
Name : Q13a.c
Author : Rohit Bansal
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program will send the signal (using kill system call). Find out whether the first program is able to catch the signal or not.
Date: 21 Sept, 2025.
========================================================================================================
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void catch_signal(int sig) {
    const char msg[] = "Signal caught — exiting\n";
    write(STDOUT_FILENO, msg, sizeof(msg) - 1);
    _exit(0);
}

int main(void) {
    printf("pid (receiver): %d\n", (int)getpid());

    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = catch_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);

    for (;;) {
        pause();
    }

    return 0;
}
/*
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# gcc q13a.c -o q13a
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# ./q13a
pid (receiver): 30219
*/