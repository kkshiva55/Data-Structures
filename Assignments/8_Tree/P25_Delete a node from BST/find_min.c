#include "tree.h"

int findmin(Tree_t * root)
{
    if (root == NULL)              // Checking if tree is empty
    {
        return FAILURE;
    }

    Tree_t *temp = root;

    while (temp->left != NULL)        // Traversing to the left most node
    {
        temp = temp->left;
    }

    return temp->data;               // Return minimum value of the tree
}
