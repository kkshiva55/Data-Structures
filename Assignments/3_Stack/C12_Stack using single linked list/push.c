#include "stack.h"

int Push(Stack_t **top, data_t data)
{
   Stack_t *new = malloc(sizeof(Stack_t));       // Memory allocation for new node

   if (new == NULL)        // Error checking
   {
       return FAILURE;
   }

   new->data = data;       // Inserting element at first
   new->link = *top;
   *top = new;

   return  SUCCESS;
}
