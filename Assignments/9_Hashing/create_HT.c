#include "hash.h"

void create_HT(hash_t *HT, int size)
{
    for (int i = 0; i < size; i++)
    {
        HT[i].index = i;              // Storing the index values
        HT[i].value = -1;             // Storing '-1' in the value blocks
        HT[i].link = NULL;            // Storing all the links blocks with NULL
    }
}