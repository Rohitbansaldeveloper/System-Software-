/*
========================================================================================================
Name : Q7.c
Author : Rohit Bansal
Description : Write a simple program to print the created thread ids.
Date: 23 Sept, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <pthread.h>

void* foo(void* p) {
    int threadID = *((int*)p);
    printf("Thread %d (pthread %lu) is executing\n", threadID, (unsigned long)pthread_self());
    return NULL;
}

int main(void) {
    pthread_t tid[3];
    int ids[3] = {1, 2, 3};

    pthread_create(&tid[0], NULL, foo, &ids[0]);
    pthread_create(&tid[1], NULL, foo, &ids[1]);
    pthread_create(&tid[2], NULL, foo, &ids[2]);

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_join(tid[2], NULL);

    return 0;
}
/*
Thread 1 (pthread 123145515876352) is executing
Thread 2 (pthread 123145516412928) is executing
Thread 3 (pthread 123145516949504) is executing
*/