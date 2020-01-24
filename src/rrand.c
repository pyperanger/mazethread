/*
 *  Generate the random number in a range defined by number of runners in main.c 
 *  Formula: N = RAND([0:T*5])
*/
#include "rrand.h"
#include <time.h>

int meters(struct racebj* race)
{
    struct timespec ts;

    clock_gettime(CLOCK_MONOTONIC, &ts);


    return 0;
}
