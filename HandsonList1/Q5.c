/*
============================================================================
Name : Q5.c
Author : Rohit Bansal
Description : Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd.
Date: 29rd Aug, 2025.
============================================================================
*/

#include <sys/types.h>	
#include <sys/stat.h>	
#include <fcntl.h>	
#include <stdio.h>	
#include <unistd.h>

int main(){
	while(1){
		int fd1 = creat("test1.txt",S_IRWXU);
		int fd2 = creat("test2.txt",S_IRWXU);
		int fd3 = creat("test3.txt",S_IRWXU);
		int fd4 = creat("test4.txt",S_IRWXU);
		int fd5 = creat("test5.txt",S_IRWXU);

		printf("%d %d %d %d %d\n",fd1,fd2,fd3,fd4,fd5);
		close(fd1);
		close(fd2);
		close(fd3);
		close(fd4);
		close(fd5);
		sleep(5);
	}
}

/* Output
3 4 5 6 7
3 4 5 6 7
3 4 5 6 7
3 4 5 6 7
*/
