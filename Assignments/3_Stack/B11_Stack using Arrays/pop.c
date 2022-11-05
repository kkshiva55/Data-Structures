#include "stack.h"

/* Function for Poping the element */
int Pop(Stack_t *s)
{	
    if (s->top == -1)      // Checking if stack is empty 
    {
        return FAILURE;
    }

    --s->top;         // Decrementing top
    return SUCCESS;	
}