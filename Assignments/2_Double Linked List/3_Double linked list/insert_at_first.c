#include "dll.h"

int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));   // Creating a new node

    if (new == NULL)     // Error checking
    { 
        return FAILURE;
    }

    new->data = data;
    new->next = NULL;    // Updating the links and storing the data onto the new node
    new->prev = NULL;

    if (*head == NULL)     // Checking if list is empty
    { 
        *head = *tail = new;
        return SUCCESS;
    }

    (*head)->prev = new;    // Insert the node at first
    new->next = *head;
    *head = new;
    return SUCCESS;
}