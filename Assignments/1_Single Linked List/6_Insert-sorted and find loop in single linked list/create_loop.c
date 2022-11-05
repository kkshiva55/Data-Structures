#include "sll.h"

int create_loop(Slist **head, data_t data)
{
    if (*head == NULL)                  // Checking if list is empty
    {
        return LIST_EMPTY;
    }

    Slist *temp1 = *head;
    Slist *temp2 = NULL;

    while (temp1->link != NULL)         // Traversing 'temp1' pointer upto the last node
    {
        if(temp1->data == data)         // If the data is found, assign that node address to 'temp2' pointer
        {
            temp2 = temp1;
        }

        temp1 = temp1->link;
    }
    
    
    if (temp2 == NULL)               // Data is not found till the last node
    {
        return DATA_NOT_FOUND;
    }
      
    temp1->link = temp2;           // Matched data node address is assigned to last node address (Loop is created)
    return SUCCESS;
}