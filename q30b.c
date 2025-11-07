
/*
========================================================================================================
Name : Q30b.c
Author : Rohit Bansal
Description : Write a program to create a shared memory.
		b. Attach with O_RDONLY and check whether you are able to overwrite.
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

    char *data = shmat(shmid, (void *)0, SHM_RDONLY);
    printf("Enter text to put in shared memory: ");
    scanf("%[^\n]s", data);

    printf("Write successful\n");
    shmdt(data);
    return (0);
}
/*
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# gcc q30b.c -o q30b
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# ./q30b            
Enter text to put in shared memory: sarthak
zsh: bus error  ./q30b
*/