/*
========================================================================================================
Name : Q4.c
Author : Rohit Bansal
Description : Write a program to measure how much time is taken to execute 100 getppid() system call. Use time stamp counter.
Date: 20 Sept, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <stdint.h>
#include <unistd.h> 

uint64_t rdtsc() {
    unsigned int lo, hi;
    
    __asm__ __volatile__ (
        "rdtsc"
        : "=a" (lo), "=d" (hi) 
    );

    return ((uint64_t)hi << 32) | lo;
}

int main(){

 int start, end;
 
 start = rdtsc();
 
 for(int i=1;i<=100;i++){
    getpid();
 }
 
 end = rdtsc();
 
 printf("Total cycles: %d", end-start);
 
 return 0;
}

/*
Output:
Total cycles: 1048
*/