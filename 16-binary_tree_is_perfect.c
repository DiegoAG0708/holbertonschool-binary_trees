#include "binary_trees.h"

/**
* binary_tree_is_perfect - Checks if a binary tree is perfect
* @tree: Pointer to the root node of the tree to check
*
* Return: 1 if perfect, 0 otherwise
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
size_t left_size;
size_t right_size;

if (tree == NULL)
return (0);

left_size = binary_tree_size(tree->left);
right_size = binary_tree_size(tree->right);

if (left_size == right_size)
{
if (tree->left == NULL && tree->right == NULL)
return (1);
return (binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right));
}
return (0);
}
