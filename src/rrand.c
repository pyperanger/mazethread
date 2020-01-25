/*
 *  Generate the random number in a range defined by number of runners in main.c
 *  Formula: N = RAND([0:T*5])
 */
#include "rrand.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int
tryharder(struct racebj* race) // return a number in context of endline
{
  srand(race->seed);
  return rand() % (race->runners * 5);
}

int
meters(struct racebj* race) // objetive number
{
  int range;
  struct timespec ts;

  range = race->runners * 5;

  clock_gettime(CLOCK_MONOTONIC, &ts); // ignore clang erros
  race->seed = (int)ts.tv_nsec;
  srand(race->seed);

trygain:
  race->endline = rand() % range;

  if (race->endline == 0)
    goto trygain;

  return 0;
}
