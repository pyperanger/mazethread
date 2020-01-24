/*
 *  Maze Thread 
 *  |   -   --thread|-t 5 (RANGE = RAND(T*10)) 
 *  |   -   --help|-h
*/
// MAZE HEADER
#include "maze.h"
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>

#define die(STR)    \
{                   \
    printf(STR);    \
    exit(1);        \
}


void help()
{
    printf("Welcome to Maze Thread Race 2020\n"
           "-t\t- number of thread.. or runners\n"
           "-h\t- this message output\n");
    die("life is short, try u best or die like the rest\n");
}

int
orgarg(int argc,  char** argv, struct racebj* raceopt)
{
    int copt,ret = 0;

    while((copt = getopt(argc, argv, "ht:")) != -1)
    {
        switch(copt)
        {
            case 'h':
                ret = 1;
                break;
            case 't':
                raceopt->runners = strtol(optarg, NULL, 10) > MAX_THREAD ? MAX_THREAD : strtol(optarg, NULL, 10); 
                break;
            case '?':
                ret = 1; 
                break;
             default:
                ret = 1;
        }    
    }

    return ret;
}

int 
main(int argc, char* argv[])
{
    struct racebj race;
    
    
    if(orgarg(argc, argv, &race) != 0 || argc < 2) // Organize the arguments 
        help();

    if(meters(&race) != 0)
       die("Impossible to find meters number\n"); 

    return 0;
}
