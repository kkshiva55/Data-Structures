#include "inverted_search.h"

void update_database(Wlist *head[], Flist **f_head)
{
    char file_name[FNAME_SIZE];
    int empty, ret;

    // Prompting the user to enter new file name
    printf("Enter filename to update database: ");
    scanf("%s", file_name);

    // Validating the file and adding into the file linked
    empty = isFileEmpty(file_name);
    if (empty == FILE_NOTAVAILABLE)        // True if file is not available
    {
        printf("File : %s is not available\n", file_name);
        printf("Hence we are not adding into the file list\n");
    }
    
    else if (empty == FILE_EMPTY)           // True if file is empty
    {
        printf("File : %s is not having any contents in it\n", file_name);
        printf("Hence we are not adding into the file list\n");

    }

    else
    {
       ret = to_create_list_of_files(f_head, file_name);    // Adding filename to the file linked list

           /* Duplicate file name is passed */
           if (ret == REPEATATION)
           {
               printf("This file name : %s is repeated, Hence we are not adding to the list\n", file_name);
           }

           else if (ret == FAILURE)
           {
               printf("FAILURE\n");
           }

           else
           {
               printf("Successfull : Inserting the file name : %s into the the file linked list\n", file_name);
               Flist *temp = *f_head;

               while (temp)
               {
                   if (!(strcmp(temp->file_name, file_name)))
                   {
                        create_database(temp, head);     // Updating the database with the new file
                   }

                  temp = temp->link;
               }
           
	          printf("Database has been successfully Updated.....\n");
           
           }
          
    }
}