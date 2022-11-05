#include "main.h"

/* Function to sort the array in quick sort method */
int quick_sort( int *arr, int first, int last )
{
    int index;

    if (first < last)
    {
        index = partition(arr, first, last);      // Partition function returns 'q' value
        quick_sort(arr, first, index - 1);        // Recursively calling the function
        quick_sort(arr, index + 1, last);
    } 

  return 0;  
}
