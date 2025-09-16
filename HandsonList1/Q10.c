/*
============================================================================
Name : Q10.c
Author : Rohit Bansal
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
              bytes (use lseek) and write again 10 bytes.
              a. check the return value of lseek
              b. open the file with od and check the empty spaces in between the data.
Date: 26th Aug, 2025.
============================================================================
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(int argv, char *argc[])
{
	int fd = open(argc[1], O_RDWR | O_CREAT, 0777);
        
	char arr[10] = "HelloWorld";
	write(fd, arr, 10);
	int o = lseek(fd, 10, SEEK_CUR);
	printf("%d\n", o);
	write(fd, arr, 10);
	o = lseek(fd, 0, SEEK_CUR);
	printf("%d\n", o);
	return 0;
}
/*
Output:
rohit-bansal@rohit-bansal-20YE000UIG:~/Hands-on-list-1$ gcc Q10.c
rohit-bansal@rohit-bansal-20YE000UIG:~/Hands-on-list-1$ ./a.out temp.txt
20
30
rohit-bansal@rohit-bansal-20YE000UIG:~/Hands-on-list-1$ cat temp.txt
HelloWorldHelloWorld
*/
