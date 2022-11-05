#include "main.h"

void merge(int *array, int narray, int *left, int nleft, int *right, int nright)
{
    int i = 0, j = 0, k = 0;

	while ((i < nleft) && (j < nright))
	{
        if (left[i] < right[j])                // Compare left and right sub-array values
		{
            array[k++] = left[i++];            // If Right sub-array value is greater
        }
		else
		{ 
			array[k++] = right[j++];           // If Left sub-array value is greater
		}
	}
	
	while(j < nright)                         // Copy the remaining sub-array values to the output array
	{
		array[k++] = right[j++];
	}
	
	while(i < nleft)
	{
		array[k++] = left[i++];
	}
}