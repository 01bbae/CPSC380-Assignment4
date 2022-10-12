#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "schedule_rr.h"
#include "task.h"
#include "cpu.h"
#include "list.h"

void add(char *name, int priority, int burst)
{
    Task *newTask = malloc(sizeof(Task));
    newTask->name = name;
    newTask->tid = ++rr_tid;
    newTask->priority = priority;
    newTask->burst = burst;
    insert(&head, newTask);
    printf("list added with name: %s, with tid: %d\n", name, rr_tid);
}

void schedule()
{
    printf("tasks queued below\n");
    traverse(head);
    printf("running tasks below\n");
    struct node *runNode = head;
    while (head != NULL)
    {
        if (runNode == NULL)
        {
            runNode = head;
        }
        int runtime = 0;
        if (runNode->task->burst >= TIME_QUANTUM)
        {
            runtime = TIME_QUANTUM;
        }
        else
        {
            runtime = runNode->task->burst;
        }
        if (runtime > 0)
        {
            run(runNode->task, runtime);
        }
        if (runtime < TIME_QUANTUM)
        {
            delete (&head, runNode->task);
        }
        else
        {
            runNode->task->burst = runNode->task->burst - TIME_QUANTUM;
        }
        runNode = runNode->next;
    }
}
