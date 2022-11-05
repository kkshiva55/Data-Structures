#include "queue.h"

int dequeue(Queue_t **front, Queue_t **rear)
{
    if (*front == NULL)         // Checking if queue is empty
    {
        return FAILURE;
    }

    if (*front == *rear)        // Deletion in case of single node
    {
        free(*front);
        *front = *rear = NULL;
    }
    else                      // Deletion in case of multiple node
    {
        *front = (*front)->link;
        free((*rear)->link);
        (*rear)->link = *front;
    }

  return SUCCESS;

}