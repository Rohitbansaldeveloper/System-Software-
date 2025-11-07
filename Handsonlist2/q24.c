
/*
========================================================================================================
Name : Q24.c
Author : Rohit Bansal
Description : Write a program to create a message queue and print the key and message queue id.
Date: 21 Sept, 2025.
========================================================================================================
*/
 #include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

int main()
{
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, IPC_CREAT | 0666);
    printf("Key: %d, ID: %d\n", key, msqid);
    return(0);
}
/*
Key: 1627705193, ID: 65536
*/