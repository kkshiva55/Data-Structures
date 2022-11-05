#include "inverted_search.h"
extern char *fname;

int insert_at_last(Wlist **head, data_t *data)
{
    // Creating the node
    Wlist *new = malloc(sizeof(Wlist));
    if (new == NULL)   // Error checking
    {
        return FAILURE;
    }

    // Updating the node
    new->file_count = 1;
    strcpy(new->word, data);
    new->Tlink = NULL;
    new->link = NULL;

    // Calling the function to update the link table
    update_link_table(&new);

    // Checking if Wlist is empty or not

    if (*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    // If Wlist is non empty
    Wlist *temp = *head;

    // Traversing through the Wlist
    while (temp->link)
    {
        temp = temp->link;
    }
    temp->link = new;
    return SUCCESS;
}

int update_link_table(Wlist **head)
{
    // Creating the node
    Ltable *new = malloc(sizeof(Ltable));
    if (new == NULL)  // Error checking
    {
        return FAILURE;
    }

    // Updating the node
    new->word_count = 1;
    strcpy(new->file_name, fname);
    new->table_link = NULL;

    (*head)->Tlink = new;
    return SUCCESS;

}