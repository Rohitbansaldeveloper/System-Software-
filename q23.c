/*
========================================================================================================
Name : Q23.c
Author : Rohit Bansal
Description : Write a program to print the maximum number of files that can be opened within a process and size of a pipe (circular buffer).
Date: 21 Sept, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){
    int PIPE_BUF, OPEN_MAX;
    
    PIPE_BUF = pathconf(".", _PC_PIPE_BUF);
    OPEN_MAX = sysconf(_SC_OPEN_MAX);

    printf("SIze of pipe is = %d\nMax number of files that can be opened are = %d\n", PIPE_BUF, OPEN_MAX);
    
    return(0);
}

/*
SIze of pipe is = 512
Max number of files that can be opened are = 256            
*/