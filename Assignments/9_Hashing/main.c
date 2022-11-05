/*

Name: Shiva.K
Date: 16-10-2022
Description: Hashing

Sample output: -->

emertxe@ubuntu:~/ECEP/DS/27_hashing$ make
cc    -c -o create_HT.o create_HT.c
cc    -c -o display_HT.o display_HT.c
cc    -c -o insert_HT.o insert_HT.c
cc    -c -o main.o main.c
cc    -c -o delete_HT.o delete_HT.c
cc    -c -o search_HT.o search_HT.c
cc    -c -o delete_element.o delete_element.c
gcc -o out.exe create_HT.o display_HT.o insert_HT.o main.o delete_HT.o search_HT.o delete_element.o

emertxe@ubuntu:~/ECEP/DS/27_hashing$ ./out.exe
Enter the size of arr: 5
1. Insert data in HT
2. Search data in HT
3. Delete data from HT
4. Destroy HT
5. Display HT
6. Exit
Enter you choice : 1
Enter the data: 1
1
Enter the data: 2
1
Enter the data: 3
1
Enter the data: 4
1
Enter the data: 5
1
Enter the data: 6
1
Enter the data: 7
1
Enter the data: 8
5
[0] - 5
[1] - 1 -> 6
[2] - 2 -> 7
[3] - 3 -> 8
[4] - 4
2
Enter the data: 5
INFO : 5 is found at the index 0
2
Enter the data: 4
INFO : 4 is found at the index 4
3
Enter the data: 3
INFO : 3 is deleted successfully
3
Enter the data: 4
INFO : 4 is deleted successfully
5
[0] - 5
[1] - 1 -> 6
[2] - 2 -> 7
[3] - 8
[4] - -1
4
INFO: Hashtable deleted successfully
5
[0] - -1
[1] - -1
[2] - -1
[3] - -1
[4] - -1
6(exit)

*/



#include"hash.h" 

int main()
{
	int size, data, choice, index;
	char opt;
	printf("Enter the size of arr: ");
	scanf("%d", &size);
	hash_t arr[size];
	create_HT(arr, size);
	
	printf("1. Insert data in HT\n2. Search data in HT\n3. Delete data from HT\n4. Destroy HT\n5. Display HT\n6. Exit\nEnter you choice : ");
	while(1)
	{
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the data: ");
				scanf("%d", &data);
				if(insert_HT(arr, data, size) == FAILURE)
				{
					printf("INFO : Insert data is Failure\n");
				}
				
				break;

			case 2:
				printf("Enter the data: ");
				scanf("%d", &data);
				if((search_HT(arr, data, size)) == DATA_NOT_FOUND)
				{
					printf("INFO : Data not found\n");
				}
				else
				{
					printf("INFO : %d is found at the index %d\n", data, data % size);
				}
				break;

			case 3:
				printf("Enter the data: ");
				scanf("%d", &data);
				if(delete_element(arr, data, size) == DATA_NOT_FOUND)
				{
					printf("INFO : Data is not found\n");
				}
				else
				{
					printf("INFO : %d is deleted successfully\n",data);
				}
				break;

			case 4:
				if(destroy_HT(arr,size) == SUCCESS)
				{
					printf("INFO: Hashtable deleted successfully\n");
				}
				else
				{
					printf("INFO: Delete hashtable is Failure\n");
				}
				break;

			case 5:
				display_HT(arr, size);
				break;
			case 6:
				return SUCCESS;

			default:
				printf("Invalid input\n");
		}
	}
}