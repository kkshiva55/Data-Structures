/* Array is sorted before calling the binary search function */

#include "main.h"

/* Function to search the element using binary search */
data_t binarySearch_recursive(data_t *arr, data_t size, data_t key, data_t first, data_t last)
{
    data_t mid = (first + last) / 2;

    if (first <= last)
    {
        if (arr[mid] == key)       // True if key is matched
        {
            return mid;
        }
        
        if (key < arr[mid])       // If key is less than the array element
        {
            last = mid - 1;       // Store the last value before the mid
        }
        else
        {
            first = mid + 1;      // Store the first value after the mid
        }

     return binarySearch_recursive(arr, size, key, first, last);         // Calling the function Recursively

    }

  return DATA_NOT_FOUND;       // Return DATA NOT FOUND
    
}