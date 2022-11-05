/*

Name: Shiva.K
Date: 11-10-2022
Description: Binary Search using Recursion

Sample output: -->

emertxe@ubuntu:~/ECEP/DS/18_bsearch$ make
cc    -c -o main.o main.c
cc    -c -o BS_recursive.o BS_recursive.c
gcc -o out.exe main.o BS_recursive.o


emertxe@ubuntu:~/ECEP/DS/18_bsearch$ ./out.exe
Enter the size of an array
5
Enter the elements of an array
10 12 15 17 25
Enter the key to search
25
INFO : Key found at the position 4


emertxe@ubuntu:~/ECEP/DS/18_bsearch$ ./out.exe
Enter the size of an array
3
Enter the elements of an array
1 2 3
Enter the key to search
5
INFO : Key not found

*/


#include "main.h"


data_t bubble(data_t *arr, int size)      // Sorting the array before proceeding for the binary search
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

    /* Function call for Sorting the array elements */
    bubble(arr, size);

    printf("Enter the key to search\n");
	scanf("%d", &key);

	/* Calling the function to search the element */
	if ((res = binarySearch_recursive(arr, size, key, 0, size - 1)) == DATA_NOT_FOUND)
	{
	    printf("INFO : Key not found\n");
	}
	else
	{	
	    printf("INFO : Key found at the position %d\n", res);
	}
	
    return 0;
}
