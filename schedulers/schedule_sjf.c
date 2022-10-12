#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "schedule_sjf.h"
#include "task.h"
#include "cpu.h"
#include "list.h"

void add(char *name, int priority, int burst)
{
    Task *newTask = malloc(sizeof(Task));
    newTask->name = name;
    newTask->tid = ++sjf_tid;
    newTask->priority = priority;
    newTask->burst = burst;
    insert(&head, newTask);
    printf("list added with name: %s, with tid: %d\n", name, sjf_tid);
}

void schedule()
{
    printf("tasks queued below\n");
    traverse(head);
    printf("running tasks below\n");
    while (head != NULL)
    {
        struct node *runNode = head;
        struct node *leastBurst = runNode;
        // printf("%s\n", highestPriority->task);
        while (runNode != NULL)
        {
            if (runNode->task->burst < leastBurst->task->burst)
            {
                leastBurst = runNode;
            }
            runNode = runNode->next;
        }
        run(leastBurst->task, leastBurst->task->burst);
        delete (&head, leastBurst->task);
    }
}