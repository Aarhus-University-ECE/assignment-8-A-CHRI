#include "insertion_sort.h"
#include "linked_list.h"

#include <stdlib.h>
#include <assert.h>

node *sort(node *list)
{
    /* Pre: Non-empty list */
    assert(list != NULL);

    /* Post: Sort the array using insertion sort */
    node *sorted = NULL;

    node *curr = list;
    while (curr != NULL)
    {

        /* Create a new node */
        struct node *new = (node *)malloc(sizeof(node));
        new->data = curr->data;
        new->next = NULL;

        /* Special cases */
        if (sorted == NULL || sorted->data >= new->data)
        {
            new->next = sorted;
            sorted = new;
        }
        else
        {
            node *ins = sorted;
            while (ins->next != NULL && ins->next->data < new->data)
            {
                ins = ins->next;
            }
            new->next = ins->next;
            ins->next = new;
        }
        curr = curr->next;
    }
    return sorted;
}