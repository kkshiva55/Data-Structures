#include "main.h"

data_t insertion(data_t *arr, data_t size)
{
    data_t i, j, key;

    for (i = 1; i < size; i++)
    {
        key = arr[i];             // Store present index value as key element
        j = i - 1;

        while ((j >= 0) && (arr[j] > key))      // True if key element is smaller than the array value
        {
            arr[j + 1] = arr[j];                // Swapping the elements
            j = j - 1;
        }

        arr[j + 1] = key; 
    }

    return 0;  
}
