#include "racing.h"
#include "rrand.h"
#include "maze.h"
#include <pthread.h>
#include <stdio.h>

void* rungo(void* racego)
{
   struct racebj *rgo = (struct racebj*)racego; 
   if(tryharder(rgo) != rgo->endline)
   {
       puts("I WILL BITCH");        
   }
    return NULL;
}

