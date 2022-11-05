#include "main.h"

int Infix_Postfix_conversion(char *Infix_exp, char *Postfix_exp, Stack_t *stk)
{
    int index_infix = 0, index_postfix = 0; 

    while (Infix_exp[index_infix] != '\0')
    {
        
        if (isdigit(Infix_exp[index_infix]))           // Store the operand in the postfix array
        {
            Postfix_exp[index_postfix++] = Infix_exp[index_infix];
            index_infix++;
        }
        
        else  
        {
            if (stk->top == -1)        // If stack is empty, push the element onto the stack
            {
                push(stk, Infix_exp[index_infix]);
                index_infix++;
            }
            
            else if (Infix_exp[index_infix] == '(')      // If we encounter '(', push  onto the stack
            {
                push(stk, Infix_exp[index_infix]);
                index_infix++;
            }

            else if (Infix_exp[index_infix] == ')')     // Pop all the elements till '(' appears and store it to the postfix array
            {
                 while (peek(stk) != '(')
                 {
                    Postfix_exp[index_postfix++] = peek(stk);
                    pop(stk);
                 }
             
               pop(stk);
               index_infix++;
               
            }
           
            else if (priority(stk->stack[stk->top]) >= priority(Infix_exp[index_infix]))      // If topmost element in the stack has higher precendence
            {
                Postfix_exp[index_postfix++] = peek(stk);     // Push it to the postfix array
                pop(stk);                                     // Pop the topmost element
            }
            
            else
            {
                push(stk, Infix_exp[index_infix]);      // Else push the element onto the stack
                index_infix++;
            }

        }
       
    }
    
    
    while (stk->top != -1)       // Store the remaining elements to the postfix array
    {
        Postfix_exp[index_postfix++] = peek(stk);
        pop(stk);
    }

    Postfix_exp[index_postfix] = '\0';
    
  return 0;
  
}