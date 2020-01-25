#pragma once

#define MAZE_VERSION 0.1
#define AUTHOR "pype"

#define MIN_THREAD 4   // the more competitors the better
#define MAX_THREAD 255 // ignore > /proc/sys/kernel/threads-max

struct racebj
{
  unsigned int runners;
  unsigned int endline;
  int player;
  int seed;
  int end;
};
