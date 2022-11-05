/*

Name: Shiva.K
Date: 07-10-2022
Description: Infix to Prefix Expression and Evaluation

Sample output: -->

emertxe@ubuntu:~/ECEP/DS/14_prefix$ make
cc    -c -o stack.o stack.c
cc    -c -o infix_prefix.o infix_prefix.c
cc    -c -o main.o main.c
cc    -c -o prefix_evaluation.o prefix_evaluation.c
gcc -o out.exe stack.o infix_prefix.o main.o prefix_evaluation.o

emertxe@ubuntu:~/ECEP/DS/14_prefix$ ./out.exe
Enter the Infix expression : 2*3+(7-5)*8
PreFix expression : +*23*-758

Result : 22

*/


#include "main.h"


void strrev(char *string)
{
     int i, len_str, temp;

       for (len_str = 0; string[len_str] != '\0'; len_str++);       // Computing the string length


            for (i = 0; i < len_str / 2; i++)         // Swapping the characters from last to first
             {
                 temp = string[i];
                 string[i] = string[len_str - i - 1];
                 string[len_str - i - 1] = temp;
             }
       
}

int main()
{
	char Infix_exp[50], Prefix_exp[50], ch;
	int choice, result;
	Stack_t stk;
	stk.top = -1;

	printf("Enter the Infix expression : ");
	scanf("%s", Infix_exp);

	strrev(Infix_exp);
	Infix_Prefix_conversion(Infix_exp, Prefix_exp, &stk);
	strrev(Prefix_exp);
	printf("PreFix expression : %s\n", Prefix_exp);

	stk.top = -1;

	strrev(Prefix_exp);
	result = Prefix_Eval(Prefix_exp, &stk);
	printf("\nResult : %d\n", result);
	return 0;
}
