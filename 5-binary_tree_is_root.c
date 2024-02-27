#include "binary_trees.h"

/**
 * binary_tree_is_root - Check if a node is a root.
 *			 If node is NULL, do nothing.
 * @node: A pointer to the node to check
 * Return: 1 - If node is a root
 *	   0 - otherwise
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent)
		return (0);
	return (1);
}
