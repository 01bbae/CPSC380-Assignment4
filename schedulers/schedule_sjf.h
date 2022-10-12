#ifndef SCHEDULE_SJF_H
#define SCHEDULE_SJF_H

#include "list.h"

static struct node *head;
static int sjf_tid = 0;

// add a task to the list
void add(char *name, int priority, int burst);

// invoke the scheduler
void schedule();

#endif