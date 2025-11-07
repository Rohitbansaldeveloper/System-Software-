

/*
========================================================================================================
Name : Q2.c
Author :Rohit Bansal
Description : Write a program to print the system resource limits. Use getrlimit system call.
Date: 27 Sept, 2025.
========================================================================================================
*/
#include<stdio.h>
#include <sys/resource.h> 
#include <unistd.h>

void limit(int resource, const char *name) {
    struct rlimit limit;
    
    
    if (getrlimit(resource, &limit) == 0) {
        printf("%-20s:Min limit = %ld, Max limit = %ld\n", name, (long)limit.rlim_cur, (long)limit.rlim_max);
    } else {
        perror("getrlimit");
    }
}

int main(){
    
    limit(RLIMIT_CPU, "Time of CPU");
    limit(RLIMIT_FSIZE, "File size");
    limit(RLIMIT_DATA, "Data size");
    limit(RLIMIT_STACK, "Stack size");
    limit(RLIMIT_CORE, "Core file size");
    limit(RLIMIT_RSS, "Resident set size");
    limit(RLIMIT_NPROC, "Processes");
    limit(RLIMIT_NOFILE, "Open files");
   
    return 0;
}
/*
Time of CPU         :Min limit = 9223372036854775807, Max limit = 9223372036854775807
File size           :Min limit = 9223372036854775807, Max limit = 9223372036854775807
Data size           :Min limit = 9223372036854775807, Max limit = 9223372036854775807
Stack size          :Min limit = 8388608, Max limit = 67104768
Core file size      :Min limit = 0, Max limit = 9223372036854775807
Resident set size   :Min limit = 9223372036854775807, Max limit = 9223372036854775807
Processes           :Min limit = 2784, Max limit = 4176
Open files          :Min limit = 256, Max limit = 9223372036854775807
*/