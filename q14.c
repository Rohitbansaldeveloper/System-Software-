
/*
========================================================================================================
Name : Q14.c
Author : Rohit Bansal
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on the monitor.
Date: 27 Sept, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
int fd[2];
pipe(fd);
printf("pipe created with fd[0]=%d and with fd[1]=%d \n",fd[0],fd[1]);
char arr[50];
write(fd[1], "sarthak goyal ", sizeof("sarthak goyal"));
read(fd[0], arr, sizeof(arr));
printf("%s",arr);
getchar();
}

/*
pipe created with fd[0]=3 and with fd[1]=4 
rohit bansal 
*/