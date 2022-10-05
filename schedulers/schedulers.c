#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "schedulers.h"
#include "task.h"
#include "cpu.h"

// add a task to the list 
void add(char *name, int priority, int burst){
    struct Task* newTask = malloc(sizeof(struct Task));
    newTask.name = name;
    newTask.priority = priority;
    newTask.burst = burst;
    list.insert(head, newTask);
    printf("list added with name: %s\n", name);
}

// invoke the scheduler
void schedule(){
    printf("running tasks below\n");
    list.traverse(head)
    struct node *runNode = head;
    while(runNode.next != NULL){
        runNode = runNode.next;
    }
    run(runNode.task, runNode.task.burst);
    list.delete(head, runNode.task);
}