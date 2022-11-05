#include "dll.h"

int dl_delete_last(Dlist **head, Dlist **tail)
{
    if (*head == NULL)     // Checking if list is empty
    {
        return FAILURE;
    }

    Dlist *temp = *tail;

    if ((*head)->next == NULL)     // Delete at last in case of single node
    {
        free(temp);
        *head = NULL;
        *tail = NULL;
        return SUCCESS;
    }

    *tail = (*tail)->prev;      // Delete at last in case of multiple node
    (*tail)->next = NULL;
    free(temp);

    return SUCCESS;

}