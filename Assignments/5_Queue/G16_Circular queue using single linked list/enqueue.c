#include "queue.h"

int enqueue(Queue_t **front, Queue_t **rear, int data)
{
    Queue_t *new = malloc(sizeof(Queue_t));        // Memory allocation for new node

    if (new == NULL)        // Error checking
    {
        return FAILURE;
    }

    new->data = data;        // Storing data into the node

    if (*front == NULL)      // If list is empty
    {
        *front = *rear = new;
    }
    else 
    {
        (*rear)->link = new;       // Update present node address as next node address
        *rear = new;               // Update rear value
        new->link = *front;        // Update last node address as first node address
    }

  return SUCCESS;
  
}