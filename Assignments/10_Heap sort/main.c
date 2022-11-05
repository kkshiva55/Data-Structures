/*

Name: Shiva.K
Date: 16-10-2022
Description: Heap sort -- Max Heapify

Sample output: -->

emertxe@ubuntu:~/ECEP/DS/28_heap$ make
cc    -c -o build_maxheap.o build_maxheap.c
cc    -c -o heap_sort.o heap_sort.c
cc    -c -o main.o main.c
cc    -c -o max_heapify.o max_heapify.c
gcc -o out.exe build_maxheap.o heap_sort.o main.o max_heapify.o


emertxe@ubuntu:~/ECEP/DS/28_heap$ ./out.exe
Enter the size of an array
5
Enter the array elements
15 5 10 25 20
Sorted array is : 5 10 15 20 25

*/


#include "main.h"

void swap(int *x, int *y)       // Function definition for swapping using call by reference
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* Main Function */
int main()
{
	int i, limit;

	/* Scanning the size */
	printf("Enter the size of an array\n");
	scanf("%d", &limit);

	/* Declaring the array with size */
	int heap[limit];

		
	printf("Enter the array elements\n");
	for (i = 0; i < limit; i++)
	{
	    /* Scanning the array elements */
		scanf("%d", &heap[i]);
	}
		

    build_maxheap(heap, limit);
    
	/* Calling the function to bubble sort */
	heap_sort(heap, limit);
	
	printf("Sorted array is : ");
	for (i = 0; i < limit; i++)
	{
	    printf("%d ", heap[i]);
	}
		
	return 0;
}
