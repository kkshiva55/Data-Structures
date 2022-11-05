#include "main.h"

int Postfix_Eval(char *Postfix_exp, Stack_t *stk)
{
    int index = 0, output, oprnd_1, oprnd_2;

    while (Postfix_exp[index] != '\0')  
    {
        if (isdigit(Postfix_exp[index])) 
        {
            push(stk, Postfix_exp[index] - '0');       // Converting ascii to integer and push the digit onto the stack
        }

        else          // If array element is an operator
        {
            oprnd_1 = peek(stk);     
            pop(stk);
                                             // Storing top two elements of the stack and pop it
            oprnd_2 = peek(stk);
            pop(stk);

            switch (Postfix_exp[index])        // Before Operation depending on the operator
            {
                case '/' :
                   output = oprnd_2 / oprnd_1;
                   break;

                case '*' :
                   output = oprnd_2 * oprnd_1;
                   break;

                case '-' :
                   output = oprnd_2 - oprnd_1;
                   break;

                case '+' :
                   output = oprnd_2 + oprnd_1;
                   break;
            }

            push(stk, output);       // Push the result onto the stack
        }
        index++;
    }
    
    pop(stk);      // Emptying the stack

  return output;     // Returning the final output
}