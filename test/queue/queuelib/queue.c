#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int isEmpty(task_queue_t *q)
{
  if(q->rear == -1)
    return 1;
  else
    return 0;
}
int isFull(task_queue_t *q)
{
  if((q->rear+1) % MAX_QUEUE_SIZE == q->front)
    return 1;
  else
    return 0;
}

void enQueue(task_queue_t *q,task_t task)
{
  if(q->rear == -1)
  {
    q->task[q->front] = task; 
    q->rear = q->front;
    return;
  }
  if(isFull(q))
  {
    printf("this is overflow\n");
    return;
  }
  q->task[q->rear+1] = task; 
  q->rear = (q->rear+1)%MAX_QUEUE_SIZE;
}

task_t deQueue(task_queue_t *q)
{
  task_t task;
  if(isEmpty(q)==1)
  {
    printf("this is underflow\n");
    exit(1);
  }
  if(q->front == q->rear)
  {
    q->rear = -1;
    return q->task[q->front];
  }


  task = q->task[q->front];
  q->front = (q->front+1)%MAX_QUEUE_SIZE;
  return task;

}

void createQueue(task_queue_t *q)
{
  q->front = 0;
  q->rear = -1;
}

void print()
{
  printf("test");

}


