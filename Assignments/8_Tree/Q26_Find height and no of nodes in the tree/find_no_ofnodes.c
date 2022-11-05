#include "tree.h"

int total_nodes(Tree_t *root)
{
    static int nodes;

    if (root != NULL)
    {
        total_nodes(root->left);        // Counting number of nodes by Inorder traversal
        nodes++;
        total_nodes(root->right);
    }

   return nodes;

}
