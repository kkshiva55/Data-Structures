#include"hash.h"

int insert_HT(hash_t *arr, int element, int size)
{
    int ind = element % size;           // Calculating the index value

    if (arr[ind].value == -1)           // If already there is no value
    {
        arr[ind].value = element;       // Store the element by replacing '-1'
        return SUCCESS;
    }

    hash_t *new = malloc(sizeof(hash_t));       // Create a new node
    
    if (new == NULL)       // Error checking
    {
        return FAILURE;
    }

    new->value = element;           // Update the new node values
    new->link = NULL;
    new->index = ind;

    if (arr[ind].link == NULL)       // If link block is NULL
    {
        arr[ind].link = new;          // Update with new node address
        return SUCCESS; 
    }

    hash_t *temp = arr[ind].link;    

    while (temp->link != NULL)          // Traverse upto the last node
    {
        temp = temp->link;
    }

    temp->link = new;            // Place the element at the last

    return SUCCESS;
}