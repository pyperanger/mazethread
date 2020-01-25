/*
 *  Maze Thread
 *  |   -   --thread|-t 5 (RANGE = RAND(T*10))
 *  |   -   --help|-h
 */
// MAZE HEADER
#include "maze.h"
#include "racing.h"
#include "rrand.h"

#include <ctype.h>
#include <getopt.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define die(STR)                                                               \
  {                                                                            \
    printf(STR);                                                               \
    exit(1);                                                                   \
  }

void
help()
{
  printf("Welcome to Maze Thread Race 2020\n"
         "-t\t- number of thread.. or runners(minimum 4) each one have "
         "$endline/2 chances to find the value\n"
         "-h\t- this message output\n");
  die("life is short, try u best or die like the rest\n");
}

void
telao(struct racebj tbj)
{
  printf("Welcome to Maze Thread Runner 2020\n"
         "Competitors: %d\n"
         "Endline: %d\n"
         "Good look for all\n",
         tbj.runners,
         tbj.endline);
}

int
orgarg(int argc, char** argv, struct racebj* raceopt)
{
  int copt, ret = 0;

  while ((copt = getopt(argc, argv, "ht:")) != -1) {
    switch (copt) {
      case 'h':
        ret = 1;
        break;
      case 't':
        if (atoi(optarg) >= MIN_THREAD)
          raceopt->runners = strtol(optarg, NULL, 10) > MAX_THREAD
                               ? MAX_THREAD
                               : strtol(optarg, NULL, 10);
        else
          raceopt->runners = MIN_THREAD;
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

  if (orgarg(argc, argv, &race) != 0 || argc < 2) // Organize the arguments
    help();

  if (meters(&race) != 0)
    die("Impossible to find meters number\n");

  telao(race);

  // prepare runners
  pthread_t tid[race.runners];
  race.end = 0;
  short int i = 0;

  for (; i < race.runners; i++) {
    race.player = i;
    pthread_create(&tid[i], NULL, rungo, &race);
  }

  for (i = 0; i < race.runners; i++) {
    pthread_join(tid[i], NULL);
  }

  return 0;
}
