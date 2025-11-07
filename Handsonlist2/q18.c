
/*
========================================================================================================
Name : Q18.c
Author : Rohit Bansal
Description : Write a program to find out total number of directories on the pwd. Execute ls -l | grep ^d | wc. Use only dup2.
Date: 21 Sept, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    int fd1[2], fd2[2];
    pipe(fd1);
    pipe(fd2);

    if (fork() == 0) {
        dup2(fd1[1], STDOUT_FILENO);
        close(fd1[0]);
        close(fd1[1]);
        close(fd2[0]);
        close(fd2[1]);
        execlp("ls", "ls", "-l", (char *)NULL);
        _exit(1);
    } else {
        if (fork() == 0) {
            dup2(fd1[0], STDIN_FILENO);
            dup2(fd2[1], STDOUT_FILENO);
            close(fd1[0]);
            close(fd1[1]);
            close(fd2[0]);
            close(fd2[1]);
            execlp("grep", "grep", "^d", (char *)NULL);
            _exit(1);
        } else {
            dup2(fd2[0], STDIN_FILENO);
            close(fd1[0]);
            close(fd1[1]);
            close(fd2[0]);
            close(fd2[1]);
            execlp("wc", "wc", "-l", (char *)NULL);
            _exit(1);
        }
    }

    return 0;
}
/*
0
*/