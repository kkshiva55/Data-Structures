#include "sll.h"

int sl_delete_list(Slist **head)
{
    if (*head == NULL)      // Checking if list is empty
    {
        return LIST_EMPTY;
    }
	Slist *temp = *head;
      
         while (temp->link != NULL)    // Deleting nodes one by one
         {
            free(temp);
            temp = temp->link;
         }
         free(temp);      // Deleting the last node
         *head = NULL;

    return SUCCESS;
}