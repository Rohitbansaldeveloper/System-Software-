/*
============================================================================
Name : Q17b.c
Author : Rohit Bansal
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 29th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int fd = open("/home/rohit-bansal/ticket.txt", O_RDWR);
    struct flock fl = {F_WRLCK, SEEK_SET, 0, 0, 0};
    fcntl(fd, F_SETLKW, &fl);
    printf("File is successfully locked:");

    char buffer[10];
    
    // read ticket number from file
    int n = read(fd, &buffer, 10);

    int buf_int = atoi(buffer); // increment file number from file
    buf_int += 1;
    sprintf(buffer, "%d", buf_int);//number to char array
    
    lseek(fd,0,SEEK_SET);//reset seek
    write(fd, &buffer, strlen(buffer));
    printf("%d\t \n", buf_int);
    
    printf("Press enter to unlock\n");
    
    getchar();
    
    fl.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &fl);
    printf("file is unlocked\n");
    
}
/*
Output:
File is successfully locked:1	 
Press enter to unlock

file is unlocked
*/

