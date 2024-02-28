#include "binary_trees.h"

/**
 * binary_tree_uncle - Find the uncle of a node.
 * @node: A pointer to the node to to find the uncle
 * Return: If node has an uncle - A pointer to the uncle node
 *	   Otherwise - NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grand_father;

	if (!node || !node->parent || !node->parent->parent)
		return (NULL);
	grand_father = node->parent->parent;
	if (grand_father->left == node->parent)
		return (grand_father->right);
	return (grand_father->left);
}
