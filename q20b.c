/*
========================================================================================================
Name : Q20b.c
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

int main() {
    char buf[100];

 
    int fd = open("myfifo", O_RDONLY);

    read(fd, buf, sizeof(buf));

    printf("%s\n", buf);

    close(fd);
    return 0;
}
/*
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# gcc q20b.c -o q20b
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# ./q20b
Hello from Writer via FIFO
*/