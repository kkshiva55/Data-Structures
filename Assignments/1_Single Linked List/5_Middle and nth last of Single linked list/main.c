/*

Name: Shiva.K
Date: 03-10-2022
Description: Find middle element and nth last element from Single Linked List

Sample output: -->

emertxe@ubuntu:~/ECEP/DS/5_sll$ make
cc    -c -o get_nth_last.o get_nth_last.c
cc    -c -o print_list.o print_list.c
cc    -c -o find_mid.o find_mid.c
cc    -c -o insert_at_last.o insert_at_last.c
cc    -c -o main.o main.c
gcc -o out.exe get_nth_last.o print_list.o find_mid.o insert_at_last.o main.o

emertxe@ubuntu:~/ECEP/DS/5_sll$ ./out.exe
1. Insert at last
2. Find Mid
3. Find Nth last
4. Print list 
5. Exit
Enter the Option : 1
Enter the number that you want to insert at last: 1
1
Enter the number that you want to insert at last: 2
1
Enter the number that you want to insert at last: 3
1
Enter the number that you want to insert at last: 4
2
Middle element is 3
1
Enter the number that you want to insert at last: 5
2
Middle element is 3
4
1 -> 2 -> 3 -> 4 -> 5 -> NULL
3
Enter the Number to find the last : 2
2th last is 4
5 (exit)

*/


#include "sll.h"

int main()
{
	char check_char;
	int option, data, pos, key;


	Slist *head = NULL; //initialize the header to NULL


	printf("1. Insert at last\n2. Find Mid\n3. Find Nth last\n4. Print list \n5. Exit\nEnter the Option : ");
	while (1)
	{

		/*ask user options*/
		scanf("%d", &option);

		switch (option)
		{
			case 1:
				printf("Enter the number that you want to insert at last: ");
				scanf("%d", &data);

				/*insert_at_last function call*/
				if (insert_at_last(&head, data) == FAILURE) //pass by reference
				{
					printf("INFO : Insert last failed\n");
				}
				break;

			case 2:{
					   int mid;
					   if ((mid = find_mid(head, &mid)) == LIST_EMPTY)
					   {
						   printf("INFO : List is empty\n");
					   }
					   else 
					   {
						   printf("Middle element is %d\n", mid);
					   }
				   }
				   break;
			case 3:
				   printf("Enter the Number to find the last : ");
				   scanf("%d", &pos);
				   if ((key = find_nth_last(head, pos, &data)) == FAILURE)
				   {
					   printf("INFO : Position not found\n");
				   }
				   else if (key == LIST_EMPTY)
				   {
				        printf("INFO : List is empty");
				   }
				   else 
				   {
					   printf("%dth last is %d\n", pos, key);
				   }
				   break;
			case 4:
				   /* print list function call*/
				   print_list(head);
				   break;
			case 5:
				   return SUCCESS;
			default:
				   printf("Invalid Option\n");
		}


	}

	return SUCCESS;
}