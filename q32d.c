
/*
========================================================================================================
Name : Q32d.c
Author : Rohit Bansal
Description : Write a program to implement semaphore to protect any critical section.
		d. remove the created semaphore
Date: 29 Sept, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

#define NUM_THREADS 3
#define SEM_NAME "/resource_semaphore"

sem_t *resource_semaphore;

void* use_resource(void *arg) {
    long tid = (long)arg;
    printf("Thread %ld is waiting to access a resource.\n", tid);
    sem_wait(resource_semaphore);
    printf("Thread %ld has acquired a resource.\n", tid);
    sleep(2);
    printf("Thread %ld is releasing the resource.\n", tid);
    sem_post(resource_semaphore);
    return NULL;
}

int main() {
    sem_unlink(SEM_NAME);
    resource_semaphore = sem_open(SEM_NAME, O_CREAT | O_EXCL, 0600, 2);
    if (resource_semaphore == SEM_FAILED) {
        perror("sem_open failed");
        exit(1);
    }

    pthread_t threads[NUM_THREADS];
    for (long i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, use_resource, (void*)i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_close(resource_semaphore);
    sem_unlink(SEM_NAME);
    printf("Semaphore is successfully destroyed\n");
    return 0;
}
/*
Thread 0 is waiting to access a resource.
Thread 2 is waiting to access a resource.
Thread 1 is waiting to access a resource.
Thread 0 has acquired a resource.
Thread 2 has acquired a resource.
Thread 0 is releasing the resource.
Thread 2 is releasing the resource.
Thread 1 has acquired a resource.
Thread 1 is releasing the resource.
Semaphore is successfully destroyed
*/