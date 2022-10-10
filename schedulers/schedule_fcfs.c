#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "schedule_fcfs.h"
#include "task.h"
#include "cpu.h"
#include "list.h"

// add a task to the list
void add(char *name, int priority, int burst)
{
    Task *newTask = malloc(sizeof(Task));
    newTask->name = name;
    newTask->tid = ++tid;
    newTask->priority = priority;
    newTask->burst = burst;
    insert(&head, newTask);
    printf("list added with name: %s, with tid: %d\n", name, tid);
}

// invoke the scheduler
void schedule()
{
    printf("tasks queued below\n");
    traverse(head);
    printf("running tasks below\n");
    while (head != NULL)
    {
        struct node *runNode = head;
        while (runNode->next != NULL)
        {
            runNode = runNode->next;
        }
        run(runNode->task, runNode->task->burst);
        delete (&head, runNode->task);
    }
}