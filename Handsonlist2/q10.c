/*
========================================================================================================
Name : Q10.c
Author : Rohit Bansal
Description : Write a separate program using sigaction system call to catch the following signals.
		a. SIGSEGV
		b. SIGINT
		c. SIGFPE
Date: 21 Sept, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int sig) {
    switch(sig) {
        case SIGSEGV:
            printf("Caught signal SIGSEGV (Segmentation Fault)\n");
            exit(1);
            break;
        case SIGINT:
            printf("Caught signal SIGINT (Interrupt from keyboard)\n");
            exit(0);
            break;
        case SIGFPE:
            printf("Caught signal SIGFPE (Floating-point exception)\n");
            exit(1);
            break;
        default:
            printf("Caught unexpected signal: %d\n", sig);
            exit(1);
    }
}

int main() {
    struct sigaction sa;

    sa.sa_handler = signal_handler;
    sa.sa_flags = 0; 
    sigemptyset(&sa.sa_mask);

    int a = sigaction(SIGSEGV, &sa, NULL);
    int b =  sigaction(SIGINT, &sa, NULL);
    int c = sigaction(SIGFPE, &sa, NULL);
   
    printf("%d",a);
    printf("%d",b);
    printf("%d",c);
   
    while (1) {
        printf("Press Ctrl + C to trigger SIGINT.\n");
        sleep(1);
    }

    return 0;
}
/*
000Press Ctrl + C to trigger SIGINT.
Press Ctrl + C to trigger SIGINT.
Press Ctrl + C to trigger SIGINT.
Press Ctrl + C to trigger SIGINT.
Press Ctrl + C to trigger SIGINT.
^CCaught signal SIGINT (Interrupt from keyboard)
*/

