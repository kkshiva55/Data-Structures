#include "sll.h"
/* Function to get the middle of the linked list*/
int find_mid(Slist *head, int *mid) 
{ 
    if (head == NULL)      // Checking if list is empty
    {
        return LIST_EMPTY;
    }

    Slist *temp1 = head;    // Assigning two pointers 
    Slist *temp2 = head;

    while ((temp2 != NULL) && (temp2->link != NULL))
    {
        temp2 = temp2->link->link;     // One pointer is traversing one node 
        temp1 = temp1->link;          // while the other pointer is traversing two node 
    }

    return temp1->data;    // Return the middle element
} 
