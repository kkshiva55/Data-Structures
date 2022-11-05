#include "main.h"

void swap(int *x, int *y)       // Function definition for swapping using call by reference
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

data_t selection(data_t *arr, data_t size )
{
    data_t current_min, current_item, j;

    for (j = 0; j < size - 1; j++)  
    {
        current_min = j;              // Present index is stored as current minimum

        for (current_item = j + 1; current_item < size; current_item++)
        {
            if (arr[current_item] < arr[current_min])      // True if Current minimum value is greater than the Current item value
            {
                current_min = current_item;                // Assign Current minimum as Current item
            }
        }

       if (current_min != j)                      // True if Current minimum value is not equal to j value
       {
           swap(&arr[j], &arr[current_min]);      // Swap the j value and the Current minimum value
       }
    } 

  return 0;

}
