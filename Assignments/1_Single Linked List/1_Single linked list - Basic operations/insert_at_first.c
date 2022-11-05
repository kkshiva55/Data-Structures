#include "sll.h"

int insert_at_first(Slist **head, data_t data)
{
    Slist *new = malloc(sizeof(Slist));   // Creating a new node
      
       if(new == NULL)   // Error checking for newly created node
       {
          return FAILURE;
       }
    new->data = data;     // Linking the node and storing the data
    new->link = *head;
    *head = new;

   return SUCCESS;
}