
/*
========================================================================================================
Name : Q3.c
Author : Rohit Bansal
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 20 Sept, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>

int main(void) {
    struct rlimit limit;

    limit.rlim_cur = 5;  
    limit.rlim_max = 10;  
    setrlimit(RLIMIT_CPU, &limit);
    printf("New CPU time limits:\n Soft = %llu seconds, Hard = %llu seconds\n",
           (unsigned long long)limit.rlim_cur,
           (unsigned long long)limit.rlim_max);
    volatile unsigned long counter = 0;
    while (1) {
        ++counter;
    }

}
/*Output:
New CPU time is :
 Soft limit = 5 seconds, Hard limit = 10 seconds
*/
