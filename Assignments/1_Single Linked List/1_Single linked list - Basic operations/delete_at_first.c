#include "sll.h"

int sl_delete_first(Slist **head)
{
    if (*head == NULL)     // Checking if list is empty
    {
        return LIST_EMPTY;
    }
    Slist *temp = *head;    // Deleting node at first
    *head = temp->link;
    free(temp);
    
  return SUCCESS;
}