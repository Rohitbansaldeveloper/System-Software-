/*
========================================================================================================
Name : Q16.c
Author : Rohit Bansal
Description : Write a program to send and receive data from parent to child vice versa. Use two way communication.
Date: 16 Sept, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd_pc[2];
	int fd_cp[2];
	
	pipe(fd_cp);
	pipe(fd_pc);

	if(!fork()){
		int c_value = 100;
		close(fd_cp[0]);
		write(fd_cp[1], &c_value, sizeof(int));

		int c_val;
		close(fd_pc[1]);
		read(fd_pc[0], &c_val, sizeof(int));
		printf("Data from parent to child: %d\n", c_val);
	}
	else{
		int p_value;
		close(fd_cp[1]);
		read(fd_cp[0], &p_value, sizeof(int));
		printf("Data from child to parent: %d\n", p_value);

		int p_val = 200;
		close(fd_pc[0]);
		write(fd_pc[1], &p_val, sizeof(int));
	}

}
/*
Data from child to parent: 100
Data from parent to child: 200
*/

