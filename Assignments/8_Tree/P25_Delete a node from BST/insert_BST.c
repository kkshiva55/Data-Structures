#include "tree.h"

/* Function to insert the data's in BST */
int insert_into_BST(Tree_t **root, int data)
{
    int flag;
    Tree_t *new = malloc(sizeof(Tree_t));        // Memory allocation for new node

    if (new == NULL)    // Error checking
    {
        return FAILURE;
    }

    new->data = data;
    new->left = NULL;
    new->right = NULL;

    if (*root == NULL)     // If tree is empty
    {
        *root = new;
        return SUCCESS;
    }

    Tree_t *temp = *root;
    Tree_t *parent;

    while (temp != NULL)                // Traversing through the tree
    {
        parent = temp;

        if (data < temp->data)          // If the data is less than the tree data, Store the address of left
        { 
            temp = temp->left;
            flag = 1;
        }
        else if (data > temp->data)     // If the data is more than the tree data, Store the address of right
        {
            temp = temp->right;
            flag = 0;
        }
        else                            // If the entered data is already present in the tree
        {
            return DUPLICATE;
        }
    }

    if (flag == 1)              
    {
        parent->left = new;        // Inserting new node at the left
    }
    else
    {
        parent->right = new;       // Inserting new node at the right
    }

    return SUCCESS;
}