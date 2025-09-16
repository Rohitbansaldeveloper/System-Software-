/*
============================================================================
Name : Q16b.c
Author : Rohit Bansal
Description : Write a program to perform mandatory locking.
              a. Implement write lock
              b. Implement read lock
Date: 29th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argv, char *buff[])
{
    int a = open(buff[1], O_RDONLY);

    struct flock fl = {F_RDLCK, 0, 0, 0, 0}; // set read_lock type to flock instance lock.
    fcntl(a, F_SETLKW, &fl);
    printf("File is locked now.\nPlease press enter key to unlock file\n");
    getchar();
    fl.l_type = F_UNLCK; // change lock type to unlock to unlock file
    fcntl(a, F_SETLKW, &fl);
    return 0;
}
/*
Output:
rohit-bansal@rohit-bansal-20YE000UIG:~/Hands-on-list-1$ ./a.out file1.txt
File is locked now.
Please press enter key to unlock file

*/
