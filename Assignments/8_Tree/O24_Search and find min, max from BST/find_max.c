#include "tree.h"

int findmax(Tree_t * root)
{
    if (root == NULL)              // Checking if tree is empty
    {
        return FAILURE;
    }

    Tree_t *temp = root;

    while (temp->right != NULL)        // Traversing to the right most node
    {
        temp = temp->right;
    }

    return temp->data;            // Returning maximum value in the tree
}
