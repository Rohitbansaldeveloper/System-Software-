
/*
============================================================================
Name : Q7.c
Author : Rohit Bansal
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 28th Aug, 2025.
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int n, fd1, fd2;
    char array[100];
    fd1 = open("fileq7a.txt", O_RDONLY);
    fd2 = open("fileq7b.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    while ((n = read(fd1,array, sizeof(array))) > 0) {
        write(fd2,array,n);
    }
    close(fd1);
    close(fd2);
}

/*
Output:fileq7a.txt,file7b.txt;
*/