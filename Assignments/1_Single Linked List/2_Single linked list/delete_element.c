#include "sll.h"

int sl_delete_element(Slist **head, data_t data)
{
    if (*head == NULL)    // Checking if list is empty
    {
        return LIST_EMPTY;
    }

    Slist *temp = *head;
    Slist *prev, *next;

      if (temp->data == data)    // In case if first node is to be deleted
      {
         *head = temp->link;
         free(temp);
         return SUCCESS; 
      }

        while (temp != NULL)
        {
            if (temp->data != data)    // Comparing the given data with the list
            {
                prev = temp;
                temp = temp->link; 
            }
            else
            {
                next = temp->link;    // Creating a link by excluding the node which contains matched data
                prev->link = next;
                free(temp);           // Deleting the node
                return SUCCESS;
            }
        }
    return DATA_NOT_FOUND;
}