/*
============================================================================
Name : Q20.c
Author : Rohit Bansal
Description :Find out the priority of your running program. Modify the priority with nice command.
Date: 30th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/resource.h>

int main()
{   
    //Identifying current priority
    int priority;
    int nice_val = 10;
    priority = getpriority(PRIO_PROCESS, 0);
    printf("Current priority is:%d\n",priority);
    //Setting new priority
    int final;
    final = nice(nice_val);
    setpriority(PRIO_PROCESS, 0, final);
    priority = getpriority(PRIO_PROCESS, 0);
    printf("New priority is:%d\n",priority);
    
    return 0;
}
/*
Output: 
Current priority is:0
New priority is:10
*/
