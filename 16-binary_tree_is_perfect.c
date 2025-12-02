#include "binary_trees.h"

/**
* bt_height - Measures height in edges (leaf = 0)
* @tree: Pointer to the root node of the tree to measure
*
* Return: Height in edges, or 0 if tree is NULL
*/
static size_t bt_height(const binary_tree_t *tree)
{
size_t lh;
size_t rh;

if (tree == NULL)
return (0);

if (tree->left == NULL && tree->right == NULL)
return (0);

lh = bt_height(tree->left);
rh = bt_height(tree->right);

return ((lh > rh ? lh : rh)+1);
}

/**
* is_perfect - Recursively checks if a tree is perfect
* @tree: Pointer to current node
*
* Return: 1 if perfect, 0 otherwise
*/
static int is_perfect(const binary_tree_t *tree)
{
size_t lh;
size_t rh;

if (tree == NULL)
return (1); /* empty subtree is considered perfect structurally */

if (tree->left == NULL && tree->right == NULL)
return (1);

if (tree->left == NULL || tree->right == NULL)
return (0);

lh = bt_height(tree->left);
rh = bt_height(tree->right);

if (lh != rh)
return (0);

return (is_perfect(tree->left) && is_perfect(tree->right));
}

/**
* binary_tree_is_perfect - Checks if a binary tree is perfect
* @tree: Pointer to the root node of the tree to check
*
* Return: 1 if perfect, 0 otherwise; if tree is NULL, return 0
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

return (is_perfect(tree));
}
