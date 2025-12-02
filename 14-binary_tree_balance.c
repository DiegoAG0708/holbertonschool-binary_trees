#include "binary_trees.h"

/**
* bt_height - Measures the height of a binary tree (internal helper)
* @tree: Pointer to the root node of the tree to measure
*
* Return: Height of the tree, or 0 if tree is NULL
*/
static size_t bt_height(const binary_tree_t *tree)
{
size_t left_height;
size_t right_height;

if (tree == NULL)
return (0);

if (tree->left == NULL && tree->right == NULL)
return (0);

left_height = bt_height(tree->left);
right_height = bt_height(tree->right);

if (left_height > right_height)
return (left_height + 1);
return (right_height + 1);
}

/**
* binary_tree_balance - Measures the balance factor of a binary tree
* @tree: Pointer to the root node of the tree to measure
*
* Return: Balance factor, or 0 if tree is NULL
*/
int binary_tree_balance(const binary_tree_t *tree)
{
int left_height;
int right_height;

if (tree == NULL)
return (0);

left_height = (int)bt_height(tree->left);
right_height = (int)bt_height(tree->right);

return (left_height - right_height);
}
