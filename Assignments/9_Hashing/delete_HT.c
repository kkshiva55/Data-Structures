#include"hash.h"

int destroy_HT(hash_t *arr, int size)
{
    for (int ind = 0; ind < size; ind++)
    {
        hash_t *temp1 = arr[ind].link;

        if (arr[ind].value != -1)  
        {
            arr[ind].value = -1;          // Replace value block with '-1'
            arr[ind].link = NULL;         // Replace link block with NULL      
        }

        while (temp1 != NULL) 
        {
            hash_t *temp2 = temp1->link;        // Deleting nodes one by one
            free(temp1);
            temp1 = temp2;
        }
    }

   return SUCCESS;

}