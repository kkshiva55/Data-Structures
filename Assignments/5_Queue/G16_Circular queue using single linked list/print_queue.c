#include "queue.h"

int print_queue(Queue_t *front, Queue_t *rear)
{
	if (front == NULL)                   // Checking if queue is empty
	{
		printf("INFO : Queue is Empty\n");
		return FAILURE;
	}

	printf("Front -> ");
	while (front)	              // Printing upto the last node 	
	{
		printf("%d ", front -> data);
		front = front -> link;
		if (rear -> link != front)
		{
		    printf("-> ");
		}
		else
		    break;
	}

	printf("<- Rear\n");
	return SUCCESS;
}