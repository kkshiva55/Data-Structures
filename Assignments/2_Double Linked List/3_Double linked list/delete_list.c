#include "dll.h"

int dl_delete_list(Dlist **head, Dlist **tail)
{
    if (*head == NULL)    // Checking if list is empty
    {
        return FAILURE;
    }

     Dlist *temp = *head;

    while (temp->next != NULL)    // Deleting nodes one by one 
    {
        free(temp);
        temp = temp->next;
    }
    
    free(temp);       // Assigning NULL to Head and Tail
    *head = NULL;
    *tail = NULL;

    return SUCCESS;
}