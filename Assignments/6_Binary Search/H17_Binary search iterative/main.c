/*

Name: Shiva.K
Date: 11-10-2022
Description: Binary Search using Iterative Method

Sample output: -->

emertxe@ubuntu:~/ECEP/DS/17_bsearch$ make
cc    -c -o BS_iterative.o BS_iterative.c
cc    -c -o main.o main.c
gcc -o out.exe BS_iterative.o main.o


emertxe@ubuntu:~/ECEP/DS/17_bsearch$ ./out.exe
Enter the size of an array
4
Enter the elements of an array
11 12 13 14   
Enter the key to search
12
INFO : Key found at the position 1


emertxe@ubuntu:~/ECEP/DS/17_bsearch$ ./out.exe
Enter the size of an array
3
Enter the elements of an array
1 2 3
Enter the key to search
4
INFO : Key not found

*/


#include "main.h"


data_t bubble(data_t *arr, int size)        // Sorting the array before proceeding for the binary search
{
    data_t i, j, temp;

    for (i = 0; i < size; i++)  
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])       // Comparing adjacent elements
            {
                temp = arr[j];
                arr[j] = arr[j + 1];       // Swapping numbers if adjacent element is smaller
                arr[j + 1] = temp;
            }

        }

    }

    return 0;  
}

/* Main Function */
int main()
{

    /* Declaring the variables */
    data_t option, res, key, size;
    
    /* Reading the number of elements from the user */
    printf("Enter the size of an array\n");
    scanf("%d", &size);
    
    data_t arr[size];
    /* Getting the elements for binary search */
    printf("Enter the elements of an array\n");
    for (int i = 0; i < size; i++)
    {
	    scanf("%d", &arr[i]);
    }

    printf("Enter the key to search\n");
	scanf("%d", &key);

    /* Sorting the array elements */
    bubble(arr, size);

	/* Calling the function to search the element */
	if ((res = binarySearch_iterative(arr, size, key)) == DATA_NOT_FOUND)
	{
	    printf("INFO : Key not found\n");
	}
	else
	{	
	    printf("INFO : Key found at the position %d\n", res);
	}
	
    return 0;
}
