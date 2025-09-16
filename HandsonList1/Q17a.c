/*
============================================================================
Name : Q17a.c
Author : Rohit Bansal
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 28th Aug, 2024.
============================================================================
*/
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

struct ticket{
 int ticket_num;
};

int main(int argc, char *buff[])
{

    int a = open(buff[1], O_RDWR | O_CREAT,0644);
    if (a == -1)
    {
        perror("Error in opening file!");
        return 0;
    }
    struct ticket t; 
    int num;
    printf("Enter ticket number:\t");
    scanf("%d",&num);
    t.ticket_num = num;
    write(a, &t, sizeof(t));
    printf("ticket number is stored in file\n");
    return 0;
}
/*
Output:
./a.out ticket.txt
Enter ticket number:	10
ticket number is stored in file
*/
