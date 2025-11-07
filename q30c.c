

/*
========================================================================================================
Name : Q30c.c
Author : Rohit Bansal
Description : Write a program to create a shared memory.
		c. Detach the shared memory.
Date: 29 Sept, 2025.
========================================================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main()
{
    key_t key = ftok(".", 'a');
    int shmid = shmget(key, 1024, IPC_CREAT | 0666);

    char *data = shmat(shmid, (void *)0, 0);
    printf("Detachment Successful\n");
    shmdt(data);

    return (0);
}
/*
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# gcc q30c.c -o q30c
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# ./q30c            
Detachment Successful
*/