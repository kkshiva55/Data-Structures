#include "sll.h"

int reverse_recursive(Slist **head)
{
    if (*head == NULL)          // Checking if list is empty
    {
        return LIST_EMPTY;
    }

    static Slist *curr, *next;
    static Slist *prev = NULL;
   
    curr = *head;
    next = curr->link;        // Updating previous, current and next pointer values to traverse till the end 
    curr->link = prev;
    prev = curr;
    curr = next;
 
    if (curr != NULL)          // Recursively call unti current pointer reaches last node
    {
        reverse_recursive(&curr);
    }

    *head = prev;        // Changing head value as last node address
   return SUCCESS;
}