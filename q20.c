
/*
========================================================================================================
Name : Q20.c
Author : Rohit Bansal
Description : Write two programs so that both can communicate by FIFO - Use one way communication.
Date: 21 Sept, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    int a = 0;
    printf("1.\t write (program 1)\n2.\t read (program 2)\n\t Enter choice: ");
    scanf("%d", &a);
    int fd = -1;

    switch (a)
    {
    case 1:
        fd = open("myFifo", O_WRONLY, 0666);
        write(fd, "Hello from writer\n", sizeof("Hello from writer\n"));
        close(fd);
        break;
    case 2:
        fd = open("myFifo", O_RDONLY, 0666);
        char buf[100];
        read(fd, buf, sizeof(buf));
        printf("Message from writer: %s", buf);
        close(fd);
        break;

    default:
        printf("Choose a valid choice\n");
        break;
    }

    return (0);
}
/*
Output:
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# q20a.c -o 20a
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# gcc  q20a.c -o q20a
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# gcc q20b.c -o q20b
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# ./q20a
Message sent to FIFO by writer

root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# ./q20b
Hello from Writer via FIFO

*/
