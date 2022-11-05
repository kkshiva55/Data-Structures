#include "dll.h"

int dl_insert_after(Dlist **head, Dlist **tail, int gdata, int ndata)
{
    if (*head == NULL)          // Checking if list is empty
    {
        return LIST_EMPTY;
    }

    Dlist *temp = *head;

    while (temp != NULL)
    {
        if (temp->data != gdata)       // Comparing with the given data
        {
            temp = temp->next;      // Traversing until the data is matched
        }
        else
        {
            Dlist *new = malloc(sizeof(Dlist));      // Memory allocation for new node
           
            if (new == NULL)              // Error checking
            {
                return FAILURE;
            }

            new->data = ndata;          // Updating data and links 
            new->next = temp->next;
            new->prev = temp;

            if (temp != *tail)      
            {
                temp->next->prev = new;
            }
            else                // Inserting as last node
            {
                *tail = new;
                new->next = NULL;
            }
            
            temp->next = new;
        
        return SUCCESS;

        }
    }

    return DATA_NOT_FOUND;

}