/**************************************************************************************************************************************
* Filename: pinfo.c
* Class: CPE 2600 121
* Description: The system calls available for retrieving information about processes in the system. 
* Author: Jackie Herrick
* Date: 11/05/26
**************************************************************************************************************************************/
#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sched.h>
int main() 
{
    int priority;
    pid_t pid = getpid();
    printf("The PID of this process is: %d\n", (int)pid);
    //for Priority -20 then highest and 19 is the lowest
    // setpriority(PRIO_PROCESS, 0, 10);
    priority = getpriority(PRIO_PROCESS, 0);
    printf("Current process priority: %d\n", priority);

    int policy = sched_getscheduler(0); // Current process
    switch (policy) 
    {
        case SCHED_OTHER: puts("SCHED_OTHER"); //Default time-sharing policy for normal processes.
        break;

        case SCHED_BATCH: puts("SCHED_BATCH"); //Optimized for CPU-intensive, non-interactive jobs.
        break;

        case SCHED_IDLE: puts("SCHED_IDLE"); //Extremely low-priority background jobs.
        break;

        case SCHED_FIFO: puts("SCHED_FIFO"); //Real-time, first-in-first-out scheduling.
        break;

        case SCHED_RR: puts("SCHED_RR"); //Real-time, round-robin scheduling.
        break;

        default: puts("Unknown policy");
    }

    unsigned int cpu, node;
    if (getcpu(&cpu, &node) == 0) 
    {
        printf("CPU: %u, NUMA node: %u\n", cpu, node);
    } else 
    {
        perror("getcpu failed");
        exit(EXIT_FAILURE);
    }

    struct rusage usage;

    if (getrusage(RUSAGE_SELF, &usage) == -1) 
    {
        perror("getrusage");
        return 1;
    }
        //ru_utimeCPU: time spent in user mode and 
        printf("User CPU time: %ld.%06ld seconds\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
        //ru_stimeCPU: time spent in kernel mode
        printf("System CPU time: %ld.%06ld seconds\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
        //ru_maxrssMaximum: resident memory used (KB on Linux)
        printf("Maximum resident set size: %ld KB\n", usage.ru_maxrss);
        //ru_nvcswVoluntary: context switches
        printf("Voluntary context switches: %ld\n", usage.ru_nvcsw);
        //ru_nivcswInvoluntary: context switches
        printf("Involuntary context switches: %ld\n", usage.ru_nivcsw);
    struct rlimit limit;

    if (getrlimit(RLIMIT_NOFILE, &limit) == 0) 
    {
        //Soft limit: The limit currently enforced by the kernel.
        printf("Soft limit: %ld\n", (long)limit.rlim_cur);
        //Hard limit: maximum value the soft limit can be set to.
        printf("Hard limit: %ld\n", (long)limit.rlim_max);
    } else 
    {
        perror("getrlimit");
    }

    return 0;
}