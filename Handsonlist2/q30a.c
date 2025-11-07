

/*
========================================================================================================
Name : Q30a.c
Author : Rohit Bansal
Description : Write a program to create a shared memory.
		a. Write some data to the shared memory
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
    printf("Enter text to put in shared memory: ");
    scanf("%[^\n]s", data);
    
    printf("Write successful\n");
    
    return(0);
}
/*
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# gcc q30a.c -o q30a
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# ./q30a            
Enter text to put in shared memory: sarthak goyal
Write successful
*/