#include "queue.h"

int IsQueueFull(Queue_t *q)
{
  if (q->count == q->capacity)       // Return SUCCESS if queue is full
  {
      return SUCCESS;
  } 

  return FAILURE;
}

int IsQueueEmpty(Queue_t *q)        // Return SUCCESS if queue is empty
{
   if (q->count == 0)
   {
       return SUCCESS;
   }

   return FAILURE;
}