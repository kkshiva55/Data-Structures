#include "main.h"

int Prefix_Eval(char *Prefix_exp, Stack_t *stk)
{
     int index = 0, output, oprnd_1, oprnd_2;

    while (Prefix_exp[index] != '\0')  
    {
        if (isdigit(Prefix_exp[index])) 
        {
            push(stk, Prefix_exp[index] - '0');       // Converting ascii to integer and push the digit onto the stack
        }

        else          // If array element is an operator
        {
            oprnd_1 = peek(stk);     
            pop(stk);
                                             // Storing top two elements of the stack and pop it
            oprnd_2 = peek(stk);
            pop(stk);

            switch (Prefix_exp[index])        // Before Operation depending on the operator
            {
                case '/' :
                   output = oprnd_1 / oprnd_2;
                   break;

                case '*' :
                   output = oprnd_1 * oprnd_2;
                   break;

                case '-' :
                   output = oprnd_1 - oprnd_2;
                   break;

                case '+' :
                   output = oprnd_1 + oprnd_2;
                   break;
            }

            push(stk, output);       // Push the result onto the stack
        }
        
        index++;
    }
    
    pop(stk);      // Emptying the stack

  return output;     // Returning the final output
}