#include "dll.h"

int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));    // Creating a new node 
      
    if (new == NULL)   // Error checking
    {
        return FAILURE;
    }

    new->data = data;
    new->next = NULL;    // Updating the links and storing the data onto the new node
    new->prev = NULL;

    if (*head == NULL)   // Checking if list is empty
    {
        *head = *tail = new;
        return SUCCESS;
    }

    (*tail)->next = new;   // Insert the node at last
    new->prev = *tail;
    *tail = new;

    return SUCCESS;

}