#include "inverted_search.h"

void save_database(Wlist *head[])
{
    char file_name[FNAME_SIZE];

    printf("Enter the filename: ");
    scanf("%s", file_name);

    FILE *fptr = fopen(file_name, "w");    // Opening the file in write mode  

    for (int i = 0; i < 27; i++)       // Checking for all the alphabets and special characters
    {
        if (head[i] != NULL)
        {
            write_databasefile(head[i], fptr);
        }
    }
    
    fclose(fptr);      // Closing the file

    printf("Database has been successfully saved to %s\n", file_name);
}

void write_databasefile(Wlist *head, FILE* databasefile)
{
    int index = (tolower(*(head->word))) % 97;     // Finding the index value
     
    fprintf(databasefile, "#[%d]\n", index);     // Storing index value in the output file

     while (head != NULL)
     {
        fprintf(databasefile, "\nWord is [%s]: File count is %d \n    <----- In File/s: ----->\n", head->word, head->file_count);
        Ltable *Thead = head->Tlink;

        // Traversing through the Ltable
        while (Thead)
        {
            fprintf(databasefile, "File is %s: Word count is %d\n", Thead->file_name, Thead->word_count);
            Thead = Thead->table_link;
        }
        
        head = head->link;
    }
    fprintf(databasefile, "---------------------------------------\n\n");
    
}