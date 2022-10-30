/*
 * Implementaion of queue
 */

#ifndef _QUEUE
#define _QUEUE

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct
{
    struct node* front;
    struct node* rear;
} queue;

void init_queue(queue* q);

void enqueue(queue* q, int val);

int dequeue(queue* q);

bool empty(queue* q);

void printq(queue* q);

#endif