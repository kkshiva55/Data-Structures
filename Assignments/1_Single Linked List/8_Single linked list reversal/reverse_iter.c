#include "sll.h"

/* Function to reverse the given single linked list */
int reverse_iter(Slist **head) 
{ 
    if (*head == NULL)          // Checking if list is empty
    {
        return LIST_EMPTY;
    }

    Slist *prev = NULL;     
    Slist *curr, *next;      // Assigning previous, current and next pointers
    curr = next = *head;

    while (next != NULL)
    {
        next = next->link;       // Updating previous, current and next pointer values to traverse till the end 
        curr->link = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;        // Changing head value as last node address
    
    return SUCCESS;

} 