/*

Name: Shiva.K
Date: 28-09-2022
Description: Single Linked List

Sample output: -->

emertxe@ubuntu:~/ECEP/DS/2_sll$ make
cc    -c -o print_list.o print_list.c
cc    -c -o insert_after.o insert_after.c
cc    -c -o insert_before.o insert_before.c
cc    -c -o insert_at_first.o insert_at_first.c
cc    -c -o insert_nth.o insert_nth.c
cc    -c -o main.o main.c
cc    -c -o delete_element.o delete_element.c
gcc -o out.exe print_list.o insert_after.o insert_before.o insert_at_first.o insert_nth.o main.o delete_element.o

emertxe@ubuntu:~/ECEP/DS/2_sll$ ./out.exe
1.Insert at first
2.Insert after
3.Insert before
4.Insert Nth
5.Delete element
6.Print list
7. Exit
Enter any option : 1
Enter the number you have to insert : 3
1
Enter the number you have to insert : 2
1
Enter the number you have to insert : 1
1
Enter the number you have to insert : 0
6
0 -> 1 -> 2 -> 3 -> NULL
2
Enter the value of gdata : 3
Enter the ndata that you want to insert after 3 : 4
6
0 -> 1 -> 2 -> 3 -> 4 -> NULL
3
Enter the value of gdata : 0
Enter the ndata that you want to insert before 0 : -1
6
-1 -> 0 -> 1 -> 2 -> 3 -> 4 -> NULL
4
Enter the node number : 5
Enter the number that you want to insert 5th position : 6
6 is successfully inserted at the position 5
6
-1 -> 0 -> 1 -> 2 -> 6 -> 3 -> 4 -> NULL
5
Enter the element you need to delete : -1
Element Successfully deleted
6
0 -> 1 -> 2 -> 6 -> 3 -> 4 -> NULL
7 (exit)

*/


#include "sll.h"

int main()
{
 
    int option, ndata, gdata, ret, n;


    Slist *head = NULL; //initialize the header to NULL

	printf("1.Insert at first\n2.Insert after\n3.Insert before\n4.Insert Nth\n5.Delete element\n6.Print list\n7. Exit\nEnter any option : ");
    while(1)
    {

	/*ask user options*/

	scanf("%d", &option);

	switch (option)
	{
	    case 1:
		    printf("Enter the number you have to insert : ");
		    scanf("%d", &ndata);
		    if (insert_at_first(&head, ndata) != SUCCESS)
		    {
		       printf("INFO : Insert first failure\n");
	    	}
	
	    	break;
	    case 2:
	    	printf("Enter the value of gdata : ");
	    	scanf("%d", &gdata);
	    	printf("Enter the ndata that you want to insert after %d : ", gdata);
    		scanf("%d", &ndata);
    		/*insert_at_last function call*/
	    	if ((ret = sl_insert_after(&head, gdata, ndata)) == DATA_NOT_FOUND) //pass by reference
	    	{
	    	    printf("INFO : %d is not found at the list\n", gdata);
	    	}
	    	else if (ret == LIST_EMPTY)
	    	{
	    	    printf("INFO : List is empty\n");
	    	}
	
    		break;
	   case 3:
    		printf("Enter the value of gdata : ");
	    	scanf("%d", &gdata);
	    	printf("Enter the ndata that you want to insert before %d : ", gdata);
    		scanf("%d", &ndata);
	    	/*insert_at_last function call*/
    		if ((ret = sl_insert_before(&head, gdata, ndata)) == DATA_NOT_FOUND) //pass by reference
	    	{
	    	    printf("INFO %d is not found at the list\n", gdata);
    		}
	    	else if (ret == LIST_EMPTY)
	    	{
	    	    printf("INFO : List is empty\n");
    		}
	

	    	break;
	    case 4:
	    	printf("Enter the node number : ");
	    	scanf("%d", &n);
		    printf("Enter the number that you want to insert %dth position : ", n);
		    scanf("%d", &ndata);
		    /*insert_at_last function call*/
		    if ((ret = sl_insert_nth(&head, ndata, n)) == POSITION_NOT_FOUND)//pass by reference
		    {
		       printf("INFO : %d Position not found\n", n);
	    	}
	    	else if (ret == LIST_EMPTY)
		    {
		        printf("INFO : List is empty\n");
		    }
		    else
		    {
		        printf("%d is successfully inserted at the position %d\n", ndata, n);
		    }
		    break;
	    case 5:
		    // To delete the element
		    printf("Enter the element you need to delete : ");
		    scanf("%d", &ndata);
		    if ((ret = sl_delete_element(&head, ndata)) == DATA_NOT_FOUND)
		    {
		        printf("INFO : Element is not found\n");
		    }
		    else if (ret == LIST_EMPTY)
		    {
		        printf("INFO : List is empty\n");
		    }
		    else
		    {
		        printf("Element Successfully deleted\n");
		    }
		    break;
	    case 6:
		    print_list(head);
		    break;
        case 7:
            return SUCCESS;
            
	    default: printf("Enter proper choice !!\n");
		     break;
	    }
    }

    return SUCCESS;
}