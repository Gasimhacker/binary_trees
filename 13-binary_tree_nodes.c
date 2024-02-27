#include "binary_trees.h"

/**
 * binary_tree_nodes - Count the nodes with at least 1 child in a binary tree
 *
 * @tree: Pointer to the node to start from
 *
 * Return: The number of nodes with at least 1 child
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
