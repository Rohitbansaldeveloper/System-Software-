/*
========================================================================================================
Name : Q11.c
Author : Rohit Bansal
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - use sigaction system call.
Date: 21 Sept, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

int main(void) {
    struct sigaction sa;

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = SIG_IGN;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    printf("Ignoring SIGINT for 10 seconds\n");
    sigaction(SIGINT, &sa, NULL);

    sleep(10);

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = SIG_DFL;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    printf("\nRestored default handler for SIGINT\n");
    sigaction(SIGINT, &sa, NULL);

    for (;;) {
        pause();
    }

    return 0;
}
/*
Ignoring SIGINT for 10 seconds

Restored default handler for SIGINT
^C*/
