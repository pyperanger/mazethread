#pragma once

#define MAZE_VERSION 0.1
#define AUTHOR "pype"

#define MIN_THREAD 2
#define MAX_THREAD 255 // /proc/sys/kernel/threads-max 

struct racebj {
    int runners;
    int endline;
};
