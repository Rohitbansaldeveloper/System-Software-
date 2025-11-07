
/*
========================================================================================================
Name : Q26.c
Author : Rohit Bansal
Description : Write a program to send messages to the message queue. Check $ipcs -q.
Date: 21 Sept, 2025.
========================================================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

struct msgbuf {
    long mtype;
    char mtext[80];
};

int main()
{
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, IPC_CREAT | 0666);

    struct msgbuf message;
    message.mtype = 10;

    printf("Enter message:\n");
    fgets(message.mtext, sizeof(message.mtext), stdin);

    size_t len = strlen(message.mtext);
    if (len > 0 && message.mtext[len - 1] == '\n')
        message.mtext[len - 1] = '\0';

    msgsnd(msqid, &message, strlen(message.mtext) + 1, 0);
    printf("Message sent successfully\n");

    return 0;
}
/*
Enter message:
sarthak goyal
Message sent successfully
*/