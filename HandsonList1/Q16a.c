
/*
============================================================================
Name : 16a.c
Author : Rohit Bansal
Description : Write a program to perform mandatory locking.
              a. Implement write lock b. Implement read lock
Date: 30 Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argv, char *buff[])
{
    int fd = open(buff[1], O_WRONLY);

    struct flock fl = {F_WRLCK,0,0,0,0};
    fcntl(fd, F_SETLKW, &fl);
    printf("File is locked now.\n Please press enter key to unlock file\n");
    getchar();
    fl.l_type = F_UNLCK; 
    fcntl(fd, F_SETLKW, &fl);
    return 0; 
}
/*
Output:
rohit-bansal@rohit-bansal-20YE000UIG:~/Hands-on-list-1$ ./a.out file1.txt
File is locked now.
 Please press enter key to unlock file

*/