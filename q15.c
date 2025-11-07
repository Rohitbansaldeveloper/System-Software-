/*
========================================================================================================
Name : Q15.c
Author :Rohit Bansal
Description : Write a simple program to send some data from parent to the child process.
Date: 28 Sept, 2025.
========================================================================================================
*/
#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
int fd[2];
pipe(fd);
if(!fork())
{
  int i=100;
close(fd[0]);
printf("writing to pipe after closing the fd[0] \n");
write(fd[1],&i,sizeof(i));
}
else
{
printf("in parent process ");
int  j;
close(fd[1]);
read(fd[0],&j,sizeof(j));
printf("data from child is %d",j);
}
}
/*
writing to pipe after closing the fd[0] 
in parent process data from child is 100% 
*/

