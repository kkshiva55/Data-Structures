#include "dll.h"

int dl_delete_first(Dlist **head, Dlist **tail)
{
    if (*head == NULL)   // Checking if list is empty
    {
        return FAILURE;
    }
     
     Dlist *temp = *head;
     
     if (temp->next == NULL)    // Deletion in case of single node
     {
        free(temp);
        *head = NULL;
        *tail = NULL;
        return SUCCESS;
     }

     *head = (*head)->next;    // Deletion in case of multiple nodes
     (*head)->prev = NULL;
     free(temp);

     return SUCCESS;

}