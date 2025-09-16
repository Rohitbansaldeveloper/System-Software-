/*
============================================================================
Name : Q2.c
Author : Rohit Bansal
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and identify all the process related information in the corresponding proc directory.
Date: 29nd Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
int main(){
	printf("my pid is : %d\n",getpid());
	while(1){

	}	

	return 0;
}	
/*
output
my pid is : 15531
*/
