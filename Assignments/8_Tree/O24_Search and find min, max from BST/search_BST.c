#include "tree.h"

/* Iteratively */
int search_BST(Tree_t * root, int data)
{
    if (root == NULL)
    {
        return FAILURE;
    }

    Tree_t *temp = root;

    while (temp != NULL)                // Traversing upto the last child node
    {
        if (data < temp->data)          // If the data is smaller than the node data, traverse towards the left side
        {
            temp = temp->left;
        }
        else if (data > temp->data)     // If the data is higher than the node data, traverse towards the right side
        {
            temp = temp->right;
        }
        else
        {
            return SUCCESS;            // Data found in the tree
        }
    }

    return NOELEMENT;                  // Data not found in the tree

}