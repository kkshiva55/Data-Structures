#include "inverted_search.h"

char *fname;

void create_database(Flist *f_head, Wlist *head[])
{
    // Traversing through the linked list
    while (f_head)
    {
        read_datafile(f_head, head, f_head->file_name);
        printf("Successfull: Creation of database for file : %s\n", f_head->file_name);
        f_head = f_head->link;
    }
}

Wlist * read_datafile(Flist *file, Wlist *head[], char *filename)
{
    // Opening the file
    FILE *fptr = fopen(filename, "r");
    char word[WORD_SIZE];
    fname = filename;
    int flag = 1;

    while ((fscanf(fptr, "%s", word)) != EOF)
    {
        // Index values for alphabets
        int index = tolower(word[0]) % 97;

        // Index values other than alphabets
        if (!((index >= 0) && (index <= 25)))
        {
            index = 26;
        }

        // For Repeated words
        if (head[index] != NULL)
        {
            Wlist *temp = head[index];

            // Comparing the words at each node with new word
            while (temp)
            {
                if (!(strcmp(temp->word, word)))
                {
                    update_word_count(&temp, filename);
                    flag = 0;
                    break;
                }
             temp = temp->link;
            }
            
        }

        if ((flag == 1) || (head[index] == NULL))
        {
            // For non-Repeated words
            insert_at_last(&head[index], word);
        }

    }

  return SUCCESS;

}

int update_word_count(Wlist **head, char * file_name)
{
    Ltable *temp = (*head)->Tlink;

    while (temp->table_link != NULL)
    {
        if ((strcmp(temp->file_name, file_name)) == 0)    // Checking for duplicate file name
        {
             (temp->word_count)++;    // Increment word count
             return SUCCESS;
        }
      temp = temp->table_link;
    }

    if ((strcmp(temp->file_name, file_name)) == 0)    // Checking for filename in the last node of the Ltable
    {
        (temp->word_count)++;
        return SUCCESS;
    }

    Ltable *new = malloc(sizeof(Ltable));   // Creating a Ltable node
    if (new == NULL)     // Error checking
    {
        return FAILURE;
    }
    
    // Updating new Ltable node
    new->word_count = 1;
    strcpy(new->file_name, file_name);
    new->table_link = NULL;

    temp->table_link = new;
    ((*head)->file_count)++;       // Incrementing the file count
    return SUCCESS;
}