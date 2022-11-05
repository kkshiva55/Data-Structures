#include "main.h"

data_t bubble(data_t *arr, int size )
{
    data_t i, j, temp;

    for (i = 0; i < size; i++)  
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])       // Comparing adjacent elements
            {
                temp = arr[j];
                arr[j] = arr[j + 1];       // Swapping numbers if adjacent element is smaller
                arr[j + 1] = temp;
            }

        }

    }

    return 0;  
}