/*

Name: Shiva.K
Date: 10-10-2022
Description: Merge Sort

Sample output: -->

emertxe@ubuntu:~/ECEP/DS/23_merge$ make
cc    -c -o merge.o merge.c
cc    -c -o merge_sort.o merge_sort.c
cc    -c -o main.o main.c
gcc -o out.exe merge.o merge_sort.o main.o

emertxe@ubuntu:~/ECEP/DS/23_merge$ ./out.exe
Enter the size of an array
5
Enter the array elements
25 5 10 26 15
Sorted array is : 5 10 15 25 26

*/


#include "main.h"

/* Main Function */
int main()
{
	int i, limit;

	/* Scanning the size */
	printf("Enter the size of an array\n");
	scanf("%d", &limit);

	/* Declaring the array with size */
	int arr[limit];

		
	printf("Enter the array elements\n");
	for (i = 0; i < limit; i++)
	{
	    /* Scanning the array elements */
		scanf("%d", &arr[i]);
	}
		
	/* Calling the function to bubble sort */
	merge_sort(arr, limit);
	
	printf("Sorted array is : ");
	for (i = 0; i < limit; i++)
	{
	    printf("%d ", arr[i]);
	}
		
	return 0;
}
