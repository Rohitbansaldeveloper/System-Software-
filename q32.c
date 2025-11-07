/*
========================================================================================================
Name : Q32.c
Author : Rohit Bansal
Description : Write a program to implement semaphore to protect any critical section.
Date: 27 Sept, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t semaphore;

void* critical_section(long thread_id) {

    printf("Thread %ld is waiting to enter critical section.\n", thread_id);

    sem_wait(&semaphore);

    printf("Thread %ld has entered the critical section.\n", thread_id);

    sleep(2);

    printf("Thread %ld is leaving the critical section.\n", thread_id);
    
    sem_post(&semaphore);

    return NULL;
}

int main() {

    sem_init(&semaphore, 0, 1);

    pthread_t threads[3];
    
    for (long i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, critical_section, (void*)i);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
    sem_destroy(&semaphore);

    return 0;
}
/*
========================================================================================================
Output:


========================================================================================================
*/   