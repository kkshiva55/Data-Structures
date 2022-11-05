#include "main.h"

void build_maxheap(int *heap, int size)
{
    int index = (size / 2) - 1;

    while (index >= 0)
    {
        max_heapify(heap, index, size);     // Finding the highest element at the root
        index--;
    }

}