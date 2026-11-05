/**************************************************************************************************************************************
* Filename: info.c
* Class: CPE 2600 121
* Description: Information maintenance system calls provide data concerning the entire running system.
* Author: Jackie Herrick
* Date: 11/05/26
**************************************************************************************************************************************/
#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>

int main() {
    struct utsname buffer;
    struct timespec time;
    int status;
    char hostname[256];

    //memory
    long total_pages = sysconf(_SC_PHYS_PAGES);
    long free_pages = sysconf(_SC_AVPHYS_PAGES);
    long page_size = getpagesize();

    long long total_memory = (long long)total_pages * page_size;
    long long free_memory = (long long)free_pages * page_size;
    // gets time
    clock_gettime(CLOCK_MONOTONIC, &time);
    printf("The current time of day %ld in nanoseconds \n", time.tv_nsec);
    //system info
    status = uname(&buffer);
    if (status < 0)
    {
        perror("uname");
        exit(EXIT_FAILURE);
    }

    //host name
    if (gethostname(hostname, sizeof(hostname)) == 0) 
    {
    printf("The systems network name is %s\n", hostname);
    } 
    else 
    {
    perror("gethostname error");
    }
    printf("The operating system name is %s\n", buffer.sysname);
    printf("The operating system release is %s\n", buffer.release);
    printf("The operating system version is %s\n", buffer.version);
    printf("The systems hardware type is %s\n", buffer.machine);
    printf("The number of CPUs on the system is %d\n", get_nprocs());
    printf("The total amount of physical memory IN BYTES is %lld\n", total_memory);
    printf("The total amount of free memory IN BYTES is %lld\n", free_memory);
    return 0; 
}