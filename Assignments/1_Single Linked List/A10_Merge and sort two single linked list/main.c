/*

Name: Shiva.K
Date: 10-10-2022
Description: Merge and Sort two Single Linked List

Sample output: -->

emertxe@ubuntu:~/ECEP/DS/10_sll$ make
cc    -c -o print_list.o print_list.c
cc    -c -o insert_at_last.o insert_at_last.c
cc    -c -o sort.o sort.c
cc    -c -o main.o main.c
cc    -c -o sorted_merge.o sorted_merge.c
gcc -o out.exe print_list.o insert_at_last.o sort.o main.o sorted_merge.o

emertxe@ubuntu:~/ECEP/DS/10_sll$ ./out.exe
1. Insert at  List 1
2. Insert at list 2
3. Print list
4. Sorted merge
5. Exit
Enter your choice: 1
Enter the data to be inserted at list 1 : 25
1
Enter the data to be inserted at list 1 : 15
1
Enter the data to be inserted at list 1 : 5
1
Enter the data to be inserted at list 1 : 10
3

List 1 -> 25 -> 15 -> 5 -> 10 -> NULL


List 2 -> INFO : List is empty
4
INFO : Sorted merge Successfull
3
5 -> 10 -> 15 -> 25 -> NULL
2
Enter the data to be inserted at list 2 : 6
2
Enter the data to be inserted at list 2 : 12
2
Enter the data to be inserted at list 2 : 26
2
Enter the data to be inserted at list 2 : 4
3
5 -> 10 -> 15 -> 25 -> NULL
4
INFO : Sorted merge Successfull
3
4 -> 5 -> 6 -> 10 -> 12 -> 15 -> 25 -> 26 -> NULL
5(exit)

*/


#include "sll.h"

int main()
{
	//variable declaration
	Slist *head1 = NULL;
	Slist *head2 = NULL;
	int choice, data, temp = 0;

	printf("1. Insert at  List 1\n2. Insert at list 2\n3. Print list\n4. Sorted merge\n5. Exit\nEnter your choice: ");
	while (1)
	{
		//call function display menu
		scanf("%d", &choice);

		switch (choice)
		{

			//insert element at last
			case 1:
				printf("Enter the data to be inserted at list 1 : ");
				scanf("%d", &data);

				if (insert_at_last(&head1, data) == FAILURE)
					printf("INFO: Failed to Inserting the new data at last..try again\n");
				break;

			case 2:

				printf("Enter the data to be inserted at list 2 : ");
				scanf("%d", &data);

				if (insert_at_last(&head2, data) == FAILURE)
					printf("INFO: Failed to Inserting the new data at last..try again\n");
				break;

			case 3:
				if (temp == 0)
				{
					printf("\nList 1 -> ");
					print_list(head1); // print list_1
					printf("\n\nList 2 -> ");
					print_list(head2); // print list_2
					break;
				}
				else
					print_list(head1);
				break;

			case 4:
			 
				if (sorted_merge(&head1, &head2) == SUCCESS)
				{
				    temp = 1;
                    sort(&head1);   // Function to sort Single linked list
					printf("INFO : Sorted merge Successfull\n");
				}
				else
					printf("INFO : Both list are Empty\n");

				break;

			case 5 :
				return SUCCESS;

			default:
				printf("\nEnter the proper choice\n");

		}

	}

	return 0;
}		
