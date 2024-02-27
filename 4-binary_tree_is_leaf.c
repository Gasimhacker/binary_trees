#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Check if a node is a leaf.
 *			 If node is NULL, do nothing.
 * @node: A pointer to the node to check
 * Return: 1 - If node is a leaf
 *	   0 - otherwise
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left || node->right)
		return (0);
	return (1);
}
