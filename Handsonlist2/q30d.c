
/*
========================================================================================================
Name : Q30d.c
Author : Rohit Bansal
Description : Write a program to create a shared memory.
		d. remove the shared memory
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
    int shmid = shmget(key, 1024, 0);
    int a = shmctl(shmid, IPC_RMID, NULL);
    if(a!=-1) printf("Removal Successful");

    return (0);
}
/*
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# gcc q30d.c -o q30d
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# ./q30d
Removal Successful%                                                                                                          
*/