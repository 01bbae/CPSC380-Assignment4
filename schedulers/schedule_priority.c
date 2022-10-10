#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "schedule_priority.h"
#include "task.h"
#include "cpu.h"
#include "list.h"

void add(char *name, int priority, int burst)
{
    Task *newTask = malloc(sizeof(Task));
    newTask->name = name;
    newTask->tid = ++tid;
    newTask->priority = priority;
    newTask->burst = burst;
}

void schedule()
{
    printf("tasks queued below\n");
    traverse(head);
    printf("running tasks below\n");
    while (head != NULL)
    {
        struct node *runNode = head;
        struct node *highestPriority = runNode;
        while (runNode->next != NULL)
        {
            if (runNode->task->priority > highestPriority->task->priority)
            {
                highestPriority = runNode;
            }
            runNode = runNode->next;
        }
        run(runNode->task, runNode->task->burst);
        delete (&head, runNode->task);
    }
}
