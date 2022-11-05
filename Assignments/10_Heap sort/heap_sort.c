#include "main.h"

/* Function to sort the array using heap sort */
int heap_sort(int *heap, int size )
{
    build_maxheap(heap, size);
    int index = size - 1;

    while (index >= 0)
    {
        swap(&heap[0], &heap[index]);
        max_heapify(heap, 0, index);     // Getting the highest element at the root
        index--;
    }
}  

