#ifndef SCHEDULE_FSFS_H
#define SCHEDULE_FSFS_H

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

#include "list.h"

struct node *head;
int tid = 0;

// add a task to the list
void add(char *name, int priority, int burst);

// invoke the scheduler
void schedule();

#endif