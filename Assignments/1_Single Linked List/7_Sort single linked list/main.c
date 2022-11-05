/*

Name: Shiva.K
Date: 10-10-2022
Description: Sorting of Single Linked List

Sample output: -->

emertxe@ubuntu:~/ECEP/DS/7_sll$ make
cc    -c -o print_list.o print_list.c
cc    -c -o insert_at_last.o insert_at_last.c
cc    -c -o main.o main.c
cc    -c -o sl_sort.o sl_sort.c
gcc -o out.exe print_list.o insert_at_last.o main.o sl_sort.o


emertxe@ubuntu:~/ECEP/DS/7_sll$ ./out.exe
1. Insert at last
2. Sort list
3. Print list
4. Exit
Enter your choice : 1
Enter the number that you want to insert at last: 25
1
Enter the number that you want to insert at last: 10
1
Enter the number that you want to insert at last: 5
1
Enter the number that you want to insert at last: 15
1
Enter the number that you want to insert at last: 2
3
25 -> 10 -> 5 -> 15 -> 2 -> NULL
2
INFO : Sorting successfull
3
2 -> 5 -> 10 -> 15 -> 25 -> NULL
4(exit)

*/


#include "sll.h"

int main()
{

	int option, data, key;


	Slist *head = NULL; //initialize the header to NULL

	printf("1. Insert at last\n2. Sort list\n3. Print list\n4. Exit\nEnter your choice : ");
	while (1)
	{

		/* ask user options */
		scanf("%d", &option);

		switch (option)
		{
			case 1:
				printf("Enter the number that you want to insert at last: ");
				scanf("%d", &data);

				/* insert_at_last function call */
				if (insert_at_last(&head, data) == FAILURE) 
				{
					printf("INFO : Insert last failed\n");
				}
				break;
			case 2:
				/* Function to sort the link */
				if (sl_sort(&head) == LIST_EMPTY)
				{
					printf("INFO : List is empty\n");
				}
				else
				{
					printf("INFO : Sorting successfull\n");
				}
				break;

			case 3:
				/* print list function call*/
				print_list(head);
				break;

            case 4:
                 return SUCCESS;
                 
			default: printf("Enter proper choice !!\n");
					 break;
		}

	}

	return SUCCESS;
}