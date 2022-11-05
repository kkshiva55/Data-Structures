/*

Name: Shiva.K
Date: 13-10-2022
Description: Delete a node from Binary Search Tree

Sample output: -->

emertxe@ubuntu:~/ECEP/DS/25_Tree$ make
cc    -c -o BST_delete.o BST_delete.c
cc    -c -o inorder.o inorder.c
cc    -c -o find_min.o find_min.c
cc    -c -o main.o main.c
cc    -c -o insert_BST.o insert_BST.c
gcc -o out.exe BST_delete.o inorder.o find_min.o main.o insert_BST.o

emertxe@ubuntu:~/ECEP/DS/25_Tree$ ./out.exe
1. insert BST
2. in order Traversal
3.BST Delete
4.Exit
Enter the option: 1
Enter the data to insert into the BST : 10
1
Enter the data to insert into the BST : 7
1
Enter the data to insert into the BST : 12
1
Enter the data to insert into the BST : 14
1
Enter the data to insert into the BST : 11
1
Enter the data to insert into the BST : 16
1
Enter the data to insert into the BST : 13
1
Enter the data to insert into the BST : 9
1
Enter the data to insert into the BST : 6
1
Enter the data to insert into the BST : 5
2
5 6 7 9 10 11 12 13 14 16 
3
Enter the data to be deleted: 5
INFO : Element deleted successfully
2
6 7 9 10 11 12 13 14 16 
3
Enter the data to be deleted: 9
INFO : Element deleted successfully
2
6 7 10 11 12 13 14 16 
2
6 7 10 11 12 13 14 16 
3
Enter the data to be deleted: 7
INFO : Element deleted successfully
2
6 10 11 12 13 14 16 
3
Enter the data to be deleted: 12
INFO : Element deleted successfully
2
6 10 11 13 14 16 
4(exit)


*/


#include "tree.h"

int status;

int main()
{
	/* Intializing the root with NULL */
	Tree_t *root = NULL;
	int result;
	/* Declaring the variables */
	int option, data;

	printf("1. insert BST\n2. in order Traversal\n3.BST Delete\n4.Exit\n");
	printf("Enter the option: ");
	while (1)
	{
		scanf("%d", &option);

		switch(option)
		{
			case 1:
				/* Reading the data from the user */
				printf("Enter the data to insert into the BST : ");
				scanf("%d", &data);

				/* Calling the function to insert the element */
				if ((result = insert_into_BST(&root, data)) == DUPLICATE)
				{
					printf("INFO : Duplicate found\n");
				}
				else if (result == FAILURE)
				{
					printf("INFO : Node not created\n");
				}
				break;
			case 2:
				/* Function to Printing the data in in-order form */
				inorder(root);
				printf("\n");
				break;

			case 3:
				/* Function to delete the data from the tree */
				printf("Enter the data to be deleted: ");
				scanf("%d", &data);
				if (root)
				{
			        root = delete_BST(root, data);
			        if (status)
			            printf("INFO : Element deleted successfully\n");
			        else
			            printf("INFO : Element not found\n");
				}
				else
				    printf("INFO : Tree is empty\n");
			            
				break;
			case 4:
				
			    return SUCCESS;
				break;
			
			default:
				printf("Invalid Option\n");
		}

		/* If user press y means loop will continue */
	}
	return 0;
}