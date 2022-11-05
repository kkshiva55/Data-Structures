#include"hash.h"

int search_HT(hash_t *arr, int data, int size)
{
    int index = data % size;

    if (arr[index].value == data)          // Checking for the element in the value block
    {
        return SUCCESS;
    }

    hash_t *temp = arr[index].link;        // If one index contains multiple values

    while (temp != NULL)
    {
        if (temp->value == data)         // Checking for the element in the linked list
        {
            return SUCCESS;
        }

        temp = temp->link;
    }

    return DATA_NOT_FOUND;            // Element not found
}