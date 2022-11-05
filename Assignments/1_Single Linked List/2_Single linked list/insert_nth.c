#include "sll.h"

int sl_insert_nth(Slist **head, data_t data, data_t n)
{
    Slist *new = malloc(sizeof(Slist));   // Creating a new node

       if (new == NULL)
       {
          return FAILURE;
       }
        new->data = data;    // Updating the data in the new node
        new->link = NULL;
        Slist *temp = *head;
    
   if (*head == NULL)    // Checking if list is empty
   {
       
       if (n == 1)    // If nth position is '1' in case of empty list
       {
          *head = new;
          new->link = temp;
          return SUCCESS;
       }
       else
       {
           free(new);            // Free the memory for newly created node if the list is empty and nth value is not equal to '1'
           return LIST_EMPTY;
       }
     
   }
       
       if (n == 1)    // If nth position is '1' in case of non-empty list
       {
          *head = new;
          new->link = temp;
          return SUCCESS;
       }

    Slist *prev;

           for (int pos = 1; pos <= n; pos++)   // Traversing towards position
           {
               if (pos == n)    // Inserting the node at given position
               {
                 new->link = temp;
                 prev->link = new;
                 return SUCCESS;            
               }
               else if ((temp == NULL) && (pos == n))   // Insert after the last node
               {
                  temp->link = new;
                  return SUCCESS;
               }
               else if (temp == NULL)    // Invalid position
               {
                  return POSITION_NOT_FOUND;
               }

             prev = temp;         // Updating present and previous node links
             temp = temp->link;
           }
       

}