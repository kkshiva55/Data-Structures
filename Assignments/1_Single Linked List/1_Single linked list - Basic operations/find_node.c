#include "sll.h"

int find_node(Slist *head, data_t data)
{
	if (head == NULL)    // Checking if list is empty
    {
        return FAILURE;
    }
    Slist *temp = head;
    int pos = 1;

        while (temp->link != NULL)     // Traversing through the list and find the node position
        {
                if (temp->data == data)
                {
                    return pos;     // Return node position
                }
            
            pos++;
            temp = temp->link;
        }

        if (temp->data == data)   // Comparing with the data present in the last node
        {
            return pos;
        }
        else
        {
            return FAILURE;
        }
    
}
