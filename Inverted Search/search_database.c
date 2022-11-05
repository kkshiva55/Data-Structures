#include "inverted_search.h"

void search(Wlist *head, char *word)
{
    int flag = 1;
    if (head == NULL)
    {
        printf("List is empty\n");
    }

    else
    {
        // Traversing through the list
        while (head)
        {
            // Comparing the word with the words in the list
            if (!(strcmp(head->word, word)))
            {
                flag = 0;
                printf("%s is found at %d file/s \n", word, head->file_count);
                
                Ltable *Thead = head->Tlink;
                while (Thead)
                {
                    printf("In a file : %s %d time/s\n", Thead->file_name, Thead->word_count);
                    Thead = Thead->table_link;
                }
                printf("\n");
            }
            
          head = head->link;

        }
 
    }

    if (flag == 1)    // True if word is not found
    {
        printf("%s is not found in the list\n", word);
    }
}