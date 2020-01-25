#include "racing.h"
#include "maze.h"
#include "rrand.h"
#include <pthread.h>
#include <stdio.h>

void*
rungo(void* racego)
{
  struct racebj* rgo = (struct racebj*)racego;

  for (int r = 0; r < rgo->endline / 2; r++) // X chance to find the vlue
  {
    if (tryharder(rgo) != rgo->endline) {
      printf("Player Number %d find the flag!!\n", rgo->player);
      break;
    }
  }
  return NULL;
}
