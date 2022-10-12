#ifndef SCHEDULE_RR_H
#define SCHEDULE_RR_H

#define TIME_QUANTUM 10

#include "list.h"

static struct node *head;
static int rr_tid = 0;

// add a task to the list
void add(char *name, int priority, int burst);

// invoke the scheduler
void schedule();

#endif