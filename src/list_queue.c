#include "list_queue.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void init_queue(queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(queue *q, int val)
{
    /*Post: Add value to the queue */

    /* Create a new node */
    struct node *new = (node *)malloc(sizeof(node));
    new->data = val;
    new->next = NULL;

    /* If the queue is empty, let the rear pointer */
    if (q->rear == NULL && q->front == NULL)
    {
        q->front = new;
        q->rear = new;
    }
    q->rear->next = new;
    q->rear = new;
}

int dequeue(queue *q)
{
    /* Pre: Non-empty queue */
    assert(q->front != NULL);

    /*Post: Remove and return the rear element */
    node *t = q->front;

    q->front = q->front->next;

    int temp = t->data;
    free(t);

    return temp;
}

bool empty(queue *q)
{
    return q->front == NULL && q->rear == NULL;
}