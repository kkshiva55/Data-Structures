#include "queue.h"

/* Function to deque the element */
int dequeue(Queue_t *q)
{
    if (IsQueueEmpty(q) == SUCCESS)    // Checking if queue is empty
    {
        return FAILURE;
    }

    q->front = ((q->front) + 1) % (q->capacity);    // Changing the position of front in forward direction
    --q->count;

    return SUCCESS;
}