/*
========================================================================================================
Name : Q20a.c
Author : Rohit Bansal
Description : Write two programs so that both can communicate by FIFO -Use one way communication. 
Date: 29 Sept, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main() {

    char *buf = "Hello from Writer via FIFO\0";

    mkfifo("myfifo", 0666);

    int fd = open("myfifo", O_WRONLY);

    write(fd, buf, strlen(buf));

    printf("Message sent to FIFO by writer\n");

    close(fd);
    return 0;
}
/*
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# gcc q20a.c -o q20a
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# ./q20a
Message sent to FIFO by writer
*/