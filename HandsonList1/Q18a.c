/*
============================================================================
Name : Q18.c
Author : Rohit Bansal
Description : Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

struct record
{
    int record_id;
    int value;
};

int main()
{
    int fd = open("/home/rohit-bansal/Q18main.txt", O_RDWR);
    struct flock wrlock = {F_WRLCK, SEEK_SET, 0, sizeof(struct record), getpid()};
    int record_id;
    printf("Enter record id:");
    scanf("%d", &record_id);
    if(record_id>3)printf("Record does not exist");
    else{
    wrlock.l_start = (record_id-1)*sizeof(struct record);
    wrlock.l_len = sizeof(struct record);
    fcntl(fd, F_SETLKW, &wrlock);
    printf("record %d is locked\nEnter to unlock it\n", record_id);
    getchar();
    getchar();
    wrlock.l_type = F_ULOCK;
    fcntl(fd, F_SETLKW, &wrlock);
    printf("record %d is unlocked\n",record_id);
    }
    return 0;
}
/*
Output:
Enter record id:2
record 2 is locked
Enter to unlock it

record 2 is unlocked
*/
