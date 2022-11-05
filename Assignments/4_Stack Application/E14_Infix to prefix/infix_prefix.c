#include "main.h"

int Infix_Prefix_conversion(char *Infix_exp, char *Prefix_exp, Stack_t *stk)
{
    int index_infix = 0, index_prefix = 0;

    while (Infix_exp[index_infix] != '\0') 
    {
        if (isdigit(Infix_exp[index_infix]))      // Store the operand into the prefix array
        {
            Prefix_exp[index_prefix++] = Infix_exp[index_infix];
            index_infix++;
        }

        else
        {
            if (stk->top == -1)                        // If stack is empty, push it onto the stack
            {
                push(stk, Infix_exp[index_infix]);
                index_infix++;
            }

            else if (Infix_exp[index_infix] == ')')      // Push ')' onto the stack
            {
                push(stk, Infix_exp[index_infix]);
                index_infix++;
            }

            else if (Infix_exp[index_infix] == '(')    // Store all elements to the prefix array until we encounter '('
            {
                while (peek(stk) != ')')
                {
                    Prefix_exp[index_prefix++] = peek(stk);
                    pop(stk);
                }
                pop(stk);             // Discard '(' from the stack
                index_infix++;
            }

            else if (priority(peek(stk)) > priority(Infix_exp[index_infix]))    // Store all the elements to the prefix array until this condition fails
            {
                while ((priority(peek(stk)) > priority(Infix_exp[index_infix])) && (stk->top != -1))
                {
                    Prefix_exp[index_prefix++] = peek(stk);
                    pop(stk);
                }
            }

            else      // Push onto the stack
            {
                push(stk, Infix_exp[index_infix]);
                index_infix++;
            }
        }
    }

    while (stk->top != -1)     // Store all the remaining elements to the prefix array
    {
        Prefix_exp[index_prefix++] = peek(stk);
        pop(stk);
    }
    Prefix_exp[index_prefix] = '\0';
    
  return 0;
  
}
