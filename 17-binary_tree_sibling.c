#include "binary_trees.h"

/**
 * binary_tree_sibling - Find the sibling of a node.
 * @node: A pointer to the node to to find the sibling
 * Return: If node has a sibling - A pointer to the sibling node
 *	   Otherwise - NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
