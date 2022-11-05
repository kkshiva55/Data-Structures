#include "dll.h"

int dl_insert_before(Dlist **head, Dlist **tail, int gdata, int ndata)
{
    if (*head == NULL)     // Checking if list is empty
    {
        return LIST_EMPTY;
    }

    Dlist *temp = *head;

    while (temp != NULL)    
    {
        if (temp->data == gdata)             // Comapring with the given data
        {
            Dlist *new = malloc(sizeof(Dlist));         // Memory allocation for new node
 
            if (new == NULL)          // Error checking
            {
                return FAILURE;
            }

            new->data = ndata;       // Updating given data into the new node
            new->next = temp;

            if (temp != *head)      
            {
                new->prev = temp->prev;
                temp->prev->next = new;
            }
            else                  // Inserting in the first node
            {
                *head = new;
                 new->prev = NULL;
            }

            temp->prev = new;

            return SUCCESS;
        }
        else
        {
            temp = temp->next;     // Traversing until the data is matched
        }
    }

    return DATA_NOT_FOUND;
}