#include "main.h"

void push(Stack_t *stk, int data)      // Pushing onto the stack
{
	++(stk -> top);
	stk -> stack[stk -> top] = data;
}

void pop(Stack_t *stk)         // Delete topmost element from the stack
{
	if (stk -> top != -1)
		--(stk -> top);
}

int peek(Stack_t *stk)       // Return the topmost element from the stack
{
	if (stk -> top != -1)
	{
		return stk -> stack[stk -> top];
	}
	return -1;
}

int priority(char opr)
{
    switch(opr)        // Return the value depending on the precedence
	{
		   
		case '*' :
		    return 3;
			break;

		case '/' :
		    return 3;
			break;

		case '-' :
			return 2;
			break;

		case '+' :
		    return 2;
			break;

		case '(' :
			return 1;
			break;

		case ')' :
			return 1;
            break;
			
		default :
			return 0;


	}
}
