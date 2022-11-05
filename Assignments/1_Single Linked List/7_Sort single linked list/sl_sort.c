#include "sll.h"

int sl_sort(Slist **head)
{
    int check = 1;
    
    if (*head == NULL)      // Checking if list is empty
    {
        return LIST_EMPTY;
    }
    
    if ((*head)->link == NULL)           // For Single node, return SUCCESS
    {
        return SUCCESS;
    }

    
    while (check != 0)          // Loop will be executed until all the elements has been sorted
    {
        Slist *prev = NULL, *present = *head, *next = present->link;
        check = 0;
        
        while (next != NULL)            // Traversing next pointer upto the last node
        {
            if (next->data < present->data)
            {
                if (prev != NULL)     // Swapping the nodes
                {
                    Slist *temp = next->link;
                    prev->link = next;
                    next->link = present;
                    present->link = temp;
                }
                else             // Swapping in case of last node
                {
                    
                    Slist *temp = next->link;
                    *head = next;
                    next->link = present;
                    present->link = temp;
                }
                
                prev = next;
                next = present->link;      // Traversing upto the last node

                check = 1;
            }
            else
            {
                
                prev = present;
                present = next;
                next = next->link;
            }
        }
    }

  return  SUCCESS;

}