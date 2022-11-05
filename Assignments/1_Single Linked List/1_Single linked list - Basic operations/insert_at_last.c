#include "sll.h"

int insert_at_last(Slist **head, data_t data)
{
      Slist *new = malloc(sizeof(Slist));     // Creating a new node
       
       if(new == NULL)    // Error checking for newly created node
       {
          return FAILURE;
       }
    new->data = data;
    new->link = NULL;
    
       if(*head == NULL)    // Inserting when list is empty
       {
          *head = new;
          return SUCCESS;  
       }
       
       // If list is non-empty

    Slist *temp = *head; 
     
      while(temp->link != NULL)
      {
        temp = temp->link;
      } 
      temp->link = new;
      
  return SUCCESS;   
}