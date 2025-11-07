/*
========================================================================================================
Name : Q32a.c
Author : Rohit Bansal
Description : Write a program to implement semaphore to protect any critical section.
		a. Rewrite the ticket number creation program using semaphore.
Date: 27 Sept, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int NUM_THREADS = 3;
int ticket_number = 0;
pthread_mutex_t lock;

void* generate_ticket(void *arg) {
    int tid = *(int*)arg;
    printf("Thread %d is waiting to generate a ticket.\n", tid);

    pthread_mutex_lock(&lock);
    ticket_number++;
    printf("Thread %d generated ticket number: %d\n", tid, ticket_number);
    pthread_mutex_unlock(&lock);

    sleep(1);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int tid[NUM_THREADS];

    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        tid[i] = i;
        pthread_create(&threads[i], NULL, generate_ticket, &tid[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    return 0;
}
/*
Thread 0 is waiting to generate a ticket.
Thread 2 is waiting to generate a ticket.
Thread 0 generated ticket number: 1
Thread 1 is waiting to generate a ticket.
Thread 2 generated ticket number: 2
Thread 1 generated ticket number: 3
*/