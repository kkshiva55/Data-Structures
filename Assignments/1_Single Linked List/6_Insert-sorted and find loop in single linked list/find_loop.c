#include "sll.h"

/* Function for finding the loop in the link */
int find_loop(Slist *head)
{
    if (head == NULL)             // Checking if list is empty
    {
        return LIST_EMPTY;
    }

    Slist *slow = head;
    Slist *fast = head;

    while ((slow != NULL) && (fast != NULL) && (fast->link != NULL))
    {
        slow = slow->link;             // Slow pointer traverse one node
        fast = fast->link->link;       // Fast pointer traverse two nodes

        if (slow == fast)              // If slow and fast pointers meets in a same node
        {
            return SUCCESS;            // LOOP FOUND
        }
    }

  return LOOP_NOT_FOUND;

}