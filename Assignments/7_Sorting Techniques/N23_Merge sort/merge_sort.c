#include "main.h"

int merge_sort(int *array, int narray)
{
    if (narray == 1)             // Divide sub-arrays upto the array of size '1'
	{	
		return SUCCESS;
	}
	
	int nleft = narray / 2;         // Size of left sub-array

	int *left = (int *)malloc (sizeof(int) * nleft);      // Allocate memory for left sub-array
	if(left == NULL)     // Error checking
	{
		return FAILURE;
	}

	int *right = (int *)malloc (sizeof(int) * (narray - nleft));     // Allocate memory for right sub-array
	if(right == NULL)    // Error checking
	{
		return FAILURE;
	}

	for (int i = 0; i < nleft; i++)            // Store the values to left sub-array
	{
		left[i] = array[i];
	}

	for (int i = nleft; i < narray; i++)       // Store the values to right sub-array
	{
		right[i - nleft] = array[i];
	}

	merge_sort(left, nleft);                                        // Recurvisely call the function to divide sub-arrays
	merge_sort(right, narray - nleft);
	merge(array, narray, left, nleft, right, narray - nleft);       // Function call to conquer the sub-arrays

	free(left);                                                     // Freeing the memory allocated for sub-arrays
	free(right); 
}