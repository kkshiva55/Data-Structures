#include "sll.h"

int sorted_merge( Slist **head1, Slist **head2)
{
    if ((*head1 == NULL) && (*head2 == NULL))     // True if both list is empty
    {
        return LIST_EMPTY;
    }

    else if (*head1 == NULL)    // True if list 1 is empty
    {
        *head1 = *head2;        // Update head 1 as head 2 
        *head2 = NULL;
    }

    else
    {
        Slist *temp = *head1;

       while (temp->link != NULL)     // Traverse upto the last node of the list 1
       {
           temp = temp->link;
       }

       temp->link = *head2;          // Update last node of list 1 with head 2
       *head2 = NULL;

    }

    /* Sort function is called in the main function (case 4) */

   return SUCCESS;

}