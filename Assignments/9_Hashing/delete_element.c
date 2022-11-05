#include"hash.h"

int delete_element(hash_t *arr, int data, int size)
{
    int ind = data % size;

    if (arr[ind].value == -1)            // If there is no element at the index
    {
        return DATA_NOT_FOUND;
    }

    if ((arr[ind].value == data) && (arr[ind].link == NULL))     // True if there is only one element at the value block
    {
        arr[ind].value = -1;
        return SUCCESS;
    }

    hash_t *temp1 = arr[ind].link;
    hash_t *temp2 = temp1->link;

    if (arr[ind].value == data)            // If there are multiple nodes and the value block data is to deleted
    {
        arr[ind].value = temp1->value;     // Replace value block with the first node data
        arr[ind].link = temp2;
        free(temp1);                       // Delete the first node 
        return SUCCESS;
    }

    /* First node is to deleted */

    if (temp1->value == data)
    {
        arr[ind].link = temp2;
        free(temp1);
        return SUCCESS;
    }

    /* Deleting node if the node is neither first node nor last node */

    while (temp2->link != NULL)
    {
        if (temp2->value == data)
        {
            temp1->link = temp2->link;
            free(temp2);
            return SUCCESS;
        }
    }

    /* Last node is to deleted */

    if (temp2->value == data)
    {
        temp1->link = NULL;
        free(temp2);
        return SUCCESS;
    }

    return DATA_NOT_FOUND;
}