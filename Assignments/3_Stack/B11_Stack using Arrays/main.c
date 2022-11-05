/*

Name: Shiva.K
Date: 03-10-2022
Description: Implementation of stack using Array 

Sample output: -->

emertxe@ubuntu:~/ECEP/DS/11_stack$ make
cc    -c -o push.o push.c
cc    -c -o peek.o peek.c
cc    -c -o peep.o peep.c
cc    -c -o pop.o pop.c
cc    -c -o main.o main.c
gcc -o out.exe push.o peek.o peep.o pop.o main.o

emertxe@ubuntu:~/ECEP/DS/11_stack$ ./out.exe
Enter the size of the stack: 4
1. Push
2. Pop
3. Display Stack
4. Peek(Element at Top)
5. Exit
Enter your choice : 2
INFO : Stack is empty
3
INFO : Stack is empty
4
INFO : Stack is empty
2
INFO : Stack is empty
1
Enter the element to be pushed in stack : 10
1
Enter the element to be pushed in stack : 12
1
Enter the element to be pushed in stack : 13
1
Enter the element to be pushed in stack : 15
1
Enter the element to be pushed in stack : 25
INFO : Stack Full
3
Top -> 15 13 12 10 
2
INFO : Pop operation is successfull
3
Top -> 13 12 10 
4
INFO : Peek element is 13
5 (exit)

*/


#include "stack.h"

int create_stack(Stack_t *stk, int size)
{
    stk->stack = malloc(sizeof(int) * size);

    if (stk->stack == NULL)
    {
        return FAILURE;
    }

    stk->capacity = size;
    stk->top = -1;
    return SUCCESS;
}


int main()
{
	int choice, element, peek, size;
	Stack_t stk;

    printf("Enter the size of the stack: ");
    scanf("%d", &size);
    
    create_stack(&stk, size);
	printf("1. Push\n2. Pop\n3. Display Stack\n4. Peek(Element at Top)\n5. Exit\nEnter your choice : ");
    
	while (1)
	{
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the element to be pushed in stack : ");
				scanf("%d", &element);
				if (Push(&stk, element) == FAILURE)
				{
					printf("INFO : Stack Full\n");
				} 
				break;
			case 2:
				if (Pop(&stk) == FAILURE)
				{
					printf("INFO : Stack is empty\n");
				}
				else
				{
				    printf("INFO : Pop operation is successfull\n");
				}
				break;
			case 3:
				Peep(stk);
				break;
			case 4:
				if ((peek = Peek(&stk)) == FAILURE)
				{
					printf("INFO : Stack is empty\n");
				}
				else
				{
					printf("INFO : Peek element is %d\n", peek);
				}
				break;
			case 5:
				return SUCCESS;
			default:
				printf("Invalid Choice.\n");
				break;
		}
	}
	return 0;
}