/*

Name: Shiva.K
Date: 07-10-2022
Description: Infix to Postfix expression and evaluation

Sample output: -->

emertxe@ubuntu:~/ECEP/DS/13_postfix$ make
cc    -c -o stack.o stack.c
cc    -c -o infix_postfix.o infix_postfix.c
cc    -c -o main.o main.c
cc    -c -o postfix_evaluation.o postfix_evaluation.c
gcc -o out.exe stack.o infix_postfix.o main.o postfix_evaluation.o

emertxe@ubuntu:~/ECEP/DS/13_postfix$ ./out.exe

Enter the Infix expression : ((22+3)-(12+1))*2+7

PostFix expression : 223+121+-2*7+

Result : 3

*/


#include "main.h"
#include <string.h>

int main()
{
	char Infix_exp[50], Postfix_exp[50], ch;
	int choice, result;
	Stack_t stk;
	stk.top = -1;

	printf("Enter the Infix expression : ");
	scanf("%s", Infix_exp);

	Infix_Postfix_conversion(Infix_exp, Postfix_exp, &stk);
	printf("PostFix expression : %s\n", Postfix_exp);
	stk.top = -1;
	result = Postfix_Eval(Postfix_exp, &stk);
	printf("\nResult : %d\n", result);
	return 0;
}
