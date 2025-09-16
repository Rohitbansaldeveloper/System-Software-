/*
============================================================================
Name : Q3.c
Author : Rohit Bansal
Description : Write a program to create a file and print the file descriptor value. Use creat() system call
Date: 29nd Aug, 2025.
============================================================================
*/

#include<sys/types.h>
#include<sys/stat.h>	
#include<fcntl.h>		
#include<stdio.h>		

int main(int argc, char *argv[]){
	if(argc != 2){
		perror("Enter File Name in arguement\n");
		return 0;
	}
	
	const char *fileName = argv[1];
	int fd = creat(fileName,S_IRWXU);

	if(fd == -1){
		perror("Error while creating a file\n");
	}else{
		printf("The file have been successfully create and the file descriptor value is: %d\n",fd);
	}
	return 0;
}

/*
./a.out newFile
The file have been successfully create and the file descriptor value is: 3
*/
