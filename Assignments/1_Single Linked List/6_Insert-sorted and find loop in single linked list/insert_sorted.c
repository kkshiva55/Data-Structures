#include "sll.h"

/* Function for insert the number in sorted linked list */
int insert_sorted( Slist **head, data_t data) 
{ 
    Slist *new = malloc(sizeof(Slist));        // Allocate memory for new node

    if (new == NULL)      // Error checking
    {
        return FAILURE;
    }

    new->data = data;
    new->link = NULL;
   
    if (*head == NULL)            // If List is empty
    {
        *head = new;
        return SUCCESS;
    }

    Slist *temp = *head;

    if ((*head)->data > data)     // Inserting the new node before the first node
    {
        new->link = temp;
        *head = new;
        return SUCCESS;
    }

   Slist *prev;

    while (temp->link != NULL)    // Inserting the new node before the node
    {
        if (data < temp->data)  
        {
            prev->link = new;
            new->link = temp;
            return SUCCESS;
        }

      prev = temp;
      temp = temp->link;

    }

    if (data < temp->data)        // If data is less than the last node data
    {
        prev->link = new;
        new->link = temp;
        return SUCCESS;
    }
    else                         // If data is greater than the last node data
    {
        temp->link = new;
        return SUCCESS;
    }
 
    
} 