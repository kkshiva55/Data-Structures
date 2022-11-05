#include "dll.h"

int dl_delete_element(Dlist **head, Dlist **tail, int data)
{	
    if (*head == NULL)     // Checking if list is empty
    {
        return LIST_EMPTY;
    }

    Dlist *temp = *head;

    while (temp != NULL)
    {
        if (temp->data == data)      // Comapring with the given data
        {
            Dlist *del = temp;

            if (*head == *tail)    // Deletion in case of single node
            {
                free(del);
                *head = NULL;
                *tail = NULL;
            }
            else if(temp == *tail)     // Deletion in case of last node
            {
                *tail = temp->prev;
                temp->prev->next = NULL;
                free(del);
            }
            else if (temp == *head)     // Deletion of first node
            {
                *head = temp->next;
                temp->next->prev = NULL;
                free(del);
            }
            else    
            {
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                free(del);
            }

            return SUCCESS;
        }

        temp = temp->next;     // Traversing through the last node
    }

    return DATA_NOT_FOUND;
}