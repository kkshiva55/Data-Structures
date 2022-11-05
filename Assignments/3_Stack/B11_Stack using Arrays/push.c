#include "stack.h"

/* Fuction for inserting the element */
int Push(Stack_t *s, int element)
{
       if (s->capacity - 1  == s->top)   // Checking if stack is full
       {
           return FAILURE;
       }

       ++s->top;                         // Incrementing top
       
       s->stack[s->top] = element;      // Pushing the element onto the stack
       
       return SUCCESS;

}