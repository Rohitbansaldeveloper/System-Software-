
/*
============================================================================
Name : Q8.c
Author : Rohit Bansal
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
              Close the file when end of file is reached.
Date: 29th Aug, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define BUF_SIZE 1

int main(int argc , char *argv[]){
	int fd ;
	char c;
	int n;

	if(argc !=2){
		write(2 , "Usage: ./Q8_read_lines filename\n" , 32);
		exit(1);
	}

	fd = open(argv[1] , O_RDONLY);
	if(fd == -1){
		perror("open faild");
		exit(1);
	}

	while( n = read(fd , &c , BUF_SIZE) > 0){

		write(1 , &c ,1);
	}
	if(n<0){
		perror("read failed");
	}
	close(fd);
	return 0;
}

/************************ Sample Output ******************************
$ ./Q8 test8.txt
Rohitbansal1
rohitbansal2
rohitbansal3
rohitbansal4
*********************************************************************/
