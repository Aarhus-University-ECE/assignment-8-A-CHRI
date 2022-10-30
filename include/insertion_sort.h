/*
 * Insertion sort
 */

#ifndef _INS_SORT
#define _INS_SORT

typedef struct node
{
    int data;
    struct node *next;
} node;

node* sort(node* list);

#endif