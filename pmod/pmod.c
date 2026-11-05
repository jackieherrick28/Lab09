/**************************************************************************************************************************************
* Filename: pmod.c
* Class: CPE 2600 121
* Description: Modifies its own priority to REDUCE it by 10
* Author: Jackie Herrick
* Date: 11/05/26
**************************************************************************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

int main(void)
{
    //priority to REDUCE it by 10
    if (nice(10) == -1 && errno != 0)
    {
        perror("nice");
        return 1;
    }

    /* Sleep for 1,837,272,638 ns */
    struct timespec delay;

    delay.tv_sec = 1;
    delay.tv_nsec = 837272638;

    if (nanosleep(&delay, NULL) == -1)
    {
        perror("nanosleep");
        return 1;
    }

    printf("Goodbye!\n");

    return 0;
}