#include "main.h"

void swap(int *x, int *y)       // Function definition for swapping using call by reference
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


/* Function to partition the array */
int partition(int *arr, int first, int last)
{
    int pivot = first, p = first, q = last;       // Declaring required variables

    while (p < q)
    {
        while(arr[p] <= arr[pivot])       // True if first element 'p' is less than or equal to the pivot element
        {
            p++;
        }

        while (arr[q] > arr[pivot])       // True if last element 'q' is greater than the pivot element
        {
            q--;
        }

        if (p < q)                         // True if first index value is less than last index value
        {
            swap(&arr[p], &arr[q]);        // Swap first and last index array values
        }
    } 

  swap(&arr[first], &arr[q]);            // Swap Pivot and last index array values

  return q;
  
}

