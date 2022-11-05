#include "inverted_search.h"

void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i = 1, empty, ret_val;

    while (argv[i] != NULL)
    {
        empty = isFileEmpty(argv[i]);
        if (empty == FILE_NOTAVAILABLE)        // True if file is not available
        {
            printf("File : %s is not available\n",argv[i]);
            printf("Hence we are not adding into the file list\n");
            i++;
            continue;
        }

        else if (empty == FILE_EMPTY)           // True if file is empty
        {
            printf("File : %s is not having any contents in it\n",argv[i]);
            printf("Hence we are not adding into the file list\n");
            i++;
            continue;  
        }

        else
        {
           ret_val = to_create_list_of_files(f_head, argv[i]);

           /* File name successfully added at the last of the linked list */
           if (ret_val == SUCCESS)
           {
               printf("Successfull : Inserting the file name : %s into the the file linked list\n", argv[i]);
           }

           /* Duplicate file name is passed in CLA */
           else if (ret_val == REPEATATION)
           {
               printf("This file name : %s is repeated, Hence we are not adding to the list\n", argv[i]);
           }

           else
           {
               printf("FAILURE\n");
           }
           
        }
      i++;
    }
}

// Checking for file availability and for it's contents

int isFileEmpty(char *filename)
{
    FILE *fptr = fopen(filename, "r");

    if (fptr == NULL)           // If file name is not available          
    {
        if (errno == ENOENT)
        {
            return FILE_NOTAVAILABLE;
        }
    }

    fseek(fptr, 0, SEEK_END);

    if (ftell(fptr) == 0)            // If the file is empty
    {
        return FILE_EMPTY;
    }
}

int to_create_list_of_files(Flist **f_head, char *name)
{
    Flist *new = malloc(sizeof(Flist));    // Creating a new node
    if (new == NULL)  // Error checking
    {
        return FAILURE;
    }
    
    strcpy(new->file_name, name);    // Update the node values
    new->link = NULL; 

    if (*f_head == NULL)    // If list is empty
    {
        *f_head = new;
        return SUCCESS; 
    }

    Flist *temp = *f_head;
    while (temp->link)
    {
        if ((strcmp(temp->file_name, name)) == 0)     // Checking for duplicate file name
        {
            free(new);               // Delete the node if there is duplicate file name in the CLA
            return REPEATATION;
        }
     temp = temp->link;
    }

    if ((strcmp(temp->file_name, name)) == 0)     // Checking the last node for duplicate file name
    {
        free(new);
        return REPEATATION;
    }

    temp->link = new;               // Insert the new node at the last

    return SUCCESS;
}  
