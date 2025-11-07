
/*
========================================================================================================
Name : Q5.c
Author : Rohit Bansal
Description : Write a program to print the system limitation of:
		a. maximum length of the arguments to the exec family of functions
		b. maximum number of simultaneous process per user id
		c. number of clock ticks (jiffy) per second
		d. maximum number of open files
		e. size of a page
		f. total number of pages in the physical memory
		g. number of currently available pages in the physical memory
Date: 21 Sept, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/sysctl.h>
#include <mach/mach.h>
#include <stdint.h>

int main(void) {
    long arg = sysconf(_SC_ARG_MAX);
    printf("Maximum length of the arguments to the exec family of functions: %ld\n", arg);

    long processes = sysconf(_SC_CHILD_MAX);
    printf("Maximum number of simultaneous processes per user id: %ld\n", processes);

    long clock_ticks = sysconf(_SC_CLK_TCK);
    printf("Number of clock ticks per second: %ld\n", clock_ticks);

    long open_files = sysconf(_SC_OPEN_MAX);
    printf("Maximum number of open files: %ld\n", open_files);

    long page_size = sysconf(_SC_PAGESIZE);
    printf("Size of a page: %ld bytes\n", page_size);

    uint64_t memsize = 0;
    size_t len = sizeof(memsize);
    sysctlbyname("hw.memsize", &memsize, &len, NULL, 0);
    printf("Total physical memory: %llu bytes\n", (unsigned long long)memsize);

    uint64_t total_pages = memsize / (uint64_t)page_size;
    printf("Total number of pages in physical memory: %llu\n", (unsigned long long)total_pages);

    vm_statistics64_data_t vmstat;
    mach_msg_type_number_t count = HOST_VM_INFO64_COUNT;
    host_statistics64(mach_host_self(), HOST_VM_INFO64, (host_info64_t)&vmstat, &count);

    uint64_t available_pages =
        (uint64_t)vmstat.free_count
      + (uint64_t)vmstat.inactive_count
#ifdef __APPLE__
      + (uint64_t)vmstat.speculative_count
#endif
      ;

    printf("Number of currently available pages in physical memory (free+inactive+speculative): %llu\n",
           (unsigned long long)available_pages);

    return 0;
}
/*
Maximum length of the arguments to the exec family of functions: 1048576
Maximum number of simultaneous processes per user id: 2784
Number of clock ticks per second: 100
Maximum number of open files: 256
Size of a page: 4096 bytes
Total physical memory: 17179869184 bytes
Total number of pages in physical memory: 4194304
Number of currently available pages in physical memory (free+inactive+speculative): 1496949
*/