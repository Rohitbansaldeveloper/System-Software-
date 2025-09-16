/*
============================================================================
Name : Q1b.c
Author : Rohit Bansal
Description : Create a hard link file using the `link` system call
Date: 29nd Aug, 2025.
============================================================================
*/

#include<unistd.h>	
#include<stdio.h>	

int main(int argc, char *argv[]){
	if(argc != 3){
		printf("Enter target and source file Name\n");
		return 0;
	}
	const char *source = argv[1];
	const char *target = argv[2];
	
	int status = link(source,target);

	if(status == -1){
		perror("Error while craeting head link\n");	
	}else{
		printf("Hard Link created successfully\n");
	}
}

/*
./a.out source.txt hardLink 
Hard Link created successfully


*/
