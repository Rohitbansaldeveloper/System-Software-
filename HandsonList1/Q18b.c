/*
============================================================================
Name : Q18.c
Author : Rohit Bansal
Description : Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 30th Aug, 2025.
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
    int fd = open("/home/rohit-bansal/Q18main.txt", O_RDONLY);
    struct flock rdlock = {F_RDLCK, SEEK_SET, 0, sizeof(struct record), getpid()};
    int record_id;
    printf("Enter record id:");
    scanf("%d", &record_id);
    if(record_id>3)printf("Record does not exist");
    else{
    rdlock.l_start = (record_id-1)*sizeof(struct record);
    rdlock.l_len = sizeof(struct record);
    fcntl(fd, F_SETLKW, &rdlock);
    printf("record %d id locked Enter to unlock it\n", record_id);
    getchar();
    getchar();
    rdlock.l_type = F_ULOCK;
    fcntl(fd, F_SETLKW, &rdlock);
    printf("record is unlocked\n");
    }
    return 0;
}
/*
Output:
Enter record id:3
record 3 id locked Enter to unlock it

record is unlocked
*/
