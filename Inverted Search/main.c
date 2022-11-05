#include "inverted_search.h"

int main(int argc, char *argv[])
{
    system("clear");
     int choice;
     char ch;
     Wlist *head[27] = {NULL};
     char word[WORD_SIZE];

    // Validating Command line arguments

    if (argc <= 1)
    {
        printf("Enter the valid no.of.Arguments \n");
        printf("./SList.exe file1.txt file2.txt ..... \n");
        return 0;
    }

    // Creating the file list and Declaring the file head

    Flist *f_head = NULL;

    file_validation_n_file_list(&f_head, argv);

    if (f_head == NULL)
    {
        printf("No files are available in the file\n");
        printf("Hence the process terminated\n");
        return 1;
    }

    // Prompting the user for choice
    do
    {
         printf("\nSelect your choice among following options:\n1. Create Database\n2. Display Database\n3. Update Database\n4. Search\n5. Save Database\nEnter your choice : ");
         scanf("%d", &choice);

         switch(choice)
         {
             case 1 :
                create_database(f_head, head);
                break;

            case 2 :
                display_database(head);
                break;

            case 3 :
                update_database(head, &f_head);
                break;

            case 4 :
                printf("Enter the word to be searched: ");
                scanf("%s", word);

                search(head[tolower(word[0]) % 97], word);
                break;

            case 5 :
                save_database(head);
                break;


             default :
                printf("Enter proper choice.....\n");
                break;

         }

         printf("Do you want to continue ?\n");
         printf("Enter y/Y to continue (or) n/N to exit : ");
         __fpurge(stdin);
         scanf("%c", &ch);
    } while ((ch == 'y') || (ch == 'Y'));

    return SUCCESS;

}

