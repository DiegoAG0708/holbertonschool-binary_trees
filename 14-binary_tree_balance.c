#include "binary_trees.h"

/**
* h_nodes - Measures binary tree height in nodes (leaf = 1)
* @tree: Pointer to the root node of the tree to measure
*
* Return: Height in nodes, or 0 if tree is NULL
*/
static size_t h_nodes(const binary_tree_t *tree)
{
size_t lh;
size_t rh;

if (tree == NULL)
return (0);

/* leaf node height in nodes = 1 */
if (tree->left == NULL && tree->right == NULL)
return (1);

lh = h_nodes(tree->left);
rh = h_nodes(tree->right);

return ((lh > rh ? lh : rh) + 1);
}

/**
* binary_tree_balance - Measures the balance factor of a binary tree
* @tree: Pointer to the root node of the tree to measure
*
* Return: Balance factor (left height - right height), or 0 if tree is NULL
*/
int binary_tree_balance(const binary_tree_t *tree)
{
int lh;
int rh;

if (tree == NULL)
return (0);

lh = (int)h_nodes(tree->left);
rh = (int)h_nodes(tree->right);

return (lh - rh);
}
