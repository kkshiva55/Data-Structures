/*

Name: Shiva.K
Date: 08-10-2022
Description: Bubble Sort

Sample output: -->

emertxe@ubuntu:~/ECEP/DS/19_bubble$ make
cc    -c -o bubble.o bubble.c
cc    -c -o main.o main.c
gcc -o out.exe bubble.o main.o


emertxe@ubuntu:~/ECEP/DS/19_bubble$ ./out.exe
Enter the size of an array
5
Enter the array elements
5 3 25 10 7
Sorted array is : 3 5 7 10 25

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
	bubble(arr, limit);
	
	printf("Sorted array is : ");
	for (i = 0; i < limit; i++)
	{
	    printf("%d ", arr[i]);
	}
		
	return 0;
}
