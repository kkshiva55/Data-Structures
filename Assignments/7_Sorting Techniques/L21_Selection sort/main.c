/*

Name: Shiva.K
Date: 08-10-2022
Description: Selection Sort 

Sample output: -->

emertxe@ubuntu:~/ECEP/DS/21_selection$ make
cc    -c -o main.o main.c
cc    -c -o selection.o selection.c
gcc -o out.exe main.o selection.o


emertxe@ubuntu:~/ECEP/DS/21_selection$ ./out.exe
Enter the size of an array
5
Enter the array elements
25 10 5 15 26
Sorted array is : 5 10 15 25 26

*/


#include "main.h"

/* Main Function */
int main()
{
	int i, limit, option;

	/* Scanning the size */
	printf("Enter the size of an array\n");
	scanf("%d", &limit);

	/* Declaring the array with size */
	data_t arr[limit];

		
	printf("Enter the array elements\n");
	for (i = 0; i < limit; i++)
	{
	    /* Scanning the array elements */
		scanf("%d", &arr[i]);
	}
		
	/* Calling the function to bubble sort */
	selection(arr, limit);
	
	printf("Sorted array is : ");
	for (i = 0; i < limit; i++)
	{
	    printf("%d ", arr[i]);
	}
		
	return 0;
}
