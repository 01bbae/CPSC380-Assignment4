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
    newTask->tid = ++priority_tid;
    newTask->priority = priority;
    newTask->burst = burst;
    insert(&head, newTask);
    printf("list added with name: %s, with tid: %d\n", name, priority_tid);
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
        // printf("%s\n", highestPriority->task);
        while (runNode != NULL)
        {
            if (runNode->task->priority > highestPriority->task->priority)
            {
                highestPriority = runNode;
            }
            runNode = runNode->next;
        }
        run(highestPriority->task, highestPriority->task->burst);
        delete (&head, highestPriority->task);
    }
}
