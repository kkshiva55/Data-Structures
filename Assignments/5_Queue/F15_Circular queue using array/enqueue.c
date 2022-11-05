#include "queue.h"

/* Function to Insert the element */
int enqueue(Queue_t *q, int data)
{
    if (IsQueueFull(q) == SUCCESS)      // Checking if queue is full
    {
        return FAILURE;
    }

    if (q->front == -1)        // If queue is empty, then change front value as '0'
    {
        q->front = 0;
    }

    q->rear = (q->rear + 1) % (q->capacity);      // Adding element after the rear 
    q->Que[q->rear] = data;
    ++q->count;

    return SUCCESS;

}