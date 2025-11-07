
/*
========================================================================================================
Name : Q32c.c
Author :Rohit Bansal
Description : Write a program to implement semaphore to protect any critical section.
		c. protect multiple pseudo resources ( may be two) using counting semaphore
Date: 28 Sept, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/stat.h>

#define NUM_THREADS 3

static sem_t *resource_semaphore;

void* use_resource(void* arg) {
    int tid = (int)(intptr_t)arg;

    printf("Thread %d is waiting to access a resource.\n", tid);

    sem_wait(resource_semaphore);

    printf("Thread %d has acquired a resource.\n", tid);
    sleep(2);
    printf("Thread %d is releasing the resource.\n", tid);

    sem_post(resource_semaphore);
    return NULL;
}

int main(void) {
    const char *SEM_NAME = "/resource_semaphore_example";

    resource_semaphore = sem_open(SEM_NAME, O_CREAT, 0644, 2);
    if (resource_semaphore == SEM_FAILED) {
        perror("sem_open");
        return 1;
    }

    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, use_resource, (void*)(intptr_t)i) != 0) {
            perror("pthread_create");
            return 1;
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_close(resource_semaphore);
    sem_unlink(SEM_NAME);
    return 0;
}
/*
Thread 0 is waiting to access a resource.
Thread 0 has acquired a resource.
Thread 1 is waiting to access a resource.
Thread 2 is waiting to access a resource.
Thread 1 has acquired a resource.
Thread 0 is releasing the resource.
Thread 1 is releasing the resource.
Thread 2 has acquired a resource.
Thread 2 is releasing the resource.
*/
