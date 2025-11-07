/*
========================================================================================================
Name : Q13b.c
Author : Rohit Bansal
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program will send the signal (using kill system call). Find out whether the first program is able to catch the signal or not.
Date: 20 Sept, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    int pid;
    printf("Enter pid of process to stop\n");
    scanf("%d", &pid);

    printf("Sending SIGSTOP signal to process: %d\n", pid);
    kill(pid, SIGSTOP);

    printf("SIGSTOP signal sent\n");
 
    return (0);
}
/*
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# gcc q13b.c -o q13b
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# ./q13b 
Enter pid of process to stop
30219
Sending SIGSTOP signal to process: 30219
SIGSTOP signal sent
*/