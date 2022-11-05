#include "inverted_search.h"

void display_database(Wlist *head[])
{
    printf("\n[index]  [word]   file_count file/s    File: file_name   word_count\n");

    for (int i = 0; i < 27; i++)      // Checking for all alphabets
    {
        if (head[i] != NULL)
        {
            print_word_count(head[i]);
        }
    }
}

int print_word_count(Wlist *head)
{
    // Traversing through the Wlist
    while (head != NULL)
    {
        printf(" [%d]   [%s]   %d file/s:     ", tolower(head->word[0]) % 97, head->word, head->file_count);
        Ltable *Thead = head->Tlink;

        // Traversing through the Ltable
        while (Thead)
        {
            printf("  File: %s    %d", Thead->file_name, Thead->word_count);
            Thead = Thead->table_link;
        }
        printf("\n");
        head = head->link;
    }
    
    return SUCCESS;
}