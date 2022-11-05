#include "main.h"

/* Function to check the number is minimum or maximum to decide the position */
void max_heapify(int *heap, int i, int size)
{
    int left = (2 * i) + 1;      // Left child
    int right = (2 * i) + 2;     // Right child
    int large;

    if ((heap[i] < heap[left]) && (left < size))     // If left child is greater than the right child
    {
        large = left;
    }
    else
    {
        large = i;
    }

    if ((heap[large] < heap[right]) && (right < size))   // If right child is greater than the left child
    {
        large = right;
    }

    if (i != large)
    {
        swap(&heap[large], &heap[i]);
        max_heapify(heap, large, size);      // Recursively calling the heapify function
    }
}
