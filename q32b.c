
/*
========================================================================================================
Name : Q32b.c
Author : Rohit Bansal
Description : Write a program to implement semaphore to protect any critical section.
		b. protect shared memory from concurrent write access
Date:    27 Sept, 2025.
========================================================================================================
*/  
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>   
#include <sys/stat.h>
#include <string.h>

#define NUM_THREADS 3
#define SEM_NAME "/c32b_ticket_sem" 

int shared_memory = 0;
sem_t *semaphore;

void* write_to_shared_memory(void *arg) {
    int tid = *(int*)arg;

    printf("Thread %d is waiting to write to shared memory.\n", tid);
    sem_wait(semaphore);
    int temp = shared_memory;
    printf("Thread %d reads shared memory: %d\n", tid, temp);
    sleep(1);                       
    temp += 10;
    shared_memory = temp;
    printf("Thread %d writes to shared memory: %d\n", tid, shared_memory);
    sem_post(semaphore);      

    return NULL;
}

int main(void) {
    pthread_t threads[NUM_THREADS];
    int tid[NUM_THREADS];

    sem_unlink(SEM_NAME); 
    semaphore = sem_open(SEM_NAME, O_CREAT | O_EXCL, 0600, 1);
    if (semaphore == SEM_FAILED) {
        perror("sem_open");
        return 1;
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        tid[i] = i;
        pthread_create(&threads[i], NULL, write_to_shared_memory, &tid[i]);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_close(semaphore);
    sem_unlink(SEM_NAME);
    return 0;
}
/
/*
========================================================================================================
Output:

==Thread 0 is waiting to write to shared memory.
Thread 0 reads shared memory: 0
Thread 1 is waiting to write to shared memory.
Thread 1 reads shared memory: 0
Thread 2 is waiting to write to shared memory.
Thread 2 reads shared memory: 0
Thread 1 writes to shared memory: 10
Thread 0 writes to shared memory: 10
Thread 2 writes to shared memory: 10
======================================================================================================
*/   