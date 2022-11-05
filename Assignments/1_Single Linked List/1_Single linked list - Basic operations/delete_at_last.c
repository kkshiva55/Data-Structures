#include "sll.h"

int sl_delete_last(Slist **head)
{
    if (*head == NULL)     // Checking if list is empty
    {
        return LIST_EMPTY;
    }

    else
    {
        Slist *temp = *head;
        if (temp->link == NULL)    // Deleting if only one node is present
        {
            free(temp);
            *head = NULL;
            return SUCCESS;
        }

        else
        {
            while (temp->link->link != NULL)     // Traverse through the list and delete the last node
            {
                temp = temp->link;
            }
           free(temp->link);
           temp->link = NULL;
    
          return SUCCESS;
        }

    }
    
}