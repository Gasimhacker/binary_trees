#include "binary_trees.h"

/**
 * binary_tree_leaves - Count the leaves in a binary tree
 *
 * @tree: Pointer to the node to measures the leaves of it
 *
 * Return: The leaves of the tree starting at @tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
