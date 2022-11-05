/* Array is sorted in the main function before calling the binary search function */

#include "main.h"

/* Function for binary search using iterations */
data_t binarySearch_iterative(data_t *arr, data_t size, data_t key)
{
    data_t low = 0, high = size - 1, mid;


    while (low <= high)  
    {
        mid = (low + high) / 2;

        if (arr[mid] == key)         // True if key is matched 
        {
            return mid;              // Return the position of the key 
        }
        else if (key < arr[mid])     // If array element is greater than key
        {
            high = mid - 1;          // Move high before the mid value
        }
        else
        {
            low = mid + 1;           // Move low after the mid value
        }
    }

   return DATA_NOT_FOUND;            // Return DATA NOT FOUND

}
