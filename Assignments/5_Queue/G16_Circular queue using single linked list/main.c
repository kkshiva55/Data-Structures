/*

Name: Shiva.K
Date: 07-10-2022
Description: Circular Queue implementation using Single Linked List

Sample output: -->

emertxe@ubuntu:~/ECEP/DS/16_queue$ make
cc    -c -o print_queue.o print_queue.c
cc    -c -o enqueue.o enqueue.c
cc    -c -o main.o main.c
cc    -c -o dequeue.o dequeue.c
gcc -o out.exe print_queue.o enqueue.o main.o dequeue.o

emertxe@ubuntu:~/ECEP/DS/16_queue$ ./out.exe
1. Enqueue
2. Dequeue
3. Print Queue
4. Exit
Enter the option : 2
INFO : Queue is empty
3
INFO : Queue is Empty
1
Enter the element you want to insert : 1
1
Enter the element you want to insert : 2
1
Enter the element you want to insert : 3
3
Front -> 1 -> 2 -> 3 <- Rear
2
INFO : Dequeue successfull
3
Front -> 2 -> 3 <- Rear
2
INFO : Dequeue successfull
3
Front -> 3 <- Rear
2
INFO : Dequeue successfull
3
INFO : Queue is Empty
4(exit)

*/


#include "queue.h"

int main()
{
	Queue_t *front = NULL, *rear = NULL;

	int choice, data;

	printf("1. Enqueue\n2. Dequeue\n3. Print Queue\n4. Exit\nEnter the option : ");

	while (1)
	{
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				/* Function to Enqueue the Queue */
				printf("Enter the element you want to insert : ");
				scanf("%d", &data);
				if (enqueue(&front, &rear, data) == FAILURE)
				{
					printf("INFO : Queue full\n");
				}
				break;
			case 2:
				/* Function to dequeueue the queue */
				if (dequeue(&front, &rear) == FAILURE)
				{
					printf("INFO : Queue is empty\n");
				}
				else
				{
					printf("INFO : Dequeue successfull\n");
				}
				break;
			case 3:
				/* Function to print the queue */
				print_queue(front, rear);
				break;
			case 4:
				return SUCCESS;
			default:
				printf("Invalid option !!!\n");
		}

	}
}