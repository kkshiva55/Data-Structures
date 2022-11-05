#include "stack.h"

int Peek(Stack_t **top)
{
    if (*top == NULL)      // Checking if stack is empty
    {
        return FAILURE;
    }

    return (*top)->data;     // Return peek element
}