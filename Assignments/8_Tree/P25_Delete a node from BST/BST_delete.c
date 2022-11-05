#include "tree.h"

extern int status;
/* Function to delete the node  */
Tree_t * delete_BST(Tree_t * root, int data)
{
    if (root == NULL)
    {
        return root;
    }

    else if (data < root->data)                         // Search for the data on the left side
    {
        root->left = delete_BST(root->left, data);
    }

    else if (data > root->data)
    {
        root->right = delete_BST(root->right, data);    // Search for the data on the right side
    }

    else       // Given data is found
    {
        if ((root->left == NULL) && (root->right == NULL))    // Deleting the node with no child
        {
            free(root);
            root = NULL;
            status = 1;
        }
        else if (root->left == NULL)                          // Deleting the node with one child on the right
        {
            Tree_t *temp = root;
            root = root->right;
            free(temp);
            status = 1;
        }
        else if (root->right == NULL)                         // Deleting the node with one child on the left
        {
            Tree_t *temp = root;
            root = root->left;
            free(temp);
            status = 1;
        }
        else                                                   // Deleting the node with two children
        {
            int min = findmin(root->right);
            root->data = min;
            root->right = delete_BST(root->right, min);        // Update the node with minimum value which is present below the given data (Inorder Successor)
        }
    }

    return root;
}