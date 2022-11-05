/*

Name: Shiva.K
Date: 13-10-2022
Description: Search the given data and Find the Maximum and Minimum from the Binary Search Tree

Sample output: -->

emertxe@ubuntu:~/ECEP/DS/24_Tree$ make
cc    -c -o postorder.o postorder.c
cc    -c -o search_BST.o search_BST.c
cc    -c -o inorder.o inorder.c
cc    -c -o find_min.o find_min.c
cc    -c -o main.o main.c
cc    -c -o insert_BST.o insert_BST.c
cc    -c -o find_max.o find_max.c
cc    -c -o preorder.o preorder.c
gcc -o out.exe postorder.o search_BST.o inorder.o find_min.o main.o insert_BST.o find_max.o preorder.o

emertxe@ubuntu:~/ECEP/DS/24_Tree$ ./out.exe
1. insert BST
2. in order Traversal
3. pre order Traversal
4. post order Traversal
5. BST Search
6. Find minimum
7. Find maximum
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
10 7 6 5 9 12 11 14 13 16 
4
5 6 9 7 11 13 16 14 12 10 
5
Enter the element to be searched: 12
INFO : Data found
5
Enter the element to be searched: 30
INFO : Data not found
6
INFO : Minimum value in the tree is 5
7 
INFO : Maximum value in the tree is 16
8(exit)

*/


#include "tree.h"

int main()
{
	/* Intializing the root with NULL */
	Tree_t *root = NULL;
	int result;
	/* Declaring the variables */
	int option, data;

	printf("1. insert BST\n2. in order Traversal\n3. pre order Traversal\n4. post order Traversal\n5. BST Search\n6. Find minimum\n7. Find maximum\n");
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
				/* Function to Printing the data in pre-order form */
				preorder(root);
				printf("\n");
				break;
			case 4:
				/* Function to Printing the data in post-order form */
				postorder(root);
				printf("\n");
				break;
			
			case 5:
				printf("Enter the element to be searched: ");
				scanf("%d", &data);
				result = search_BST(root, data);
				if (result == NOELEMENT)
				{
					printf("INFO : Data not found\n");
				}
				else if (result == FAILURE)
				{
				    printf("INFO : Tree is empty\n");
				}
				else
				{
					printf("INFO : Data found\n");
				}

				break;
			case 6: 
				result = findmin(root);
				if (result == FAILURE)
				{
					printf("INFO : Tree is empty\n");
				}
				else
				{
				    printf("INFO : Minimum value in the tree is %d\n", result);	
				}
				break;
			case 7: 
				result = findmax(root);
				if (result == FAILURE)
				{
					printf("INFO : Tree is empty\n");
				}
				else
				{
				    printf("INFO : Maximum value in the tree is %d\n", result);	
				}	
				break;
			case 8:
			    return SUCCESS;
			
			default:
				printf("Invalid Option\n");
		}

		/* If user press y means loop will continue */
	}
	return 0;
}