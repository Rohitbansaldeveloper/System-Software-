
/*
========================================================================================================
Name : Q31.c
Author : Rohit Bansal
Description : Write a program to create a semaphore and initialize value to the semaphore.
		a. Create a binary semaphore.
		b. Create a counting semaphore.
Date: 21 Sept, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>

#ifndef __APPLE__
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};
#endif

int main(void)
{
    union semun arg;
    key_t k = ftok(".", 'a');
    int semid = semget(k, 1, IPC_CREAT | 0666);

    int choice;
    printf("Choose an option:\n1.) Binary Semaphore\n2.) Counting Semaphore\n=> ");
    scanf("%d", &choice);

    if (choice == 1) {
        arg.val = 1;
    } else if (choice == 2) {
        arg.val = 5;
    }

    semctl(semid, 0, SETVAL, arg);
    int val = semctl(semid, 0, GETVAL);

    printf("Semaphore created: id=%d, value=%d\n", semid, val);
    return 0;
}

/*
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# gcc q31.c
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# ./a.out    
Choose an option:
1.) Binary Semaphore
2.) Counting Semaphore
=> 1
Semaphore created: id=65536, value=1
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# gcc q31.c
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# ./a.out  
Choose an option:
1.) Binary Semaphore
2.) Counting Semaphore
=> 2
Semaphore created: id=65536, value=5
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# 
*/