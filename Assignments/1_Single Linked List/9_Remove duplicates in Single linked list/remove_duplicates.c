
#include "sll.h"

//remove duplicate data's from list
int remove_duplicates( Slist **head )
{
    if (*head == NULL)   // Checking if list is empty
    { 
        return FAILURE;
    }
    
    Slist *temp1 = *head;
    Slist *temp2, *del;

    while (temp1 != NULL && temp1->link != NULL)     // Present node link and next node link should not be equal to NULL
    {
        temp2 = temp1;

          while (temp2->link != NULL)               // Traverse temp2 pointer upto the last element
          {
              if (temp1->data == temp2->link->data)     // Checking for duplicate element
              {
                  del = temp2->link;                    // Storing duplicate element address
                  temp2->link = temp2->link->link;      
                  free(del);                           // Deleting duplicate node
              }
              else
              {
                  temp2 = temp2->link;
              }
            
          }
       
      temp1 = temp1->link;      // Traverse temp1 pointer upto second last element

    }

  return SUCCESS;

}