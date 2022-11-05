#include "sll.h"

int sl_insert_before(Slist **head, data_t g_data, data_t ndata)
{
    if (*head == NULL)     // Checking if list is empty
    {
        return LIST_EMPTY;
    }
    Slist *temp = *head;
    Slist *new = malloc(sizeof(Slist));    // Creating a new node to insert before
    Slist *prev;
    new->data = ndata;
    new->link = NULL;
    
    if (new == NULL)   // Error checking
    {
        return FAILURE;
    }

        if (temp->data == g_data)    // If insertion is before the first node
        {
            new->link = *head;
            *head = new;
            return SUCCESS;
        }

    while (temp != NULL)     // Traversing through the list
    {
        if (temp->data != g_data)    // Comparing the data 
        {
            prev = temp;
            temp = temp->link;
        }
        else
        {
            prev->link = new;     // If data is found, update the link
            new->link = temp;
            return SUCCESS;
        }
    }
    return DATA_NOT_FOUND;
}