#include "tree.h"

int find_height(Tree_t *root)
{
    if (root == NULL)  
    {
        return SUCCESS;
    }

    else
    { 
        int left_tree = find_height(root->left);           // Find left side depth
        int right_tree = find_height(root->right);         // Find right side depth

        if (left_tree > right_tree)     // If left sub tree has more nodes
        {
            return left_tree + 1;
        }
        else                            // If right sub tree has more nodes
        {
            return right_tree + 1;
        }
    }
}
