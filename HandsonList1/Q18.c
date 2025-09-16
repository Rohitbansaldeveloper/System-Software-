/*
============================================================================
Name : Q18.c
Author : Rohit Bansal
Description : Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 29th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

struct record
{
    int record_id;
    int value;
};

int main(int argc, char *argv[])
{

    struct record r1 = {1, 1};
    struct record r2 = {2, 2};
    struct record r3 = {3, 3};
    int fd = open(argv[1], O_WRONLY | O_CREAT, 0777);
    struct record rs[] = {r1, r2, r3};
    write(fd, &rs, sizeof(rs));
    write(fd, &rs, sizeof(rs));
    write(fd, &rs, sizeof(rs));
    
    return 0;
}


