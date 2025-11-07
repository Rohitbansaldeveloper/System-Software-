/*
========================================================================================================
Name : Q9.c
Author : Rohit Bansal
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - Use signal system call.
Date: 30 Sept, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigintHandler(int signal) {
    printf("SIGINT is ignored for now...\n");
}

int main() {
    signal(SIGINT, SIG_IGN);
    printf("SIGINT is ignored. Please wait for 10 seconds \n");
    sleep(5);
    printf("Now resetting SIGINT. Press Ctrl+C to terminate.\n");
    signal(SIGINT, SIG_DFL);

    sleep(5);

}
/*
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# gcc q9.c
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2#./a.out
SIGINT is ignored. Please wait for 10 seconds 
Now resetting SIGINT. Press Ctrl+C to terminate.
*/