#include "sll.h"

int sl_insert_after(Slist **head, data_t g_data, data_t ndata)
{
    if (*head == NULL)    // Checking if list is empty
    {
        return LIST_EMPTY;
    }
    
    Slist *temp = *head;    // Assigning temp pointer for traversing through the list

        while (temp != NULL)
        {
            if (temp->data != g_data)   // Comparing the given data in the list
            {
                temp = temp->link;
            }
            else
            {
                Slist *new = malloc(sizeof(Slist));    // Creating a new node to insert after the matched data

                   if (new == NULL)   // Error checking
                   {
                      return FAILURE;
                   }
                   new->data = ndata;         // Assigning the data and establishing the link
                   new->link = temp->link;
                   temp->link = new;

                   return SUCCESS;
            }
        }
    return DATA_NOT_FOUND;
}