#include "sll.h"
/* Function to get the nth node from the last of a linked list*/
int find_nth_last(Slist *head, int pos, int *data) 
{ 
    if (head == NULL)        // Checking if list is empty
    {
        return LIST_EMPTY;
    }

    if (pos < 1)
    {
        return FAILURE;    
    }

    Slist *temp1 = head;
    Slist *temp2 = head;

    for (int i = 1; i < pos; i++)          // Traversing one pointer upto position times 
    {
        if (temp2->link == NULL)       // Position ranges from the '1' to 'number of nodes'
        {
            return FAILURE;
        }

        temp2 = temp2->link;
    }

    while (temp2->link != NULL)      // Traverse til second pointer reaches last node
    {
        temp1 = temp1->link;
        temp2 = temp2->link;
    }

    return temp1->data;    // Return the first pointer's data
    
}