#include "stack.h"

int Pop(Stack_t **top)
{
	if (*top == NULL)        // Checking if stack is empty
    {
        return FAILURE;
    }

    Stack_t *temp = *top;    // Deleting node where the top is pointed
    *top = temp->link;
    free(temp);
    
  return SUCCESS;
}