
/*
========================================================================================================
Name : Q17.c
Author : Rohit Bansal
Description : Write a program to execute ls -l | wc.
		a. Use dup
		b. Use dup2
		c. Use fcntl
Date: 21 Sept, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {
    int fd[2];
    pipe(fd);

    int choice;
    printf("1. Using dup\n2. Using dup2\n3. Using fcntl\nEnter choice: ");
    scanf("%d", &choice);

    if (fork() == 0) {
        close(fd[0]);
        if (choice == 1) {
            dup(fd[1]);
        } else if (choice == 2) {
            dup2(fd[1], STDOUT_FILENO);
        } else if (choice == 3) {
            fcntl(fd[1], F_DUPFD, STDOUT_FILENO);
        }
        close(fd[1]);
        execl("/bin/ls", "ls", "-l", NULL);
        exit(1);
    } else {
        close(fd[1]);
        if (choice == 1) {
            dup(fd[0]);
        } else if (choice == 2) {
            dup2(fd[0], STDIN_FILENO);
        } else if (choice == 3) {
            fcntl(fd[0], F_DUPFD, STDIN_FILENO);
        }
        close(fd[0]);
        execl("/usr/bin/wc", "wc", NULL);
        exit(1);
    }
}
/*
1. Using dup
2. Using dup2
3. Using fcntl
Enter choice: 2
      20     173    1089
        */