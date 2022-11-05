#include "tree.h"

/* Function to print the data in in order printing */
int inorder(Tree_t *root)
{
    if (root != NULL)
    {
        inorder(root->left);                // Traversing in the order of Left child, Parent and right child
        printf("%d ", root->data);
        inorder(root->right);
    }
}