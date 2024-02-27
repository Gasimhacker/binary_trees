#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a binary tree
 *
 * @tree: Pointer to the node to measures the depth
 *
 * Return: The depth of the tree starting at @tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);
	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}
