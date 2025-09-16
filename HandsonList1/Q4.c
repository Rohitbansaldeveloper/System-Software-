/*
============================================================================
Name : Q4.c
Author : Rohit Bansal
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 29rd Aug, 2025.
============================================================================
*/

#include <sys/types.h>	
#include <sys/stat.h>	
#include <fcntl.h>	
#include <stdio.h>	

int main(int argc, char *argv[]){
	if(argc != 2){
		perror("File Name not found\n");
		return 0;
	}

	const char *fileName = argv[1];
	int fd = open(fileName, O_RDWR | O_EXCL);

	if(fd == -1){
		perror("Error while opening the file!\n");
	}else{
		printf("Sucessfully opened file with Read and Write Mode\n");
	}
	return 0;
}

/*
./a.out Q4.c 
Sucessfully opened file with Read and Write Mode
*/
