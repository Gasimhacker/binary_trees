#include "binary_trees.h"

/**
 * depth - Measures the depth of a binary tree
 *
 * @tree: Pointer to the node to measures the depth
 *
 * Return: The depth of the tree starting at @tree
 */
size_t depth(const binary_tree_t *tree)
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

/**
 * binary_trees_ancestor - Find the lowest common ancestor of two nodes
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 *
 * Return: A pointer to the lowest common ancestor
 *	   If no common ancestor was found return NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	int depth_f = depth(first), depth_s = depth(second);

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	while (first && depth_f > depth_s)
	{
		first = first->parent;
		depth_f--;
	}
	while (second && depth_s > depth_f)
	{
		second = second->parent;
		depth_s--;
	}

	if (first == NULL || second == NULL || first == second)
		return (binary_trees_ancestor(first, second));
	return (binary_trees_ancestor(first->parent, second->parent));
}
