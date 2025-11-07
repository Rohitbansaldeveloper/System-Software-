

/*
========================================================================================================
Name : Q28.c
Author : Rohit Bansal
Description : Write a program to change the existing message queue permission (use msqid_ds structure).
Date: 21 Sept, 2025.
========================================================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

int main(void)
{
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, IPC_CREAT | 0666);
    struct msqid_ds st;
    msgctl(msqid, IPC_STAT, &st);
    printf("Current access Permissions - %o\n", st.msg_perm.mode);

    st.msg_perm.mode = 0777;
    msgctl(msqid, IPC_SET, &st);

    msgctl(msqid, IPC_STAT, &st);
    printf("New access Permissions - %o\n", st.msg_perm.mode);

    return 0;
}
/*
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# ./a.out  
Current access Permissions - 666
New access Permissions - 777
*/
