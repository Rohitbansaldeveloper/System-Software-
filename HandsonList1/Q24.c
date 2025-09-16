/*
============================================================================
Name : Q24.c
Author : Rohit Bansal
Description :Write a program to create an orphan process.
Date: 30th Aug, 2025.
============================================================================
*/
#include<stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>

int main() 
{ 
           
    int pid = fork(); 
  
    if (pid > 0) {
        printf("inside parent pid= %d\n", getpid());
        printf("child pid= %d\n", pid);
       } 
    else if (pid == 0) 
    { 
        printf("inside child pid= %d\n", getpid());
        sleep(10);
        exit(EXIT_SUCCESS);
    }
    return 0; 
} 
/*
Output:
inside parent pid= 14423
child pid= 14424
inside child pid= 14424

*/
